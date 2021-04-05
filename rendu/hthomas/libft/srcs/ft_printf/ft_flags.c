/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:07:56 by hthomas           #+#    #+#             */
/*   Updated: 2020/09/30 14:10:51 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_get_flags(const char *fmt, t_sp *sp, t_f *f)
{
	while (ft_in_charset(fmt[sp->index], "-0# +"))
	{
		if (fmt[sp->index] == '-')
			f->minus = 1;
		else if (fmt[sp->index] == '0')
			f->zero = 1;
		else if (fmt[sp->index] == '#')
			f->hash = 1;
		else if (fmt[sp->index] == ' ')
			f->space = 1;
		else if (fmt[sp->index] == '+')
			f->plus = 1;
		sp->index++;
	}
}

void	ft_get_width(const char *fmt, t_sp *sp, t_f *f, va_list arg)
{
	if (fmt[sp->index] == '*')
	{
		f->width = va_arg(arg, int);
		if (f->width < 0)
		{
			f->width *= -1;
			f->minus = 1;
			f->zero = 0;
		}
		sp->index++;
	}
	else
	{
		f->width = ft_atoi_no_sign(&fmt[sp->index]);
		while (ft_isdigit(fmt[sp->index]))
			sp->index++;
	}
}

void	ft_get_precision(const char *fmt, t_sp *sp, t_f *f, va_list arg)
{
	int	i;

	if (fmt[sp->index] == '.')
	{
		sp->index++;
		if (fmt[sp->index] == '*')
		{
			sp->index++;
			i = va_arg(arg, int);
		}
		else
		{
			i = ft_atoi(&fmt[sp->index]);
			while (ft_isdigit(fmt[sp->index]))
				sp->index++;
		}
		if (i >= 0)
		{
			f->precision = 1;
			f->pr = i;
		}
	}
}

char	*ft_flag_n(va_list arg, t_sp *sp, t_f *f)
{
	(void)f;
	(void)arg;
	sp->index++;
	return (ft_strdup(""));
}
