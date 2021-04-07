/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:28:13 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 03:27:57 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c1;

	i = ft_strlen(s) + 1;
	c1 = (char)c;
	while (--i)
	{
		if (s[i] == c1)
			return ((char *)s + i);
	}
	if (s[i] == c1)
		return ((char *)s + i);
	return (NULL);
}
