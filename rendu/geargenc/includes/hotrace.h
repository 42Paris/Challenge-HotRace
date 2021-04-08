/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:40:28 by geargenc          #+#    #+#             */
/*   Updated: 2021/04/08 10:52:46 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define BUFF_SIZE 1024

typedef struct		s_htrc
{
	char			*content;
	struct s_htrc	*next;
}					t_htrc;

char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
int                 readstdin(char **line);

#endif
