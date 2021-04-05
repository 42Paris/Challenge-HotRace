/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:10:00 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 10:11:03 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*precision_sign(char *str, t_f *f)
{
	if (f->space || f->plus)
	{
		free(str);
		str = ft_chardup('\0');
		if (!str)
			return (NULL);
	}
	else
	{
		free(str);
		str = ft_chardup('\0');
		if (!str)
			return (NULL);
	}
	return (str);
}
