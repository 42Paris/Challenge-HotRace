/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:29:37 by gucamuze          #+#    #+#             */
/*   Updated: 2021/04/08 13:27:32 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*list_search(t_list	*list_begin, char *keyword)
{
	while (list_begin) {
		if (strcmp(keyword, list_begin->keyword) == 0) {
			return (list_begin->value);
		}
		list_begin = (t_list *)list_begin->next;
	}
	return (NULL);
}

void	list_insert(t_list *list_begin, char *keyword, char *value)
{
	while (list_begin->next) {
		if (strcmp(keyword, list_begin->keyword) == 0) {
			return ;
		} else {
			list_begin = list_begin->next;
		}
	}
	if (strcmp(keyword, list_begin->keyword) == 0) {
		if (strcmp(value, list_begin->value) != 0) {
			return ;
		}	
	} else {
		t_list *new_item = list_create_item(keyword, value);
		list_begin->next = new_item;
	}
}

void	list_delete(t_HT *table, char *keyword, unsigned int hash)
{
	if (table->lists[hash]) { 
		t_list	*current = table->lists[hash];
		if (strcmp(current->keyword, keyword) == 0) {
			table->lists[hash] = current->next;
			list_free_item(current);
		} else {
			while (current) {
				t_list *previous = current;
				current = current->next;
				if (current) {
					if (strcmp(current->keyword, keyword) == 0) {
						previous->next = current->next;
						list_free_item(current);
						return ;
					}
				}
			}
		}
	}
}

t_list	*list_create_item(char *keyword, char *value)
{
	t_list	*list_item = malloc(sizeof(t_list));
	
	list_item->keyword	= keyword;
	list_item->value	= value;
	list_item->next		= NULL;
	
	return (list_item);
}

void	list_free_item(t_list *list_item)
{
	free(list_item->keyword);
	free(list_item->value);
	list_item->next = NULL;
	free(list_item);
}

void	list_free(t_list *list_begin)
{
	t_list	*current	= list_begin;
	t_list	*next		= (t_list *)list_begin->next;
	
	while (next)
	{
		list_free_item(current);
		current = next;
		next	= (t_list *)current->next;
	}
	if (current)
		list_free_item(current);
}

void	__DEBUG_print_list(t_list *list_begin)
{
	int n = 0;
	
	while (list_begin) {
		printf("LIST ITEM %d, keyword = %s, value = %s\n", n++, list_begin->keyword, list_begin->value);
		list_begin = list_begin->next;
	}
}