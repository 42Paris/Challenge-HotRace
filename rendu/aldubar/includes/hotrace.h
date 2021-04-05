/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:26:05 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/06 00:05:00 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "../libft/libft.h"

typedef struct		s_elem
{
	char			*key;
	char			*value;
	struct s_elem	*next;
}					t_elem;

t_elem				*new_elem(char *key, char *value);
void				add_front(t_elem **alst, t_elem *new);
void				search_or_add(t_elem **dico, char *line);
char				*get_key(char *s);
char				*get_value(char *s);
void				clear_dico(t_elem *dico);

#endif
