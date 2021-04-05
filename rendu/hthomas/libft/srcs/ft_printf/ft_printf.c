/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:42:33 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:44:03 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	fill_ftab(t_fptr *ftab)
{
	ftab[0] = &ft_char;
	ftab[1] = &ft_string;
	ftab[2] = &ft_pointer;
	ftab[3] = &ft_integer;
	ftab[4] = &ft_integer;
	ftab[5] = &ft_unsigned_int;
	ftab[6] = &ft_hex;
	ftab[7] = &ft_hex;
	ftab[8] = &ft_percent;
	ftab[9] = &ft_flag_n;
}

char	*ft_conversion(const char *fmt, va_list arg, t_sp *sp, t_f *f)
{
	t_fptr	ftab[NB_CONV];
	char	*conversions;
	int		i;

	(void)arg;
	conversions = "cspdiuxX\%n";
	fill_ftab(ftab);
	i = 0;
	while (i < NB_CONV)
	{
		if (fmt[sp->index] == conversions[i])
		{
			if (fmt[sp->index] == 'X')
				f->plus = 1;
			return (ftab[i](arg, sp, f));
		}
		i++;
	}
	return (NULL);
}

int		ft_printf3(const char *fmt, va_list arg, t_sp *sp)
{
	t_f				*f;
	char			*str;

	sp->index++;
	f = init_f();
	ft_get_flags(fmt, sp, f);
	ft_get_width(fmt, sp, f, arg);
	ft_get_precision(fmt, sp, f, arg);
	str = ft_conversion(fmt, arg, sp, f);
	if (!str)
		return (ERR);
	sp->len += ft_strlen(str);
	ft_putstr(str);
	free(str);
	free(f);
	return (OK);
}

int		ft_printf2(const char *fmt, va_list arg, t_sp *sp)
{
	reset_sp(sp);
	if (fmt[sp->index] == '%')
	{
		if (ft_printf3(fmt, arg, sp))
			return (ERR);
	}
	else
	{
		ft_putchar(fmt[sp->index]);
		sp->len++;
	}
	return (OK);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	arg;
	t_sp	*sp;
	int		len;

	va_start(arg, fmt);
	sp = init_sp();
	if (!sp)
		return (ERR);
	while (fmt[sp->index])
	{
		if (ft_printf2(fmt, arg, sp))
			return (ERR);
		sp->index++;
	}
	len = sp->len;
	free_sp(sp);
	va_end(arg);
	return (len);
}
