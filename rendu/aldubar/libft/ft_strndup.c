/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:25:22 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/05 21:17:18 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*cpy;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[size])
		size++;
	if (n > size)
		size = n;
	cpy = (char *)malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (NULL);
	while (s[i] && i < n)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
