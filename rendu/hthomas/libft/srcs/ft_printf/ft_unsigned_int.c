/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 09:38:11 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*precision_unsigned(char *str, t_sp *sp, t_f *f)
{
	if (!sp->u && !f->pr)
	{
		free(str);
		str = ft_chardup('\0');
		if (!str)
			return (NULL);
	}
	else
	{
		str = ft_cat(0, str, f->pr, '0');
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*ft_unsigned_int(va_list arg, t_sp *sp, t_f *f)
{
	char	*str;

	sp->u = va_arg(arg, unsigned int);
	str = ft_uitoa(sp->u);
	if (!str)
		return (NULL);
	if (f->precision)
	{
		str = precision_unsigned(str, sp, f);
		if (!str)
			return (NULL);
	}
	if (f->width)
	{
		if (f->zero && !f->precision)
			str = ft_cat(f->minus, str, f->width, '0');
		else
			str = ft_cat(f->minus, str, f->width, ' ');
		if (!str)
			return (NULL);
	}
	return (str);
}
