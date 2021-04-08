/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:30:59 by frthierr          #+#    #+#             */
/*   Updated: 2021/04/08 09:40:45 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		HASH_MAP_H

# define	HASH_MAP_H

# include <string.h>
# include <stdbool.h>
# include <stdio.h>
# include "ft_lst.h"
#include "pair.h"

# define HASH_MAP_INIT_VALUE 0x7a120
// # define HASH_MAP_INIT_VALUE 20000


typedef struct	s_hash_map {
	size_t	capacity;
	t_list	**data;
}				t_hash_map;

unsigned long	hash(char *str);
void			free_data(t_hash_map *hash_map);
bool			init_hash_map(t_hash_map *hash_map, unsigned long size);
t_list			*in_list(t_list *list, const char *key);
bool			insert_data(const t_hash_map *hash_map, t_pair *pair);
bool			parse_command(const t_hash_map *hash_map, char *line);
char			*query_data(const t_hash_map *hash_map, t_pair *key);
void			delete_value(const t_hash_map *hash_map, char *key);


#endif