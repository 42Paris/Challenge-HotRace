/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:00:45 by eparisot          #+#    #+#             */
/*   Updated: 2017/11/17 16:08:05 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if ((ft_strlen(s1) == 0 && ft_strlen(s2) == 0) || n == 0)
		return (1);
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (0);
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	else
		return (0);
}
