/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 18:31:41 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 11:32:30 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fuck_normv3(char *d, const char *s, int len)
{
	while (len)
	{
		d[len - 1] = s[len - 1];
		len--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = 0;
	d = dst;
	s = src;
	if (dst == src)
		return (dst);
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		fuck_normv3(d, s, len);
	return (dst);
}
