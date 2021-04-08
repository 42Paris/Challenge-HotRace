/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:00:03 by eparisot          #+#    #+#             */
/*   Updated: 2017/11/17 15:14:41 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return (1);
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (0);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	else
		return (0);
}
