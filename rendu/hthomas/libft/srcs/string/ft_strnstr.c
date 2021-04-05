/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 20:09:44 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 03:27:57 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		start;
	char	*meule_de_foin;
	char	*aiguile;

	i = 0;
	meule_de_foin = (char *)haystack;
	aiguile = (char *)needle;
	if (!aiguile[i])
		return (meule_de_foin);
	while (meule_de_foin[i])
	{
		start = 0;
		while (i + start < len && meule_de_foin[i + start] == aiguile[start])
		{
			if (!aiguile[start++ + 1])
				return (&meule_de_foin[i]);
		}
		i++;
	}
	return (NULL);
}
