/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:30:46 by aldubar           #+#    #+#             */
/*   Updated: 2020/11/20 14:26:10 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_cat(char *dest, const char *src)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
	{
		dest[len] = src[i];
		i++;
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!join)
		return (NULL);
	join = ft_cpy(join, s1);
	join = ft_cat(join, s2);
	return (join);
}
