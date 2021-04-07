/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 20:09:51 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:43:07 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	ft_strnlen(const char *str, size_t sizemax)
{
	size_t	i;

	i = 0;
	while (str[i] && i < sizemax)
		i++;
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lensrc;
	size_t	lendst;

	lensrc = ft_strlen(src);
	lendst = ft_strnlen(dst, dstsize);
	if (lendst == dstsize)
		return (lensrc + dstsize);
	if (lensrc < dstsize - lendst)
		ft_memcpy(dst + lendst, src, lensrc + 1);
	else
	{
		ft_memcpy(dst + lendst, src, dstsize - lendst - 1);
		dst[lendst + dstsize - lendst - 1] = '\0';
	}
	return (lensrc + lendst);
}
