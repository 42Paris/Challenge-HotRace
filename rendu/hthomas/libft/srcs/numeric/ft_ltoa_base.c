/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 08:15:50 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:44:15 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_count_len_nbr_l(unsigned long n, char *base_to)
{
	int		res;

	res = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		res++;
		n /= ft_strlen(base_to);
	}
	return (res);
}

char	*ft_ltoa_base(unsigned long nb, char *base_to)
{
	char		*res;

	if (!check_base(base_to))
		return (0);
	res = malloc((ft_count_len_nbr_l(nb, base_to) + 1) * sizeof(char));
	if (!res)
		return (0);
	res[ft_count_len_nbr_l(nb, base_to)] = '\0';
	fill_nbr_base(res, nb, base_to, 1);
	return (ft_strrev_minus_1(res));
}
