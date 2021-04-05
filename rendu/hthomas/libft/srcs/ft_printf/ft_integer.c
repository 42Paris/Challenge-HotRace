/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 10:14:22 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*just_do_it(char *str, t_sp *sp, t_f *f)
{
	if (f->precision)
	{
		str = precision_integer(str, sp, f);
		if (!str)
			return (NULL);
	}
	if ((!f->zero && sp->i != INT_MIN) || f->precision)
	{
		str = ft_add_sign(str, sp, f);
		if (!str)
			return (NULL);
	}
	str = width_integer(str, sp, f);
	if (!str)
		return (NULL);
	if (f->zero && !f->precision)
	{
		str = ft_add_sign(str, sp, f);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*ft_integer(va_list arg, t_sp *sp, t_f *f)
{
	char	*str;
	int		ok;

	ok = 0;
	sp->i = va_arg(arg, int);
	if (sp->i < 0)
	{
		ok = 1;
		sp->i *= -1;
	}
	str = ft_itoa(sp->i);
	if (!str)
		return (NULL);
	if (ok == 1)
		sp->i *= -1;
	str = just_do_it(str, sp, f);
	if (!str)
		return (NULL);
	return (str);
}
