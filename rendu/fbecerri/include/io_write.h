/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_write.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <fbecerri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:27:26 by fbecerri          #+#    #+#             */
/*   Updated: 2021/04/07 10:27:30 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_WRITE_H

# define IO_WRITE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE_W 8192

typedef struct	s_write
{
	char		buffer[BUFFER_SIZE_W];
	int			index;
	int			nb_write;
}				t_write;

void			io_flush(t_write *output);
void			io_write(t_write *output, char *str, int size);
void			io_putchar(t_write *output, char c);

#endif
