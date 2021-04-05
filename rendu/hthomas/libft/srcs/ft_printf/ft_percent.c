/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:49:15 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 09:53:40 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_percent(va_list arg, t_sp *sp, t_f *f)
{
	char	*str;

	(void)arg;
	sp->i = '%';
	str = ft_chardup(sp->i);
	if (!str)
		return (NULL);
	if (f->width || f->zero)
	{
		if (f->zero && !f->minus)
			str = ft_cat(f->minus, str, f->width, '0');
		else
			str = ft_cat(f->minus, str, f->width, ' ');
		if (!str)
			return (NULL);
		if (!sp->i)
			str[f->width - 1] = '\0';
	}
	if (!sp->i)
		sp->len++;
	return (str);
}
