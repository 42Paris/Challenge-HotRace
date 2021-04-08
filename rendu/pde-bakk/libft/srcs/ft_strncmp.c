/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 18:33:47 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 11:36:14 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	unsigned char	first;
	unsigned char	second;

	i = 0;
	while (i < len)
	{
		first = (unsigned char)s1[i];
		second = (unsigned char)s2[i];
		if (first != second)
			return (first - second);
		if (first == '\0' && second == '\0')
			return (0);
		i++;
	}
	return (0);
}
