/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 09:52:09 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_precision_pointer(char *str, t_sp *sp, t_f *f)
{
	if (f->precision)
	{
		if (!sp->p && !f->pr)
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

char	*ft_pointer2(t_sp *sp, t_f *f)
{
	char	*str;
	char	*tmp;
	char	*tmpstr;

	str = ft_ltoa_base(sp->p, "0123456789abcdef");
	if (!str)
		return (NULL);
	str = ft_precision_pointer(str, sp, f);
	if (!str)
		return (NULL);
	tmp = str;
	tmpstr = ft_strdup("0x");
	if (!tmpstr)
		return (NULL);
	str = ft_strjoin(tmpstr, tmp);
	if (!str)
		return (NULL);
	free(tmp);
	free(tmpstr);
	return (str);
}

char	*ft_pointer(va_list arg, t_sp *sp, t_f *f)
{
	char	*str;

	sp->p = va_arg(arg, unsigned long);
	str = ft_pointer2(sp, f);
	if (!str)
		return (NULL);
	if (f->width)
	{
		if (f->zero)
			str = ft_cat(f->minus, str, f->width, '0');
		else
			str = ft_cat(f->minus, str, f->width, ' ');
		if (!str)
			return (NULL);
	}
	return (str);
}
