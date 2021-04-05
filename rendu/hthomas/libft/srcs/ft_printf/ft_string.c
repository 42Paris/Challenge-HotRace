/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:46:21 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_precision_string(char *str, t_sp *sp, t_f *f)
{
	if (f->precision)
	{
		if (!sp->s && !f->pr)
		{
			free(str);
			str = ft_chardup('\0');
			if (!str)
				return (NULL);
		}
		else
		{
			if (f->precision && (int)ft_strlen(str) > f->pr)
				str[f->pr] = '\0';
		}
	}
	return (str);
}

char	*ft_string2(t_f *f, char *str)
{
	if (f->zero && !f->minus)
		str = ft_cat(f->minus, str, f->width, '0');
	else
		str = ft_cat(f->minus, str, f->width, ' ');
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_string(va_list arg, t_sp *sp, t_f *f)
{
	char	*str;

	sp->s = va_arg(arg, char *);
	if (!sp->s)
	{
		str = ft_strdup("(null)");
		if (!str)
			return (NULL);
	}
	else
	{
		str = ft_strdup(sp->s);
		if (!str)
			return (NULL);
	}
	str = ft_precision_string(str, sp, f);
	if (!str)
		return (NULL);
	if (f->width)
	{
		str = ft_string2(f, str);
		if (!str)
			return (NULL);
	}
	return (str);
}
