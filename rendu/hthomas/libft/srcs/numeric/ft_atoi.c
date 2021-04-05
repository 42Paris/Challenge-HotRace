/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:04:54 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 09:22:56 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if ((*nptr == '+' || *nptr == '-') && *nptr++ == '-')
		sign *= -1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res *= 10;
		res += *nptr++ - '0';
	}
	return (res * sign);
}
