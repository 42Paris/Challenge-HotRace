/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <fbecerri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:25:53 by fbecerri          #+#    #+#             */
/*   Updated: 2021/04/07 10:26:32 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_READ_H

# define IO_READ_H

# include <sys/types.h>
# include <unistd.h>
# include "ft_string.h"

# define BUFFER_SIZE_R 4096

typedef enum	e_mode {
	research,
	add,
	del,
	end,
}				t_mode;

typedef struct	s_io_read {
	size_t	index;
	size_t	size;
	size_t	size_max;
	size_t	fd;
	char	buffer[];
}				t_io_read;

t_io_read		*init_reader(size_t size, int fd);
int				io_read_file(t_io_read **r1);
int				read_line(t_string *s1, t_string *s2, t_io_read *r);

#endif
