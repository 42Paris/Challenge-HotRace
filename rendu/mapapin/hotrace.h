/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <mapapin@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:59:22 by user42            #+#    #+#             */
/*   Updated: 2021/04/07 22:59:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TABLE_SIZE 131072

typedef struct			s_node
{

	int					color;
	char				*key;
	char				*value;
	struct s_node		*right;
	struct s_node		*left;
	struct s_node		*parent;

}						t_node;

static t_node * hash_table[TABLE_SIZE];

#endif
