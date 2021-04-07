/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:29:00 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 09:30:05 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putpointer(unsigned long long pointer)
{
	if (pointer < 16)
	{
		if (pointer < 10)
			ft_putchar(pointer + '0');
		else
			ft_putchar(pointer + 'a' - 10);
	}
	else
	{
		ft_putpointer(pointer / 16);
		if (pointer % 16 < 10)
			ft_putchar(pointer % 16 + '0');
		else
			ft_putchar(pointer % 16 + 'a' - 10);
	}
}
