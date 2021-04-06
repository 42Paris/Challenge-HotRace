/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 15:02:02 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/04/05 15:25:14 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_internal.h"
#include <unistd.h>

int	gnl_newlinecheck(char *str, int k)
{
	int	i;

	i = 0;
	if (k == 0 || k == 1)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	}
	if (k == 1)
	{
		while (str[i])
			i++;
		return (i);
	}
	return (-1);
}

char	*gnl_bufferfixer(char *buf)
{
	int	i;
	int	len;

	i = 0;
	len = gnl_newlinecheck(buf, 0) + 1;
	while (buf[i] && buf[len + i])
	{
		buf[i] = buf[len + i];
		i++;
	}
	while (buf[i])
	{
		buf[i] = 0;
		i++;
	}
	return (buf);
}

int	gnl_the_finisher(char *str, char *buf, char **line, int ret)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n' || str[i] == 0)
			break ;
		i++;
	}
	*line = gnl_strdup(str, i, 0);
	if (str)
		free(str);
	if (ret == 0 && buf)
	{
		free(buf);
		buf = NULL;
		return (0);
	}
	else
	{
		gnl_bufferfixer(buf);
		return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*buf;
	char		*str;
	int			ret;

	ret = 1;
	str = gnl_calloc(0, 0);
	if (!buf)
		buf = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buf != NULL && buf[0] != 0)
		ret = gnl_strlen(buf);
	while (ret > 0)
	{
		str = gnl_strjoiner(str, buf, ret);
		if (gnl_newlinecheck(str, 0) > -1)
			return (gnl_the_finisher(str, buf, line, ret));
		gnl_bzero(buf, BUFFER_SIZE + 1);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (ret);
	}
	if (ret == 0)
		return (gnl_the_finisher(str, buf, line, ret));
	return (0);
}
