/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:40:59 by eparisot          #+#    #+#             */
/*   Updated: 2019/12/30 17:41:18 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_w(int n, char *p, int i, int base)
{
	int			sign;
	char		*tab;

	tab = "0123456789abcdef";
	sign = 1;
	if (n < 0)
	{
		n = -n;
		i++;
		sign = -1;
	}
	p[i] = '\0';
	while (i--)
	{
		p[i] = tab[n % base];
		n /= base;
	}
	if (sign == -1)
		p[0] = '-';
	return (p);
}

char			*ft_itoa_base(int n, int base)
{
	int		i;
	int		tmp;
	char	*p;

	if (base < 2 || base > 16)
		return (NULL);
	i = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	while (tmp >= base)
	{
		tmp /= base;
		i++;
	}
	if ((p = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	return (ft_w(n, p, i, base));
}
