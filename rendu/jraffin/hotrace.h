/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:53:04 by jraffin           #+#    #+#             */
/*   Updated: 2021/04/06 22:23:13 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

typedef struct			s_indexnode
{
	struct s_indexnode	*next[224];
	char				*value;
}						t_indexnode;

void					free_tree(t_indexnode *node);
int						add_value(char *keyword, char *value,
															t_indexnode *node);
void					del_value(char *keyword, t_indexnode *node);
char					*get_value(char *keyword, t_indexnode *node);

#endif
