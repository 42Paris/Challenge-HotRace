/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:02:44 by atruphem          #+#    #+#             */
/*   Updated: 2021/04/07 15:02:45 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

static void	rb_wc_delete_right(t_rb_node **node)
{
	t_rb_node	*tmp_node;
	
	tmp_node = *node;
	tmp_node->parent->right = NULL;
	while (tmp_node->parent)
	{
		if (tmp_node->parent->left->color == RB_RED)
		{
			right_rotation(tmp_node->parent);
			tmp_node->parent->color = RB_RED;
			tmp_node->parent->parent->color = RB_BLACK;
		}
		if (tmp_node->parent->left->left != NULL && tmp_node->parent->left->left->color == RB_RED)
		{
			right_rotation(tmp_node->parent);
			tmp_node->parent->parent->color = tmp_node->parent->color;
			tmp_node->parent->color = RB_BLACK;
			tmp_node->parent->parent->left->color = RB_BLACK;
			free(*node);
			return;
		}
		if (tmp_node->parent->left->right != NULL && tmp_node->parent->left->right->color == RB_RED)
		{
			left_rotation(tmp_node->parent->left);
			tmp_node->parent->left->color = RB_BLACK;
			tmp_node->parent->left->left->color = RB_RED;
			right_rotation(tmp_node->parent);
			tmp_node->parent->parent->color = tmp_node->parent->color;
			tmp_node->parent->color = RB_BLACK;
			tmp_node->parent->parent->left->color = RB_BLACK;
			free(*node);
			return;
		}
		if (tmp_node->parent->color == RB_RED)
		{
			tmp_node->parent->left->color = RB_RED;
			tmp_node->parent->color = RB_BLACK;
			free(*node);
			return;
		}
		tmp_node->parent->left->color = RB_RED;
		tmp_node = tmp_node->parent;
	}
	free(*node);
	return;
}

static void	rb_wc_delete_left(t_rb_node **node)
{
	t_rb_node	*tmp_node;
	
	tmp_node = *node;
	tmp_node->parent->left = NULL;
	while (tmp_node->parent)
	{
		if (tmp_node->parent->right->color == RB_RED)
		{
			left_rotation(tmp_node->parent);
			tmp_node->parent->color = RB_RED;
			tmp_node->parent->parent->color = RB_BLACK;
		}
		if (tmp_node->parent->right->right != NULL && tmp_node->parent->right->right->color == RB_RED)
		{
			left_rotation(tmp_node->parent);
			tmp_node->parent->parent->color = tmp_node->parent->color;
			tmp_node->parent->color = RB_BLACK;
			tmp_node->parent->parent->right->color = RB_BLACK;
			free(*node);
			return;
		}
		if (tmp_node->parent->right->left != NULL && tmp_node->parent->right->left->color == RB_RED)
		{
			right_rotation(tmp_node->parent->right);
			tmp_node->parent->right->color = RB_BLACK;
			tmp_node->parent->right->right->color = RB_RED;
			left_rotation(tmp_node->parent);
			tmp_node->parent->parent->color = tmp_node->parent->color;
			tmp_node->parent->color = RB_BLACK;
			tmp_node->parent->parent->right->color = RB_BLACK;
			free(*node);
			return;
		}
		if (tmp_node->parent->color == RB_RED)
		{
			tmp_node->parent->right->color = RB_RED;
			tmp_node->parent->color = RB_BLACK;
			free(*node);
			return;
		}
		tmp_node->parent->right->color = RB_RED;
		tmp_node = tmp_node->parent;
	}
	free(*node);
	return;
}

t_rb_node	*rb_delete(t_rb_node **node, t_rb_node **root)
{
	t_rb_node	*tmp_node;
	t_rb_node	**parent_side;
		
	if (*root == *node && (*node)->right == NULL && (*node)->left == NULL)
	{
		free(*node);
		*root = NULL;
		return (NULL);
	}
	if ((*node)->parent && (*node)->parent->left == *node)
		parent_side = &((*node)->parent->left);
	else if ((*node)->parent && (*node)->parent->right == *node)
		parent_side = &((*node)->parent->right);
	if ((*node)->right != NULL && (*node)->left != NULL)
	{
		tmp_node = (*node)->right;
		while (tmp_node->left != NULL)
			tmp_node = tmp_node->left;
		(*node)->keyword = tmp_node->keyword;
		(*node)->value = tmp_node->value;
		return (tmp_node);
	}
	else if ((*node)->right != NULL && (*node)->left == NULL)
	{
		(*node)->keyword = (*node)->right->keyword;
		(*node)->value = (*node)->right->value;
		return ((*node)->right);
	}		
	else if ((*node)->left != NULL && (*node)->right == NULL)
	{
		(*node)->keyword = (*node)->left->keyword;
		(*node)->value = (*node)->left->value;
		return ((*node)->left);
	}		
	else if ((*node)->right == NULL && (*node)->left == NULL)
	{
		if ((*node)->parent == NULL)
		{
			free(*node);
			*node = NULL;	
			return (NULL);
		}
		else if ((*node)->color == RB_RED)
		{
			*parent_side = NULL;
			free(*node);
			return (NULL);
		}
		else
		{	
			if ((*node)->parent->right == *node)
			{	
				rb_wc_delete_right(node);
				return (NULL);
			}
			else if ((*node)->parent->left == *node)
			{	
				rb_wc_delete_left(node);
				return (NULL);
			}
		}
	}
	return (NULL);
}
