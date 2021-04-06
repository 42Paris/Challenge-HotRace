/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 18:32:33 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 11:35:27 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strnlen(char *str, size_t max)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	if (i <= max)
		return (i);
	else
		return (max);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	srclen;
	size_t	destlen;

	srclen = ft_strlen((const char *)src);
	destlen = ft_strnlen(dst, dsize);
	if (destlen == dsize)
		return (dsize + srclen);
	if (srclen < dsize - destlen)
		ft_memcpy(dst + destlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + destlen, src, dsize - destlen - 1);
		dst[dsize - 1] = '\0';
	}
	return (destlen + srclen);
}
