/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:02:16 by atruphem          #+#    #+#             */
/*   Updated: 2021/04/07 22:35:12 by toni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

void	clean_tree(t_rb_node *root)
{
	int	rig;
	int	lef;

	rig = 0;
	lef = 0;
	if (!root)
		return;
	if (root->right)
	{	
		clean_tree(root->right);
		rig = 1;
	}
	if (root->left)
	{
		clean_tree(root->left);
		lef = 1;
	}
	free(root->keyword);
	free(root->value);
	if (rig)
		free(root->right);
	if (lef)
		free(root->left);
}
