/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:25:12 by frthierr          #+#    #+#             */
/*   Updated: 2021/04/08 09:40:39 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"
#include <unistd.h>

unsigned long hash(char *str)
{
    unsigned long hash = 0x1505;
    size_t	i = 0;
	int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;// * hash * 33 + c
		i++;
	}

    return hash;
}

t_list		*in_list(t_list *list, const char *key) {
	while (list) {
		if (!strcmp(list->key, key))
			return list;
		list = list->next;
	}
	return NULL;
}

bool		insert_data(const t_hash_map *hash_map, t_pair *pair) {
	
	unsigned long idx = hash(pair->key) % hash_map->capacity;
	t_list **list = &(hash_map->data[idx]);
	if (!in_list(*list, pair->key)) {
		t_list			*new_element = ft_lstnew(pair);
		if (!new_element)
			return false;
		ft_lstadd_front(list, new_element);
		return true;
	}
	return false;
}

void			delete_value(const t_hash_map *hash_map, char *key) {
	unsigned long idx = hash(key) % hash_map->capacity;
	t_list *list = hash_map->data[idx];

	if (list) {
		if (!strcmp(list->key, key)) {
			hash_map->data[idx] = list->next;
			ft_lstdelone(list);
		}
		else {
			while (list->next) {
				if (!strcmp(list->next->key, key)) {
					t_list *tmp = list->next;
					list->next = list->next->next;
					ft_lstdelone(tmp);
					break ;
				}
				list = list->next;
			}
		}
	}
}

void		free_data(t_hash_map *hash_map) {
	if (!hash_map->data)
		return ;
	for (unsigned long i = 0; i < hash_map->capacity; i++) {
		if (hash_map->data[i]) {
			ft_lstclear(&(hash_map->data[i]));
		}
	}
	free(hash_map->data);
}

bool		init_hash_map(t_hash_map *hash_map, unsigned long size) {
	// hash_map->data	= malloc(sizeof(t_list*) * size);
	hash_map->data	= calloc(sizeof(t_list*), size);
	hash_map->capacity = size;
	if (!(hash_map->data))
		return false;
	// for (unsigned long i = 0; i < size; i++) {
	// 	hash_map->data[i] = NULL;
	// }
	return true;
}

char			*query_data(const t_hash_map *hash_map, t_pair *pair) {
	unsigned long idx = hash(pair->key) % hash_map->capacity;
	t_list *list = hash_map->data[idx];

	if (list) {
		t_list *ret = in_list(list, pair->key);
		if (ret)
			return ret->value;
		else
			return NULL;
	}
	return NULL;
}

bool			parse_command(const t_hash_map *hash_map, char *line) {
	t_pair	pair;

	if (!line || !hash_map)
		return false;
	char * sep = strchr(line, '=');
	pair.key = line;
	if (sep) {
		*sep = '\0';
		sep++;
		pair.value = sep;
		return insert_data(hash_map, &pair);
	}
	else {
		pair.value = query_data(hash_map, &pair);
		if (pair.value)
			printf("%s\n", pair.value);
		else {
			printf("%s: Not found\n", pair.key);
			return false;
		}
		free(pair.key);
	}
	return true;
}
