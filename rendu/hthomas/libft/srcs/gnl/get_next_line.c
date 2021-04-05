/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:12:56 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:40:27 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*recurs(int depth, int *ret, int fd)
{
	char	buff[1];
	char	*out;
	int		test;

	test = read(fd, buff, 1);
	if (test == 0)
		buff[0] = 0;
	if (buff[0] == '\n' || buff[0] == 0)
	{
		out = malloc(sizeof(char) * depth + 1);
		out[depth] = 0;
		*ret = 1;
		if (buff[0] == 0)
			*ret = 0;
		return (out);
	}
	else
	{
		out = recurs(depth + 1, ret, fd);
		out[depth] = buff[0];
	}
	return (out);
}

int		get_next_line(char **out, int fd)
{
	int	ret;

	ret = 1;
	*out = recurs(0, &ret, fd);
	return (ret);
}

int		main_gnl(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	if (argc == 2)
		fd = open((argv[1]), O_RDONLY);
	else
		fd = 0;
	ret = get_next_line(&line, fd);
	while (ret == 1)
	{
		ft_printf("\nret: %d\nline = |%s|\n", ret, line);
		free(line);
		ret = get_next_line(&line, fd);
	}
	if (ret == 0)
		ft_printf("\nret: %d\nline = |%s|\n", ret, line);
	else if (ret == -1)
		ft_printf("\nret: %d\nline = |%s|\n", ret, line);
	free(line);
	close(fd);
	return (0);
}
