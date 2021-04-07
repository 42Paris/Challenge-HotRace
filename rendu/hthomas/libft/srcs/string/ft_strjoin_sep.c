/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:29:35 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:41:16 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	count(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	k;
	int	cpt;

	i = 0;
	cpt = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		cpt += j;
		i++;
	}
	k = 0;
	while (sep[k])
		k++;
	return ((k * (size - 1)) + cpt + 1);
}

static char	*join(int size, char **strs, char *res, char *sep)
{
	int	l;
	int	i;
	int	j;
	int	k;

	k = 0;
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			res[k++] = strs[i][j++];
		l = 0;
		if (i != size - 1)
		{
			while (sep[l])
				res[k++] = sep[l++];
		}
	}
	res[k] = '\0';
	return (res);
}

char		*ft_strjoin_sep(int size, char **strs, char *sep)
{
	char	*res;

	if (!size)
	{
		res = malloc(1 * sizeof(char));
		if (!res)
			return (0);
		*res = 0;
		return (res);
	}
	res = malloc(count(size, strs, sep) * sizeof(char));
	if (!res)
		return (0);
	return (join(size, strs, res, sep));
}
