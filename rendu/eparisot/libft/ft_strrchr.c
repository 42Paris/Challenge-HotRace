/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:00:56 by eparisot          #+#    #+#             */
/*   Updated: 2017/11/15 18:23:43 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = ft_strlen(s);
	result = NULL;
	if (ft_strlen(s) == 0)
		return (NULL);
	while (s[i] != c && i >= 0)
		i--;
	if (i < 0)
		return (NULL);
	result = (char *)&s[i];
	return (result);
}
