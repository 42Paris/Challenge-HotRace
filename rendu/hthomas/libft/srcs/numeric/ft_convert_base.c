/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 08:15:50 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 09:15:17 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*fill_positivenbr_base(long nbr, char *base, char *res, int i)
{
	int			size;

	size = 0;
	while (base[size])
		size++;
	if (nbr != 0)
	{
		res[i] = (base[nbr % size]);
		return (fill_positivenbr_base(nbr / size, base, res, i + 1));
	}
	return (res);
}

char	*fill_nbr_base(char *res, long nbr, char *base, int sign)
{
	int			i;
	int			size;

	size = 0;
	while (base[size])
		size++;
	i = 0;
	if (sign < 0)
		res[i++] = '-';
	if (nbr != 0)
		res = fill_positivenbr_base(nbr, base, res, i);
	else if (nbr == 0)
		res[0] = (base[0]);
	return (res);
}

char	*ft_strrev_minus_1(char *res)
{
	int			i;
	char		c;
	int			len;

	i = 0;
	if (res[0] == '-')
		i = 1;
	len = ft_strlen(res) - 1;
	while (i < len)
	{
		c = res[i];
		res[i++] = res[len];
		res[len--] = c;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*res;
	long		nb;
	int			sign;

	if (!check_base(base_to) || !check_base(base_from))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	sign = 1;
	if (nb < 0)
	{
		nb *= -1;
		sign = -1;
	}
	res = malloc((ft_nbrlen(nb) + 1) * sizeof(char));
	if (!res)
		return (0);
	fill_nbr_base(res, nb, base_to, sign);
	return (ft_strrev_minus_1(res));
}
