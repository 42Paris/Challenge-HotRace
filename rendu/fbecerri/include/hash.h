/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <fbecerri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:55:05 by fbecerri          #+#    #+#             */
/*   Updated: 2021/04/07 10:18:11 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H

# define HASH_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <time.h>
# include "ft_string.h"

# define DISPERTION 64
# define TABLE_SIZE 8192
# define GROWTH_RATIO 4

typedef struct		s_entry
{
	bool			fill;
	t_string		key;
	uint32_t		hash;
	t_string		data;
}					t_entry;

typedef struct		s_hashtable
{
	size_t			size;
	t_entry			bucket[];
}					t_hashtable;

t_hashtable			*create_hashtable(size_t size);
t_entry				create_entry(t_string key);
t_entry				*insert_hashtable(t_hashtable **table, t_entry entry);
t_entry				*hashtable_get(t_hashtable *table, t_string name);
void				hashtable_delete(t_hashtable *table, t_string name);

#endif
