/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:26:35 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:42:54 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_count_len_nbr_ui(unsigned int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		res++;
		n /= 10;
	}
	return (res);
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
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

static void	fill_str(char *str, unsigned int n, int i)
{
	if (n == 0)
		str[i++] = '0';
	while (n)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	str[i] = '\0';
}

char		*ft_uitoa(unsigned int n)
{
	char	*str;
	int		i;
	int		nblen;

	i = 0;
	nblen = ft_count_len_nbr_ui(n);
	str = malloc((nblen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	fill_str(str, n, i);
	return (ft_strrev(str));
}
