/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:04:54 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 09:07:07 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(char const *src)
{
	int		len;
	char	*cpy;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	cpy = malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (0);
	ft_memcpy(cpy, src, len);
	cpy[len] = '\0';
	return (cpy);
}
