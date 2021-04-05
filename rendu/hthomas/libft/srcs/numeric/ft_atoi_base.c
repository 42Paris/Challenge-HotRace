/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:12:12 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 09:20:08 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

int	cacul_res(char *str, char *base, int size_base)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (*str)
	{
		if (*str == base[i])
		{
			res = (res * size_base) + i++;
			str++;
			i = 0;
		}
		else if (i == size_base)
			return (res);
		else
			i++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	size_base;

	sign = 1;
	size_base = 0;
	if (!check_base(base))
		return (0);
	while (base[size_base])
		size_base++;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str++ == '-' && sign == -1)
			sign *= -1;
	}
	return (sign * cacul_res(str, base, size_base));
}
