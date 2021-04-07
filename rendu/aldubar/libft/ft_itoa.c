/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:50:10 by aldubar           #+#    #+#             */
/*   Updated: 2020/11/19 15:18:49 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_nb(int n)
{
	size_t	len;
	long	mod;

	mod = 10;
	if (n < 0)
		len = 1;
	else
		len = 0;
	while (n % mod != n)
	{
		mod = mod * 10;
		len++;
	}
	len++;
	return (len);
}

static void	ft_putnb(char *str, unsigned int nb)
{
	size_t	i;

	i = 0;
	if (nb < 10)
	{
		while (str[i])
			i++;
		str[i] = nb + '0';
	}
	else
	{
		ft_putnb(str, nb / 10);
		ft_putnb(str, nb % 10);
	}
}

char		*ft_itoa(int n)
{
	unsigned	int	nb;
	int				len;
	char			*str;

	len = ft_len_nb(n) + 1;
	str = (char *)ft_calloc(len, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
		ft_putnb(str + 1, nb);
	}
	else
	{
		nb = n;
		ft_putnb(str, nb);
	}
	return (str);
}
