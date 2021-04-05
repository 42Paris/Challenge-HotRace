/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:44:22 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*precision_integer(char *str, t_sp *sp, t_f *f)
{
	int		len;

	len = ft_strlen(str);
	if (!sp->i && !f->pr)
	{
		str = precision_sign(str, f);
		if (!str)
			return (NULL);
	}
	else if (f->precision && f->pr >= len)
	{
		str = ft_cat(0, str, f->pr, '0');
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

char	*ft_add_sign(char *str, t_sp *sp, t_f *f)
{
	char	*tmp;
	char	*tmpchar;
	char	positive;

	if (sp->i < 0 || f->plus || f->space)
	{
		positive = '+';
		if (f->space)
			positive = ' ';
		tmp = str;
		if (sp->i >= 0)
			tmpchar = ft_chardup(positive);
		else
			tmpchar = ft_chardup('-');
		if (!tmpchar)
			return (NULL);
		str = ft_strjoin(tmpchar, str);
		if (!str)
			return (NULL);
		free(tmp);
		free(tmpchar);
	}
	return (str);
}

char	*width_integer(char *str, t_sp *sp, t_f *f)
{
	(void)sp;
	if (f->width)
	{
		if (f->zero && !f->precision)
			str = ft_cat(f->minus, str, f->width - ((sp->i < 0)
						&& (f->zero && !f->precision)), '0');
		else
			str = ft_cat(f->minus, str, f->width - ((sp->i < 0)
						&& (f->zero && !f->precision)), ' ');
		if (!str)
			return (NULL);
	}
	return (str);
}

int		keep_position_sign2(char *str, int condition, int *fdf)
{
	int		idf;

	idf = 0;
	while (idf < (int)ft_strlen(str) && !*fdf)
	{
		if (condition)
			*fdf = ft_in_charset(str[idf], "+");
		else
			*fdf = ft_in_charset(str[idf], "-");
		idf++;
	}
	return (idf);
}

char	*keep_position_sign(char *str, int condition)
{
	int		is;
	int		idf;
	int		fds;
	int		fdf;

	is = 0;
	fds = 0;
	idf = keep_position_sign2(str, condition, &fdf);
	while (is < (int)ft_strlen(str) && !fds)
	{
		fds = ft_in_charset(str[is], "0");
		is++;
	}
	if (condition)
	{
		is = (int)ft_strlen(str) - 1;
		fds = 1;
	}
	if (fds && fdf)
	{
		ft_swap(&str[is], &str[idf]);
		return (str);
	}
	return (str);
}
