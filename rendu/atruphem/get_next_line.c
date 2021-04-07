/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:32:52 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/26 10:35:34 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	ft_reset(char **buffer, int *fdc, int *i, int fd)
{
	ft_clean(buffer);
	i[0] = 0;
	i[1] = 0;
	*fdc = fd;
}

int		ft_clean(char **buffer)
{
	free(buffer[0]);
	buffer[0] = NULL;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*buffer = NULL;
	static int		i[3] = {0};
	static int		eofc = 0;

	if (line == NULL || BUFFER_SIZE == 0 || !(ft_realloc(1, line)))
		return (-1);
	if (i[2] != fd)
		ft_reset(&buffer, &(i[2]), i, fd);
	if (!buffer)
		if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE)))
			return (-1);
	if (i[1] == 0)
		if ((eofc = ft_initialize(fd, &buffer, line, i)) == -1)
			return (-1);
	if (eofc)
		return (0);
	if ((eofc = ft_reader(i, &buffer, line, fd)) == -1)
		return (-1);
	if (eofc)
		if (ft_clean(&buffer))
			return (0);
	(i[0])++;
	(i[1])--;
	return (1);
}
