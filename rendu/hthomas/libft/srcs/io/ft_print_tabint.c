/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tabint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:52:03 by hthomas           #+#    #+#             */
/*   Updated: 2020/10/03 17:18:52 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_print_tabint(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i++]);
		ft_putchar('\n');
	}
}
