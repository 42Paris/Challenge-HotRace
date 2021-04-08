/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 17:49:30 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 11:36:39 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t		i;
	size_t		nsize;

	i = 0;
	nsize = ft_strlen(needle);
	if (ft_strlen(haystack) < nsize)
		return (0);
	if (nsize == 0)
		return ((char *)haystack);
	while (i <= (n - nsize))
	{
		if (haystack[i] == needle[0])
			if (ft_strncmp(haystack + i, needle, nsize) == 0)
				return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
