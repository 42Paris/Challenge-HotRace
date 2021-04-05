/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:22:10 by aldubar           #+#    #+#             */
/*   Updated: 2020/11/18 16:25:34 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_charset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static	int		ft_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (is_charset(s1[i], set))
		i++;
	return (i);
}

static	int		ft_stop(char const *s1, char const *set)
{
	int	stop;
	int	len;

	stop = 0;
	len = ft_strlen((char *)s1);
	while (is_charset(s1[len - stop - 1], set))
		stop++;
	return (len - stop);
}

static char		*ft_ncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		start;
	int		stop;
	char	*res;

	if (!s1)
		return (NULL);
	start = ft_start(s1, set);
	if (start >= (int)ft_strlen(s1))
	{
		res = (char *)malloc(sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	stop = ft_stop(s1, set);
	len = stop - start;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res = ft_ncpy(res, s1 + start, len);
	res[len] = '\0';
	return (res);
}
