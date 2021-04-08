/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:56:01 by eparisot          #+#    #+#             */
/*   Updated: 2018/05/10 16:05:37 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int				i;
	unsigned long	result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == '\r' || s[i] == '\v' || \
			s[i] == '\f' || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		result *= 10;
		result += s[i++] - 48;
		if (sign < 0 && result > 9223372036854775807)
			return (0);
		if (sign > 0 && result > 9223372036854775807)
			return (-1);
	}
	return (sign * result);
}
