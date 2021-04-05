/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:04:54 by hthomas           #+#    #+#             */
/*   Updated: 2020/09/30 14:08:40 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst1;
	char		*lastd;
	const char	*src1;
	const char	*lasts;

	if (!dst && !src)
		return (dst);
	dst1 = (char *)dst;
	src1 = (char *)src;
	if (dst1 < src1)
	{
		while (len--)
			*dst1++ = *src1++;
	}
	else
	{
		lasts = src1 + (len - 1);
		lastd = dst1 + (len - 1);
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dst);
}
