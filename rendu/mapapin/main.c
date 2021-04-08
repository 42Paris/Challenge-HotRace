/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <mapapin@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:59:31 by user42            #+#    #+#             */
/*   Updated: 2021/04/07 22:59:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

//------------------------TREE GESTION--------------------------------//

void	right_rotate(t_node ** root, t_node* node)
{
    t_node *l = node->left;

    node->left = l->right;
    if (l->right)
        l->right->parent = node;
    l->parent = node->parent;
    if (!node->parent)
        (*root) = l;
    else if (node == node->parent->left)
        node->parent->left = l;
    else
        node->parent->right = l;
    l->right = node;
    node->parent = l;
}

void	left_rotate(t_node ** root, t_node *node)
{
    t_node	*r = node->right;

    node->right = r->left;
    if (r->left)
        r->left->parent = node;
    r->parent = node->parent;	
    if (!node->parent)
        (*root) = r;
    else if (node == node->parent->left)
        node->parent->left = r;
    else
        node->parent->right = r;
    r->left = node;
    node->parent = r;
}

int		insert_tree(t_node ** root, t_node * tmp)
{
	if (!(*root))
	{
		(*root) = tmp;
		return 0;
	}
	t_node * x = (*root);
	t_node * y = NULL;
	int c;
	while (x)
	{
		y = x;
		c = strcmp(tmp->key, x->key);
		if (c < 0)
			x = x->left;
		else if (c > 0)
			x = x->right;
		else
			return 1;
	}
	tmp->parent = y;
	c = strcmp(tmp->key, y->key);
	if (c < 0)
		y->left = tmp;
	else if (c > 0)
		y->right = tmp;
	return 0;
}

void	balanced_tree(t_node ** root, t_node * node)
{
	while ((node != *(root)) && (node->color != 0) && (node->parent->color == 1))
	{
		if (node->parent == node->parent->parent->left)
		{
			t_node	*u = node->parent->parent->right;
			if (u != NULL && u->color == 1)
			{
				node->parent->color = 0;
				u->color = 0;
				node->parent->parent->color = 1;
				node = node->parent->parent;
			}
			else
			{
				if (node == node->parent->right)
				{
					node = node->parent;
					left_rotate(&(*root), node);
				}
				node->parent->color = 0;
				node->parent->parent->color = 1;
				right_rotate(&(*root), node->parent->parent);
			}
		}
		else
		{
			t_node * u = node->parent->parent->left;
			if (u != NULL && u->color == 1)
			{
				node->parent->color = 0;
				u->color = 0;
				node->parent->parent->color = 1;
				node = node->parent->parent;
			}
			else
			{
				if (node == node->parent->left)
				{
					node = node->parent;
					right_rotate(&(*root), node);
				}
				node->parent->color = 0;
				node->parent->parent->color = 1;
				left_rotate(&(*root), node->parent->parent);

			}
		}
	}
	(*root)->color = 0;
}

t_node * tree_minimum(t_node * x)
{
	while (x->left)
		x = x->left;
	return (x);
}	

void	rb_delete_fixup(t_node ** root, t_node * x)
{
	while (x != (*root) && x->color == 0)
	{
		if (x == x->parent->left)
		{
			t_node * w = x->parent->right;
			if (w->color == 1)
			{
				w->color = 0;
				x->parent->color = 1;
				left_rotate(&(*root), x->parent);
				w = x->parent->right;
			}
			if ((!w->left || w->left->color == 0) && (!w->right || w->right->color == 0))
			{
				w->color = 1;
				x = x->parent;
				return ;
			}
			else if (!w->right || w->right->color == 0)
			{
				w->left->color = 0;
				w->color = 1;
				right_rotate(&(*root), w);
				w = x->parent->right;
			}
			w->color = x->parent->color;
			x->parent->color = 0;
			w->right->color = 0;
			left_rotate(&(*root), x->parent);
			x = (*root);
		}
		else
		{
			t_node * w = x->parent->left;
			if (w->color == 1)
			{
				w->color = 0;
				x->parent->color = 1;
				right_rotate(&(*root), x->parent);
				w = x->parent->left;
			}
			if ((!w->right || w->right->color == 0) && (!w->left || w->left->color == 0))
			{
				w->color = 1;
				x = x->parent;
				return ;
			}
			else if (!w->left || w->left->color == 0)
			{
				w->right->color = 0;
				w->color = 1;
				left_rotate(&(*root), w);
				w = x->parent->left;
			}
			w->color = x->parent->color;
			x->parent->color = 0;
			w->left->color = 0;
			right_rotate(&(*root), x->parent);
			x = (*root);
		}
	}
	if (x)
		x->color = 0;
}

void	rb_transplant(t_node ** root, t_node * u, t_node * v)
{
	if (!u->parent)
		(*root) = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v)
		v->parent = u->parent;
}

static t_node secure = {.color = 0, .key = NULL, .value = NULL, .right = NULL, .left = NULL, .parent = NULL};

static t_node *set_secure(t_node *z, t_node *secure)
{
    t_node *x;

    x = z->right;
    if (!x)
    {
        x = secure;
        x->parent = z;
        x->left = NULL;
        x->right = NULL;
		x->color = 0;
        z->right = x;
    }
    return (x);
}

void	delete_key_tree(t_node ** root, t_node * node)
{
	t_node * y = node;
	t_node * x = NULL;
	int	y_base_color = y->color;

	if (!node->left)
		rb_transplant(&(*root), node, (x = set_secure(node, &secure)));
	else if (!node->right)
	{
		x = node->left;
		rb_transplant(&(*root), node, node->left);
	}
	else
	{
		y = tree_minimum(node->right);
		y_base_color = y->color;
		x = set_secure(y, &secure);
		if (y->parent == node)
			x->parent = y;
		else
		{
			rb_transplant(&(*root), y, y->right);
			y->right = node->right;
			y->right->parent = y;
		}
		rb_transplant(&(*root), node, y);
		y->left = node->left;
		y->left->parent = y;
		y->color = node->color;
	}
	if (y_base_color == 0)
		rb_delete_fixup(&(*root), x);

	if (!(x = x->parent))
		(*root) = NULL;
	else if (x->left == &secure)
		x->left = NULL;
	else
		x->right = NULL;
}

void	delete_tree(t_node *tree)
{
	if (tree)
	{
		delete_tree(tree->left);
		delete_tree(tree->right);
		free(tree->key);
		free(tree->value);
		free(tree);
	}
}

void	delete_node(t_node * node)
{
	if (node)
	{
		free(node->key);
		free(node->value);
		free(node);
	}
}

t_node	*create_node(char *key, char *value)
{
	t_node *tmp = malloc(sizeof(t_node));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = NULL;
	tmp->key = strdup(key);
	tmp->value = strdup(value);
	tmp->color = 1;
	return (tmp);
}

t_node	*search_tree(t_node **tree, char *key)
{
	if (!(*tree))
		return NULL;
	int c = strcmp(key, (*tree)->key);
	if (c < 0)
		return (search_tree(&(*tree)->left, key));
	else if (c > 0)
		return (search_tree(&(*tree)->right, key));
	else
		return (*tree);
}

void	print_node(t_node *node)
{
	if (node)
		puts(node->value);
}

void	print_tree(t_node *tree)
{
	if (tree)
	{
		printf("[%s | %s] ", tree->key, tree->value);
		print_tree(tree->left);
		print_tree(tree->right);
	}
}

//--------------------------------------------------------------------//


//---------------------------HASH GESTION-----------------------------//

void	init_hash_table()
{
	int	i = 0;

	while (i < TABLE_SIZE)
		hash_table[i++] = NULL;
}

int		hash(char * key)
{
	int	g = 29;
	unsigned int hash = 0;
	int	i = 0;

	while (key[i])
	{
		hash = g * hash + (int)key[i];
		i++;
	}
	return (hash % TABLE_SIZE);
}

void	print_table()
{
	printf("START\n");
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hash_table[i] == NULL)
			printf("\t%d\t---\n", i);
		else
		{
			printf("\t%d\t", i);
			print_tree(hash_table[i]);
			printf("\n");
		}
	}
	printf("END\n");
}

void	insert_table(char *key, char *value)
{
	int idx = hash(key);
	int r;
	t_node *new = create_node(key, value);
	if (hash_table[idx] == NULL)
	{
		t_node *tree = NULL;
		r = insert_tree(&tree, new);
		hash_table[idx] = tree;
		if (r == 0)
			balanced_tree(&hash_table[idx], new);
		else
			delete_node(new);
	}
	else
	{
		r = insert_tree(&hash_table[idx], new);
		if (r == 0)
			balanced_tree(&hash_table[idx], new);
		else
			delete_node(new);
	}
}

t_node	*search_table(char *key)
{
	int idx = hash(key);
	if (hash_table[idx] == NULL)
		return NULL;
	else
		return (search_tree(&hash_table[idx], key));
}

void	delete_hashtable()
{
	int i = 0;

	while (i < TABLE_SIZE)
	{
		if (hash_table[i] != NULL)
		{
			delete_tree(hash_table[i]);
			hash_table[i] = NULL;
		}
		i++;
	}
}


//--------------------------------------------------------------------//

int	check_char(char *str, char c)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int main(void)
{
	//---------------------------GETLINE-------------------------------//

	char * line = NULL;
	int	read;
	size_t size = 0;
	char *before;
	char *after;
	char *search = "=";
	char *end = "\0";

	while ((read = getline(&line, &size, stdin)) != -1)
	{
		line[read - 1] = '\0';
		if (line[0] == '!')
		{
			t_node * tmp = search_table(line + 1);
			if (tmp)
				delete_key_tree(&hash_table[hash(line + 1)], tmp);
		}
		else if (check_char(line, '='))
		{
			before = strtok(line, search);
			after = strtok(NULL, end);
			t_node * tmp = search_table(before);
			if (!tmp)
				insert_table(before, after);
		}		
		else
		{
			t_node * tmp = search_table(line);
			if (tmp)
				print_node(tmp);
			else
			{
				fputs(line, stdout);
				puts(": Not found");
			}
		}
	}
	if (line)
		free(line);

	//-----------------------------------------------------------------//

	delete_hashtable();
	
	return 0;
}
