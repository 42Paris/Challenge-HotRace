/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 10:18:02 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_add_prefix(char *str, t_sp *sp, t_f *f, int uppercase)
{
	char	*tmp;
	char	*tmpstr;

	if (f->hash && sp->h)
	{
		tmp = str;
		if (uppercase)
			tmpstr = ft_strdup("0X");
		else
			tmpstr = ft_strdup("0x");
		if (!tmpstr)
			return (NULL);
		str = ft_strjoin(tmpstr, str);
		if (!str)
			return (NULL);
		free(tmp);
		free(tmpstr);
	}
	return (str);
}

char	*ft_precision_hex(char *str, t_sp *sp, t_f *f)
{
	if (f->precision)
	{
		if (!sp->h && !f->pr)
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
	}
	return (str);
}

char	*ft_hex(va_list arg, t_sp *sp, t_f *f)
{
	char	*str;

	sp->h = va_arg(arg, unsigned int);
	if (f->plus)
		str = ft_uitoa_base(sp->h, "0123456789ABCDEF");
	else
		str = ft_uitoa_base(sp->h, "0123456789abcdef");
	if (!str)
		return (NULL);
	str = ft_precision_hex(str, sp, f);
	if (!str)
		return (NULL);
	str = ft_add_prefix(str, sp, f, f->plus);
	if (!str)
		return (NULL);
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
