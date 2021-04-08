/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:59:11 by eparisot          #+#    #+#             */
/*   Updated: 2017/10/29 14:59:12 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long trans;

	trans = n;
	if (trans < 0)
	{
		ft_putchar('-');
		trans *= -1;
	}
	if (trans > 9)
	{
		ft_putnbr(trans / 10);
		ft_putnbr(trans % 10);
	}
	else
		ft_putchar(trans + '0');
}
