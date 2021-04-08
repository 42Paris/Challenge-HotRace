/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 03:03:54 by nforay            #+#    #+#             */
/*   Updated: 2021/04/08 03:31:36 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/hotrace.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		(void)!write(fd, &s[i], 1);
		i++;
	}
	(void)!write(fd, "\n", 1);
}

static char	*recurs(int depth, int *ret, int fd)
{
	char	buff[1];
	char	*out;
	int		test;
	test = read(fd, buff, 1);
	if (test == 0)
		buff[0] = 0;
	if (buff[0] == '\n' || buff[0] == 0)
	{
		if (!(out = malloc(sizeof(char) * depth + 1)))
			return (0);
		out[depth] = 0;
		*ret = 1;
		if (buff[0] == 0)
			*ret = 0;
		return (out);
	}
	else
	{
		if (!(out = recurs(depth + 1, ret, fd)))
			return (0);
		out[depth] = buff[0];
	}
	return (out);
}

int		get_next_line(int fd, char **out)
{
	int ret;
	ret = 1;
	*out = recurs(0, &ret, fd);
	return (ret);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*start;

	start = s;
	while (n > 0)
	{
		*start++ = c;
		n--;
	}
	return (s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (((s1[i] != '\0') || (s2[i] != '\0')) && (n > 0))
	{
		n--;
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
