#include "inneclud.h"
#include "pair.h"

node		*new_node(const char *key, const char *value)
{
	node	*ret = malloc(sizeof(node));

	if (!ret)
		return (0);
	ret->key = key;
	ret->value = value;
	ret->left = 0;
	ret->right = 0;
	ret->disabled = 0;
	return (ret);
}

node		*get_node(const char *key, node *root)
{
	node	*curr = root;
	int		cmp;

	if (!root)
		return (0);
	cmp = strcmp(root->key, key);
	while (cmp)
	{
		if (curr)
		{
			if (cmp > 0)
				curr = curr->right;
			else
				curr = curr->left;
			if (!curr)
				return (0);
		}
		/*
		**	Ouch :( strcmp really slowing things down. Hashing would probably
		**	make things faster..
		**
		**	92% of the time spent in get_node is spent strcmparing :/
		**
		**  0.00 :   401342:       mov    (%rbx),%rdi
		** 91.98 :   401345:       mov    %r15,%rsi
		**  0.29 :   401348:       callq  401070 <strcmp@plt>
		*/
		cmp = strcmp(curr->key, key);
	}
	if (curr->disabled)
		return (0);
	return (curr);
}

void		insert(const char *line, const char *equal_pos, node **root)
{
	node	*curr, *parent;
	int		cmp;

	if (!*root)
		*root = new_node(strndup(line, (uintptr_t)(equal_pos - line)), strdup(equal_pos + 1));
	else
	{
		curr = *root;
		while (1)
		{
			/*
			**  This strcmp takes 79% of insert's runtime... :( Hashing would be so
			**  great right now...
			**
			**    0.00 :   4013e0:       mov    0x10(%rbx),%rax
			**	  9.59 :   4013e4:       test   %rax,%rax
			**    0.00 :   4013e7:       je     401430 <insert+0xa0>
			**    0.00 :   4013e9:       mov    %rax,%rbx
			**         :                                    cmp = strcmp(curr->key, key);
			**    0.00 :   4013ec:       mov    (%rax),%rdi
			**   79.00 :   4013ef:       mov    %r12,%rsi
			**    0.07 :   4013f2:       callq  401070 <strcmp@plt>
			**
			*/

			cmp = strncmp(curr->key, line, equal_pos - line);
			if (cmp < 0)
			{
				parent = curr;
				if (!(curr = curr->left))
				{
					parent->left = new_node(strndup(line, (uintptr_t)(equal_pos - line)), strdup(equal_pos + 1));
					return;
				}
			}
			else if (cmp > 0)
			{
				parent = curr;
				if (!(curr = curr->right))
				{
					parent->right = new_node(strndup(line, (uintptr_t)(equal_pos - line)), strdup(equal_pos + 1));
					return;
				}
			}
			else if (!cmp)
			{
				if (curr->disabled)
				{
					curr->value = strdup(equal_pos + 1);
					curr->disabled = 0;
				}
				return;
			}
		}
	}
}

void	delete(const char *key, node *root)
{
	node	*curr;
	int		cmp;

	if (!root)
		return;
	curr = root;
	while (curr)
	{
		cmp = strcmp(curr->key, key);
		if (cmp < 0)
			curr = curr->left;
		else if (cmp > 0)
			curr = curr->right;
		else if (!cmp)
		{
			curr->disabled = 1;
			return;
		}
	}
}


