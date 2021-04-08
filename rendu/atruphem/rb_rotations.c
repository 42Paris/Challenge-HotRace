/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:03:33 by atruphem          #+#    #+#             */
/*   Updated: 2021/04/07 15:03:35 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

void 	left_rotation(t_rb_node	*node)
{
	t_rb_node	*tmp_node;

	tmp_node = node->right;
	node->right = tmp_node->left;
	if (node->right != 0)
		node->right->parent = node;
	tmp_node->parent = node->parent;
	if (tmp_node->parent != 0)
	{
		if (node == tmp_node->parent->left)
			tmp_node->parent->left = tmp_node;
		else
			tmp_node->parent->right = tmp_node;
	}
	tmp_node->left = node;
	node->parent = tmp_node;
}

void	right_rotation(t_rb_node *node)
{
	t_rb_node	*tmp_node;

	tmp_node = node->left;
	node->left = tmp_node->right;
	if (node->left != 0)
		node->left->parent = node;
	tmp_node->parent = node->parent;
	if (tmp_node->parent != 0)
	{
		if (node == tmp_node->parent->left)
			tmp_node->parent->left = tmp_node;
		else
			tmp_node->parent->right = tmp_node;
	}
	tmp_node->right = node;
	node->parent = tmp_node;
}
