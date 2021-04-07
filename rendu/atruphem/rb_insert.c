/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:02:51 by atruphem          #+#    #+#             */
/*   Updated: 2021/04/07 22:14:30 by toni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

t_rb_node	*rb_create_node(char *keyword, char *value)
{
	t_rb_node	*node;
	
	if (!(node = malloc(sizeof(t_rb_node))))
		return (NULL);
	
	node->parent = 0;
	node->left = 0;
	node->right = 0;
	node->keyword = keyword;
	node->value  = value;
	node->color = RB_RED;
	node->enable = 1;
	return (node);
}

static t_rb_node *uncle(t_rb_node 	*node)
{
	if (node->parent->parent == NULL)
		return (NULL);
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);
	else
		return (node->parent->parent->left);
}

static void	repair_tree(t_rb_node	*node)
{
	t_rb_node 	*uncle_node;

	if (node->parent == 0)
	{	
		node->color = RB_BLACK;
		return;
	}
	if (node->parent->color == RB_RED)
	{
		uncle_node = uncle(node);
		if (uncle_node == 0 || uncle_node->color == RB_BLACK)
		{
			if (node->parent->parent->left != 0 && node == node->parent->parent->left->right)
			{
				left_rotation(node->parent);
				node = node->left;
			}
			else if (node->parent->parent->right != 0 && node == node->parent->parent->right->left)
			{	
				right_rotation(node->parent);
				node = node->right;
			}
			if (node == node->parent->left)
			{	
				right_rotation(node->parent->parent);
				node->parent->right->color = RB_RED;
			}
			else
			{
				left_rotation(node->parent->parent);
				node->parent->left->color = RB_RED;
			}
			node->parent->color = RB_BLACK;
		}
		else if (uncle_node->color == RB_RED)
		{	
			uncle_node->color = RB_BLACK;
			node->parent->color = RB_BLACK;
			node->parent->parent->color = RB_RED;
			repair_tree(node->parent->parent);
			return;
		}
	}		
}

int	rb_insert(t_rb_node **root, char *keyword, char *value,  int (*cmpf)(char *, char *))
{
	t_rb_node	*new_node;
	t_rb_node	*tmp_node;

	if (*root == NULL)
	{	
		*root = rb_create_node(keyword, value);
		repair_tree(*root);
		return (1);
	}
	tmp_node = *root;
	while (tmp_node)
	{
		if (cmpf(tmp_node->keyword, keyword) < 0)
		{	
			if(tmp_node->right == 0)
			{
				if (!(new_node = rb_create_node(keyword, value)))
					return (0);
				tmp_node->right = new_node;
				new_node->parent = tmp_node;
				tmp_node = 0;
			}
			else
				tmp_node = tmp_node->right;
		}		
		else if (cmpf(tmp_node->keyword, keyword) == 0)
		{
			tmp_node->enable = 1;
			return (0);
		}
		else if (cmpf(tmp_node->keyword, keyword) > 0)
		{	
			if(tmp_node->left == 0)
			{
				if (!(new_node = rb_create_node(keyword, value)))
					return (0);
				tmp_node->left = new_node;
				new_node->parent = tmp_node;
				tmp_node = 0;
			}
			else
				tmp_node = tmp_node->left;
		}
	}
	repair_tree(new_node);
	if (new_node->parent == 0)
		*root = new_node;
	return (1);
}
		
