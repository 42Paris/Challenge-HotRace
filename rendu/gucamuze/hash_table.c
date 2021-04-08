/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:46:26 by gucamuze          #+#    #+#             */
/*   Updated: 2021/04/08 12:25:08 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

unsigned	hash(char *str)
{
	int i = 0;

	for (int n = 0; str[n]; n++) {
		if (n == 1 || n == 2 || n == 3)
			i *= str[n];
		else
			i += str[n];
	}
	return (i % TABLE_SIZE);
}

void	free_table(t_HT *table)
{
	if (table) {
		if (table->nodes) {
			for (int n = 0; n < TABLE_SIZE; n++) {
				if (table->nodes[n])
					free(table->nodes[n]);
			}
			free(table->nodes);
		}
		if (table->lists) {
			for (int n = 0; n < TABLE_SIZE; n++) {
				if (table->lists[n])
					free(table->lists[n]);
			}
			free(table->lists);
		}
		free(table);
	}
}

t_HT	*create_table()
{
	t_HT	*table = malloc(sizeof(t_HT));
	
	table->nodes	= (t_node **)calloc(TABLE_SIZE, sizeof(t_node *));
	table->lists	= (t_list **)calloc(TABLE_SIZE, sizeof(t_list *));
	
	for (int n = 0; n < TABLE_SIZE; n++) {
		table->nodes[n] = NULL;
		table->lists[n] = NULL;
	}
	
	return (table);
}

