/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:43:04 by abaudot           #+#    #+#             */
/*   Updated: 2021/04/07 10:50:10 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include <stdint.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 10000
# endif


typedef struct	s_reader
{
	char		*s;
	uint32_t	len;
	uint32_t	size;
}				t_reader;

int32_t				getNextLine(int32_t fd, t_reader *my_line);
uint8_t				initilize_reader(t_reader *reader, uint32_t n);
#endif
