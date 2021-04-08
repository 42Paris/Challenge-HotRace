/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:09:11 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/26 10:36:19 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int		ft_initialize(int fd, char **buffer, char **line, int *i)
{
	if ((i[1] = read(fd, buffer[0], BUFFER_SIZE)) == 0)
	{
		ft_clean(buffer);
		line[0][0] = '\0';
		return (1);
	}
	if (i[1] == -1)
	{
		ft_clean(buffer);
		free(line[0]);
		line[0] = NULL;
		i[1] = 0;
		return (-1);
	}
	i[0] = 0;
	return (0);
}

char	*ft_realloc(int size, char **line)
{
	char	*temp;
	int		i;

	if (!(temp = malloc((sizeof(char) * BUFFER_SIZE) * size + 1)))
		return (NULL);
	i = 0;
	while (i < (BUFFER_SIZE * (size - 1)))
	{
		temp[i] = line[0][i];
		i++;
	}
	if (size > 1)
		free(line[0]);
	line[0] = temp;
	return (line[0]);
}

int		ft_resize(char **line, int j, char **buffer)
{
	int		size;

	if (BUFFER_SIZE != 0)
		size = (j / BUFFER_SIZE) + 1;
	else
		size = 0;
	if (!(ft_realloc(size, line)))
	{
		ft_clean(buffer);
		return (-1);
	}
	return (0);
}

int		ft_loadbuffer(int fd, char **buffer, int *i)
{
	if ((i[1] = read(fd, buffer[0], BUFFER_SIZE)) == 0)
		return (1);
	i[0] = 0;
	return (0);
}

int		ft_reader(int *i, char **buffer, char **line, int fd)
{
	int		eofc;
	int		j;

	eofc = 0;
	j = 0;
	while (buffer[0][i[0]] != '\n')
	{
		if (i[1] == 0)
			if ((eofc = ft_loadbuffer(fd, buffer, i) == 1))
				break ;
		line[0][j] = buffer[0][i[0]];
		(i[0])++;
		j++;
		(i[1])--;
		if (i[1] == 0)
			if ((eofc = ft_loadbuffer(fd, buffer, i) == 1))
				break ;
		if (BUFFER_SIZE != 0)
			if (j % BUFFER_SIZE == 0)
				if ((ft_resize(line, j, buffer)) == -1)
					return (-1);
	}
	line[0][j] = '\0';
	return (eofc);
}
