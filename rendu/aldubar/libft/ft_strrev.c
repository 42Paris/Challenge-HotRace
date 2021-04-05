/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:08:42 by aldubar           #+#    #+#             */
/*   Updated: 2021/01/05 15:45:16 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	len;
	char	buf;

	i = 0;
	len = ft_strlen(str);
	while (len - 1 > i)
	{
		buf = str[i];
		str[i] = str[len - 1];
		str[len - 1] = buf;
		len--;
		i++;
	}
	return (str);
}
