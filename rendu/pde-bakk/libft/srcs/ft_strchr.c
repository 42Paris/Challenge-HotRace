/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 18:32:41 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 11:34:49 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	len = ft_strlen(s) + 1;
	i = 0;
	while (i < len)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
