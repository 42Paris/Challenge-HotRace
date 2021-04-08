/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 18:32:23 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 11:35:41 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	srclen;

	if (!dst || !src)
		return (0);
	srclen = ft_strlen(src);
	if (srclen + 1 < dsize)
		ft_memcpy(dst, src, srclen + 1);
	else if (dsize != 0)
	{
		ft_memcpy(dst, src, dsize - 1);
		dst[dsize - 1] = 0;
	}
	return (srclen);
}
