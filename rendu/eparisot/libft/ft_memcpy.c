/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:58:17 by eparisot          #+#    #+#             */
/*   Updated: 2017/11/08 14:33:16 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*str1;
	char			*str2;

	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	str1 = (char *)dest;
	str2 = (char *)src;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dest);
}
