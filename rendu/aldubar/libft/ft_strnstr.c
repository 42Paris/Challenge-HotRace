/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:27:17 by aldubar           #+#    #+#             */
/*   Updated: 2020/11/17 12:52:10 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i] && needle[j] &&
				haystack[i] == needle[j] && i < len)
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + i - j);
		i = i - j + 1;
	}
	return (NULL);
}
