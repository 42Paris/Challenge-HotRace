/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:59:32 by eparisot          #+#    #+#             */
/*   Updated: 2017/11/14 16:53:51 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	result = NULL;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != c && s[i])
		i++;
	if (s[i] == '\0')
		return (NULL);
	result = (char *)&s[i];
	return (result);
}
