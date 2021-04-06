/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:01:04 by eparisot          #+#    #+#             */
/*   Updated: 2017/11/14 20:21:49 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *to_find)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = NULL;
	if (ft_strlen(to_find) == 0)
		return ((char *)s);
	if (ft_strlen(s) == 0)
		return (NULL);
	while (s[i])
	{
		result = (char *)&s[i];
		while (s[i + j] && to_find[j] && s[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (result);
		j = 0;
		i++;
	}
	return (NULL);
}
