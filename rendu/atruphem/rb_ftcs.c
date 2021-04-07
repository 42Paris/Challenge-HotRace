/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_ftcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:03:23 by atruphem          #+#    #+#             */
/*   Updated: 2021/04/07 15:03:25 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

t_rb_node	*rb_search(t_rb_node *root, char *keyword, int (*cmpf)(char *, char *))
{
	t_rb_node	*tmp_node;

	if (root == NULL)
		return (NULL);
	tmp_node = root;
	while (tmp_node)
	{
		if (cmpf(tmp_node->keyword, keyword) == 0)
			return (tmp_node);
		else if (cmpf(tmp_node->keyword, keyword) < 0)
		{	
			if(tmp_node->right == 0)
				return (NULL);
			else
				tmp_node = tmp_node->right;
		}		
		else if (cmpf(tmp_node->keyword, keyword) > 0)
		{	
			if(tmp_node->left == 0)
				return (NULL);
			else
				tmp_node = tmp_node->left;
		}
	}
	return (NULL);
}

void	root_check(t_rb_node **root)
{
	while ((*root)->parent != NULL)
		*root = (*root)->parent;
	return;
}

