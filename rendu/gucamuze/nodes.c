/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:30:14 by gucamuze          #+#    #+#             */
/*   Updated: 2021/04/08 12:17:41 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_node	*node_create(char *keyword, char *value)
{
	t_node *node 	= malloc(sizeof(t_node));
	
	node->keyword	= keyword;
	node->value		= value;
	
	return (node);
}

void	node_delete(t_HT *table, unsigned int node_index)
{
	node_free(table->nodes[node_index]);
	table->nodes[node_index] = NULL;
}

void	node_free(t_node *node)
{
	if (node->value)
		free(node->value);
	if (node->keyword)
		free(node->keyword);
	free(node);
}