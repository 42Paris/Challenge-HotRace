/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:30:22 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 09:23:41 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

float	ft_atof(const char *str)
{
	int		decimal_size;
	float	nb;
	int		sign;

	while (ft_in_charset(*str, "\t "))
		str++;
	sign = 1;
	if ((*str == '+' || *str == '-') && *str++ == '-')
		sign *= -1;
	nb = 0;
	nb += ft_atol(str);
	while (*str && ft_in_charset(*str, "0123456789"))
		str++;
	if (*str == '.')
		str++;
	else
		return (nb * sign);
	decimal_size = 0;
	while (ft_in_charset(str[decimal_size], "0123456789"))
		decimal_size++;
	if (decimal_size)
		nb += ft_atol(str) / (ft_pow(10, decimal_size));
	else
		return (nb * sign);
	return (nb * sign);
}
