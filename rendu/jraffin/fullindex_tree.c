/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullindex_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:56:07 by jraffin           #+#    #+#             */
/*   Updated: 2021/04/08 12:48:40 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <string.h>
#include <stdlib.h>

void	free_tree(t_indexnode *node)
{
	int		i;

	if (node)
	{
		i = 0;
		while (i < 224)
		{
			if (node->next[i])
				free_tree(node->next[i]);
			i++;
		}
		free(node->value);
		free(node);
	}
}

int		add_value(char *keyword, char *value, t_indexnode *node)
{
	int		c;

	while (*keyword)
	{
		c = (unsigned char)*keyword - 32;
		if (!node->next[c])
			node->next[c] = calloc(1, sizeof(t_indexnode));
		if (!node->next[c])
			return (1);
		node = node->next[c];
		keyword++;
	}
	if (!node->value)
		node->value = strdup(value);
	return (!node->value);
}

void	del_value(char *keyword, t_indexnode *node)
{
	while (*keyword && node)
	{
		node = node->next[(unsigned char)*keyword - 32];
		keyword++;
	}
	if (node)
	{
		free(node->value);
		node->value = NULL;
	}
}

char	*get_value(char *keyword, t_indexnode *node)
{
	while (*keyword && node)
	{
		node = node->next[(unsigned char)*keyword - 32];
		keyword++;
	}
	if (node)
		return (node->value);
	return (NULL);
}
