/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hotrace.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 21:24:31 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 23:40:47 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# define PAGES 127
# define BUFFER_SIZE 128

#include <stdio.h>

typedef struct s_dict
{
	void			*content;
	struct s_dict	*dict[PAGES];
}	t_dict;

int		get_line(char **line);
int		parse(t_dict **head, char *line);
int		keyword_new(t_dict **head, void *content, char *str);
t_dict	*keyword_find(t_dict *head, char *str);

#endif
