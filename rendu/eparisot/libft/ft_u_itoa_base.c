/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:40:59 by eparisot          #+#    #+#             */
/*   Updated: 2019/12/30 17:41:18 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned char	*ft_w(uint32_t n, unsigned char *p, int i, int base)
{
	char	*tab;
	int		j;

	j = 0;
	tab = "0123456789abcdef";
	while (i + j < 8)
		p[j++] = tab[0];
	p[8] = '\0';
	while (i--)
	{
		p[j + i] = tab[n % base];
		n /= base;
	}
	return (p);
}

unsigned char			*ft_u_itoa_base(uint32_t n, int base)
{
	int				i;
	uint32_t		tmp;
	unsigned char	*p;

	if (base < 2 || base > 16)
		return (NULL);
	i = 1;
	tmp = n;
	while (tmp >= (uint32_t)base)
	{
		tmp /= base;
		i++;
	}
	if ((p = (unsigned char *)malloc(sizeof(char) * (8 + 1))) == NULL)
		return (NULL);
	return (ft_w(n, p, i, base));
}
