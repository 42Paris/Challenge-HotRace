/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:26:35 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:43:20 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	if (str[i] == '-')
		i++;
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

static void	fill_str(char *str, int n, int i)
{
	if (n == 0)
		str[i++] = '0';
	if (n < 0)
	{
		str[i++] = '-';
		n *= -1;
	}
	while (n)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	str[i] = '\0';
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		nblen;

	i = 0;
	nblen = ft_nbrlen(n);
	str = malloc((nblen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		str[i++] = '-';
		str[i++] = '8';
		n /= -10;
	}
	fill_str(str, n, i);
	return (ft_strrev(str));
}
