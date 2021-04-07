/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:55:41 by ngragas           #+#    #+#             */
/*   Updated: 2021/04/07 13:45:44 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define BIG_BUF 262144
# define BUFFER_SIZE 65536

typedef struct	s_buf
{
	char		*s;
	char		*cur;
	unsigned	max;
	unsigned	cap;
}				t_buf;

int				get_next_line(char **line, unsigned *len);

#endif
