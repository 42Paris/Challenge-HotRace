/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:16:40 by aldubar           #+#    #+#             */
/*   Updated: 2020/11/18 16:09:52 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned	int	i;
	unsigned	int	size;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (start + len > ft_strlen(s))
		size = ft_strlen(s) - start;
	else
		size = len;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
