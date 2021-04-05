/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:44:42 by hthomas           #+#    #+#             */
/*   Updated: 2020/09/30 14:08:40 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strncmp_rev(const char *s1, const char *s2, size_t n)
{
	unsigned int	i1;
	unsigned int	i2;

	if (!(s1 || s2))
		return (0);
	if (!(s1 && s2))
		return (-1);
	if (s1 == s2)
		return (0);
	i1 = ft_strlen(s1) - 1;
	i2 = ft_strlen(s2) - 1;
	while (i1 + 1 && i2 + 1 && s1[i1] == s2[i2] && n--)
	{
		i1--;
		i2--;
	}
	if (n)
		return ((unsigned char)s1[i1] - (unsigned char)s2[i1]);
	return (0);
}
