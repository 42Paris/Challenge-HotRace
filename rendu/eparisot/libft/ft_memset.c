/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:58:49 by eparisot          #+#    #+#             */
/*   Updated: 2017/10/29 14:58:50 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (n == 0)
		return (s);
	str = (char *)s;
	while (i < n)
	{
		str[i] = (char)c;
		i++;
	}
	return (s);
}
