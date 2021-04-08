/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:56:01 by eparisot          #+#    #+#             */
/*   Updated: 2018/03/19 19:07:00 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_is_int(const char *s)
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
		if (sign < 0 && result > (unsigned long)INT_MAX + 1)
			return (0);
		if (sign > 0 && result > (unsigned long)INT_MAX)
			return (0);
	}
	return (1);
}
