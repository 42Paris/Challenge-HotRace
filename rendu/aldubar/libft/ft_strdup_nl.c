/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_nl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:25:22 by aldubar           #+#    #+#             */
/*   Updated: 2021/01/11 19:01:23 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_nl(const char *s)
{
	char	*cpy;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[size])
		size++;
	cpy = (char *)malloc(sizeof(char) * (size + 2));
	if (!cpy)
		return (NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\n';
	i++;
	cpy[i] = '\0';
	return (cpy);
}
