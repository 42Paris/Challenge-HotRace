/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:59:57 by ngragas           #+#    #+#             */
/*   Updated: 2021/04/07 20:59:57 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>

# define TABLE_SIZE	1000003
# define OUT_BUFFER	524288
# define HASH1 113
# define HASH2 17

typedef struct	s_dict
{
	const char		*key;
	const char		*value;
	unsigned int	key_len;
	unsigned int	value_len_with_n;
	struct s_dict	*next;
}				t_dict;

typedef struct	s_output
{
	char		str[OUT_BUFFER];
	unsigned	len;
}				t_output;

extern	t_dict	*g_table[];

void	key_add(char *kv_str, char *eq_pos, unsigned int kv_len);
void	key_remove(const char *key, unsigned int key_len);
void	key_print(const char *key, size_t key_len);
void	bufcpy(const char *str, unsigned n);

int		generate_testdata_plain(void);
void	generate_printdata_plain(bool print);
void	generate_removedata_plain(bool print);
void	table_analyze(bool print);
double	get_cpu_time();

#endif
