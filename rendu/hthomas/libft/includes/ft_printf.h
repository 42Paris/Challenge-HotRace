/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:44:08 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:47:36 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

# define ERR -1
# define OK 0
# define NB_CONV 10

typedef struct		s_printf
{
	int				index;
	int				len;
	int				i;
	unsigned int	u;
	char			*s;
	unsigned long	p;
	unsigned int	h;
}					t_sp;

typedef struct		s_flags
{
	int				zero;
	int				minus;
	int				width;
	int				precision;
	int				pr;
	int				space;
	int				hash;
	int				plus;
}					t_f;

typedef char *(*t_fptr)(va_list arg, t_sp *sp, t_f *f);

int					ft_printf(const char *format, ...);

char				*ft_char(va_list arg, t_sp *sp, t_f *f);
char				*ft_string(va_list arg, t_sp *sp, t_f *f);
char				*ft_pointer(va_list arg, t_sp *sp, t_f *f);
char				*ft_integer(va_list arg, t_sp *sp, t_f *f);
char				*ft_unsigned_int(va_list arg, t_sp *sp, t_f *f);
char				*ft_hex(va_list arg, t_sp *sp, t_f *f);
char				*ft_percent(va_list arg, t_sp *sp, t_f *f);
char				*ft_flag_n(va_list arg, t_sp *sp, t_f *f);

t_sp				*init_sp(void);
t_sp				*reset_sp(t_sp *sp);
void				free_sp(t_sp *sp);
t_f					*init_f(void);

char				*ft_cat(int before, char *str, int length, char c);
char				*ft_add_sign(char *str, t_sp *sp, t_f *f);
char				*precision_sign(char *str, t_f *f);
char				*precision_integer(char *str, t_sp *sp, t_f *f);
char				*width_integer(char *str, t_sp *sp, t_f *f);
char				*keep_position_sign(char *str, int condition);
char				*ft_integer(va_list arg, t_sp *sp, t_f *f);

int					ft_atoi_no_sign(const char *nptr);

void				ft_get_flags(const char *fmt, t_sp *sp, t_f	*f);
void				ft_get_width(const char *fmt, t_sp *sp, t_f	*f,
						va_list arg);
void				ft_get_precision(const char *fmt, t_sp *sp, t_f	*f,
						va_list arg);

#endif
