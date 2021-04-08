/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:52:40 by ciglesia          #+#    #+#             */
/*   Updated: 2021/04/08 10:47:42 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_trie	*new_node()
{
	t_trie	*new;

	if (!(new = (t_trie*)malloc(sizeof(t_trie))))
		return (NULL);
	if (!(new->map = (t_trie**)malloc(sizeof(t_trie*) * 127))) // ascii
		return (NULL);
	memset(new->map, 0, sizeof(t_trie*) * 127);
	new->end = 0;
	new->children = 0;
	new->value = NULL;
	return (new);
}

void	insert_trie(t_trie **root, char *cmd, int eq)
{
	t_trie	*temp;
	int		i;
	char	x;

	if (*root == NULL)
		*root = new_node();
	i = 0;
	temp = *root;
	while (cmd[i] && i < eq)
	{
		x = cmd[i];
		if (temp->map[(int)x] == NULL)
		{
			temp->map[(int)x] = new_node();
			temp->children++;
		}
		temp = temp->map[(int)x];
		i++;
	}
	if (temp->end)
		return ;
	temp->end = 1;
	if (cmd[eq + 1])
		temp->value = strdup(&cmd[eq + 1]);
	else
		temp->value = strdup("");
}

int		get_value(t_trie *root, char *cmd)
{
	t_trie	*temp;
	int		i;
	char	x;

	if (root == NULL) //tree is empty
		return (printf("%s: Not found\n", cmd));
	i = 0;
	temp = root;
	while (cmd[i])
	{
		x = cmd[i];
		temp = temp->map[(int)x];
		if (temp == NULL)
			return (printf("%s: Not found\n", cmd));
		i++;
	}
	if (temp->end)
		return (printf("%s\n", temp->value));
	return (printf("%s: Not found\n", cmd));
}

void	delete_node(t_trie **node)
{
	if ((*node)->value)
	{
		free((*node)->value);
		(*node)->value = NULL;
	}
	if ((*node)->map)
		free((*node)->map);
	(*node)->map = NULL;
	if (*node)
		free(*node);
	*node = NULL;
}

t_trie	**delete_value(t_trie **root, char *key, int len, int depth)
{
	if (*root == NULL)
		return (NULL);
	if (depth == len)
	{
		if ((*root)->end)
			(*root)->end = 0;
		if ((*root)->value)
		{
			free((*root)->value);
			(*root)->value = NULL;
		}
		if ((*root)->children == 0)
			delete_node(root);
		return (root);
	}
	if ((*root)->map[(int)key[depth]] && ((*root)->map[(int)key[depth]] =
		 *delete_value(&(*root)->map[(int)key[depth]], key, len, depth + 1)) == NULL)
		(*root)->children--;
	if ((*root)->children == 0 && (*root)->end == 0)
		delete_node(root);
	return (root);
}

int		is_assignation(char *cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

void	exec_cmd(char *cmd, t_trie **root)
{
	int assign;

	if (cmd)
	{
		if (cmd[0] && cmd[0] == '!')
		{
			// erase key and value
			delete_value(root, &cmd[1], strlen(&cmd[1]), 0);
			return ;
		}
		assign = is_assignation(cmd);
		if (assign)
		{
			// store key and value
			insert_trie(root, cmd, assign);
			return ;
		}
		// search key
		get_value(*root, cmd);
	}
}

int		main()
{
	char *line;
    size_t len;
    ssize_t read;
	t_trie *root;

	root = NULL;
	len = 0;
	line = NULL;
    while ((read = getline(&line, &len, stdin)) != -1)
	{
		line[strlen(line) - 1] = 0;
		exec_cmd(line, &root);
	}
	if (line)
		free(line);
	return (0);
}
