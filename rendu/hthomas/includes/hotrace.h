/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:26:40 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/06 06:15:32 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define MAX_CHAR 126
# define MIN_CHAR 32

typedef struct	s_dict
{
	t_dlist		*key;
	t_dlist		*values;
	int			size;
}				t_dict;


typedef struct			s_chain_tab
{
	char				letters[MAX_CHAR - MIN_CHAR + 1];
	struct s_chain_tab	*nexts[MAX_CHAR - MIN_CHAR + 1];
	char				*value;
}						t_chain_tab;


/*
** find_median
*/
t_dlist			*find_node(t_dlist *stack, int value);
int				size_stack(t_dlist *begin, t_dlist *end);
t_dlist			*find_median(t_dlist *stack, t_dlist *end);

/*
** print
*/
void			print_dlist_line(t_dlist *stack, char name);
void			print_clean_dlist(t_dlist *operations);

/*
** scan_input
*/
int				duplicates(t_dlist *a);
int				int_overflow(char const *str, int sign);
t_dlist			*scan_input(int argc, char const *argv[], int *print);

/*
** sort_quick
*/
int				sort_quick(t_dict *ab, t_dlist *begin, t_dlist *end,
					t_sp *norm);

/*
** sort_stack_2
*/
void			sort_stack_2(t_dict *ab, t_dlist **st, char name);
void			sort_stack_2_reverse(t_dict *ab, t_dlist **st, int push_on_a);

/*
** sort_stack_2
*/
void			sort_stack_3(t_dict *ab, t_dlist **st, char name);
void			sort_stack_3_reverse(t_dict *ab, t_dlist **st, char name);

/*
** sort_stack_under_3
*/
int				sort_stack_under_3(t_dict *ab, t_dlist **begin, t_dlist *end,
					int p_a);

/*
** utils
*/
void			error(char *str, t_dlist *a, t_dict *ab, t_sp *norm);
void			error_a_b(char *str, t_dlist *a, t_dlist *b, char *line);
int				get_value(t_dlist *stack);
char			*get_str(t_dlist *stack);
void			push_n_times(t_dict *ab, t_dlist **begin, char c, int n);

#endif
