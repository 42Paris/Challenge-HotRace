/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:29:59 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/06 00:15:54 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_line(int readed, char **join, char **line)
{
	size_t	i;
	char	*tmp;

	if (readed < 0)
		return (-1);
	if (!*join)
	{
		*line = ft_strdup("");
		return (0);
	}
	i = 0;
	while ((*join)[i] != '\n' && (*join)[i] != '\0')
		i++;
	*line = ft_substr(*join, 0, i);
	if ((*join)[i] == '\n')
		tmp = ft_strdup(&(*join)[i + 1]);
	else
		tmp = NULL;
	free(*join);
	*join = tmp;
	if (!*join)
		return (0);
	return (1);
}

static int	ft_check(int fd, char **buf)
{
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return (0);
	if (read(fd, *buf, 0) < 0)
	{
		free(*buf);
		return (0);
	}
	return (1);
}

static int	check_flag(char *join, int flag)
{
	if (flag)
	{
		if (join)
		{
			free(join);
			join = NULL;
		}
		return (0);
	}
	return (1);
}

int			ft_gnl_clear(int fd, char **line, int clear_flag)
{
	char		*buf;
	static char	*join;
	char		*tmp;
	int			readed;

	if (!check_flag(join, clear_flag))
		return (0);
	if (!line || fd < 0 || BUFFER_SIZE < 1 || !ft_check(fd, &buf))
		return (-1);
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		buf[readed] = '\0';
		if (!join)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(join, buf);
		free(join);
		join = tmp;
		if (ft_strchr(join, '\n'))
			break ;
	}
	free(buf);
	return (get_line(readed, &join, line));
}
