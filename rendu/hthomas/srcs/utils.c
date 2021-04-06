/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:00:24 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/06 11:21:04 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

int	in_charset(char const c, char const *charset, size_t *pos)
{
	*pos = 0;
	while (charset[*pos])
	{
		if (c == charset[*pos])
			return (1);
		(*pos)++;
	}
	return (0);
}
