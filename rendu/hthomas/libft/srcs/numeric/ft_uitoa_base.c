/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 08:15:50 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:43:47 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_count_len_nbr_ui(unsigned int n, char *base_to)
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

char	*fill_base_ui(unsigned int nbr, char *base, char *res, int i)
{
	int		size;

	size = 0;
	while (base[size])
		size++;
	if (nbr != 0)
	{
		res[i] = (base[nbr % size]);
		return (fill_base_ui(nbr / size, base, res, i + 1));
	}
	return (res);
}

char	*fill_nbr_base_ui(char *res, unsigned int nbr, char *base)
{
	int		i;

	i = 0;
	if (nbr != 0)
		res = fill_base_ui(nbr, base, res, i);
	else if (nbr == 0)
		res[0] = (base[0]);
	return (res);
}

char	*ft_strrev_minus_ui(char *res)
{
	int			i;
	char		c;
	int			len;

	i = 0;
	len = ft_strlen(res) - 1;
	while (i < len)
	{
		c = res[i];
		res[i++] = res[len];
		res[len--] = c;
	}
	return (res);
}

char	*ft_uitoa_base(unsigned int nb, char *base_to)
{
	char		*res;

	if (!check_base(base_to))
		return (0);
	res = malloc((ft_count_len_nbr_ui(nb, base_to)) * sizeof(char));
	if (!res)
		return (0);
	fill_nbr_base_ui(res, nb, base_to);
	return (ft_strrev_minus_ui(res));
}
