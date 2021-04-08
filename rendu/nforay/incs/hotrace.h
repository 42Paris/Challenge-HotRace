/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:29:52 by nforay            #+#    #+#             */
/*   Updated: 2021/04/08 03:55:58 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef HASHTABLESIZE
#  define HASHTABLESIZE 2097152
# endif

# ifndef HASHLENGTH
#  define HASHLENGTH 16
# endif

# define KEY 0
# define VALUE 1

enum	e_state
{
	LOOKUP,
	INSERT,
	DELETE
};

typedef struct				s_list
{
	char					*content[2];
	struct s_list			*next;
}							t_list;

typedef struct				s_query
{
	uint32_t				hash;
	enum e_state			state;
	char					*input;
	int						key_len;
	t_list					**hashtable;
}							t_query;

typedef int					(*t_function)(t_query *, char *input);

void	ft_putendl_fd(char *s, int fd);
int		get_next_line(int fd, char **out);
void	*ft_memset(void *s, int c, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif