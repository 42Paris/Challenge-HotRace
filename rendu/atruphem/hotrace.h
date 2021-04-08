/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:03:01 by atruphem          #+#    #+#             */
/*   Updated: 2021/04/07 22:17:45 by toni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# include <stdlib.h>
enum	e_rb_color
{
	RB_BLACK,
	RB_RED
};

typedef struct			s_rb_node
{
	struct	s_rb_node	*parent;
	struct	s_rb_node	*left;
	struct	s_rb_node	*right;
	char			*keyword;
	char			*value;
	int			enable;
	enum	e_rb_color	color;
}				t_rb_node;

int		ft_strcmp(char *s1, char *s2);
size_t		ft_strlen(const char *s);
t_rb_node	*rb_search(t_rb_node *root, char *keyword, int (*cmpf)(char *, char *));
int		rb_insert(t_rb_node **root, char *keyword, char *value,  int (*cmpf)(char *, char *));
void		right_rotation(t_rb_node *node);
void 		left_rotation(t_rb_node	*node);
t_rb_node	*rb_create_node(char *keyword, char *value);
void		root_check(t_rb_node **root);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		ft_putchar_fd(char c, int fd);
void		clean_tree(t_rb_node *root);

#endif
