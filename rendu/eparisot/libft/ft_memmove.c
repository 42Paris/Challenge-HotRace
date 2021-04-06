/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:58:38 by eparisot          #+#    #+#             */
/*   Updated: 2017/11/15 17:46:57 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*str1;
	char			*str2;

	str1 = (char *)dest;
	str2 = (char *)src;
	if (n == 0)
		return (dest);
	if (str2 < str1)
	{
		str1 = str1 + n - 1;
		str2 = str2 + n - 1;
		while (n-- > 0)
			*str1-- = *str2--;
	}
	else
	{
		while (n > 0)
		{
			*str1++ = *str2++;
			n--;
		}
	}
	return (dest);
}
