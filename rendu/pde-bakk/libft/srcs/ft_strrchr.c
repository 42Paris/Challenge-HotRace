/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 12:14:39 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/11/15 12:45:37 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	int		i;
	int		j;

	result = 0;
	i = 0;
	j = ft_strlen(s);
	while (i <= j)
	{
		if (s[i] == c)
			result = (char *)s + i;
		i++;
	}
	return (result);
}
