/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:40:59 by eparisot          #+#    #+#             */
/*   Updated: 2017/11/17 17:06:12 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (*find == '\0')
		return ((char *)str)		;
	i = -1;
	while (++i < len && str[i])
	{
		j = 0;
		while (find[j] == str[i + j] && (i + j) < len)
		{
			if (find[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
	}
	return (NULL);
}
