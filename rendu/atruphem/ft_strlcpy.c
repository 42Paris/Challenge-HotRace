/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:44:36 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/21 18:25:14 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	int				srcsize;

	if (src == NULL)
		return (0);
	srcsize = 0;
	i = 0;
	while (src[i] != '\0')
	{
		srcsize++;
		i++;
	}
	if (dst == NULL)
		return (srcsize);
	if (size == 0)
		return (srcsize);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}
