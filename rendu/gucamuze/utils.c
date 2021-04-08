/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:33:06 by gucamuze          #+#    #+#             */
/*   Updated: 2021/04/08 12:21:05 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*create_values(char *str, size_t size)
{
	char	*content;

	if (!(content = malloc(size)))
		return (NULL);
	memcpy(content, str, size - 1);
	content[size - 1] = 0;
	return (content);
}

void	insert(t_HT *table, char *str, int sign_index)
{
	char			*keyword	= create_values(str, sign_index + 1);
	char			*value		= create_values(&str[sign_index + 1], strlen(&str[sign_index + 1]) + 1);
	unsigned int	node_index	= hash(keyword);

	if (!table->nodes[node_index])
		table->nodes[node_index] = node_create(keyword, value);
	else {
		if (strcmp(keyword, table->nodes[node_index]->keyword) == 0) {
				free(keyword);
				free(value);
				return ;
		}
		else {
			t_list	*list_item	= list_create_item(keyword, value);
			
			if (!table->lists[node_index]) {
				table->lists[node_index] = list_item;
			} else {
				list_insert(table->lists[node_index], keyword, value);
			}
		}
	}
}

char	*search(t_HT *table, char *keyword) {
	unsigned int	node_index	= hash(keyword);

	if (table->nodes[node_index]) {
		if (strcmp(table->nodes[node_index]->keyword, keyword) == 0)
			return (table->nodes[node_index]->value);
	} 
	if (table->lists[node_index]) {
		return (list_search(table->lists[node_index], keyword));	
	}
	
	return (NULL);
}

void	delete(t_HT *table, char *keyword) {
	unsigned int	node_index	= hash(keyword);

	if (table->nodes[node_index]) {
		if (strcmp(table->nodes[node_index]->keyword, keyword) == 0) {
			node_delete(table, node_index);
		}
		else if (table->lists[node_index]) {
			list_delete(table, keyword, node_index);
		}	
	}
}
