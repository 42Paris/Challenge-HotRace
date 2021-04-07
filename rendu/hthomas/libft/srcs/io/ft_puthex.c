/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:29:00 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 09:34:09 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_puthex(unsigned int hex, int upper)
{
	char	c;

	if (upper)
		c = 'A';
	else
		c = 'a';
	if (hex < 16)
	{
		if (hex < 10)
			ft_putchar(hex + '0');
		else
			ft_putchar(hex + c - 10);
	}
	else
	{
		ft_puthex(hex / 16, upper);
		if (hex % 16 < 10)
			ft_putchar(hex % 16 + '0');
		else
			ft_putchar(hex % 16 + c - 10);
	}
}
