/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:55:42 by eparisot          #+#    #+#             */
/*   Updated: 2021/04/06 14:55:42 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H

# define HOTRACE_H

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"

# define CHUNK_SIZE 256

typedef struct			s_env
{
	char				**buf;
	t_list				*index_table;
	t_list				*data_table;
}						t_env;

typedef struct 			s_index_slot
{
	unsigned long		start_hash;
	void 				*start_addr;
	int					nb_nodes;
}						t_index_slot;

typedef struct 			s_data_slot
{
	char 				*key;
	char 				*val;
	unsigned long		hash;
	int					deleted;
}						t_data_slot;

t_env *g_env;

void sig_handler(int signum);
void init_env(void);
unsigned long calc_hash(unsigned char *str);
void del(void *addr, size_t size);
void del_data(void *addr, size_t size);
void cleanup(void);

#endif