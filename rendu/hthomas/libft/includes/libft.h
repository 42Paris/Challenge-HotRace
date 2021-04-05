/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:02:45 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:47:46 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "ft_printf.h"
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlist
{
	void			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

/*
** io
*/
void				ft_print_tabint(int *tab, int size);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putnbr_unsigned_fd(unsigned int nb, int fd);
void				ft_putnbr_unsigned(unsigned int nb);
void				ft_putchar(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_puthex(unsigned int hex, int upper);
void				ft_putpointer(unsigned long long pointer);
void				ft_putstrn_fd(const char *str, int fd, unsigned int n);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putstr(const char *str);
void				ft_putstrn(const char *str, unsigned int n);

/*
** linked-list
*/
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **alst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/*
** linked-list-doubly
*/
t_dlist				*ft_dlstnew(void *content);
void				ft_dlstadd_front(t_dlist **adlst, t_dlist *new);
int					ft_dlstsize(t_dlist *dlst);
t_dlist				*ft_dlstlast(t_dlist *dlst);
void				ft_dlstadd_back(t_dlist **adlst, t_dlist *new);
void				ft_dlstdelone(t_dlist *dlst, void (*del)(void*));
void				ft_dlstclear(t_dlist **adlst, t_dlist *dlst,
						void (*del)(void*));
void				ft_dlstiter(t_dlist *dlst, void (*f)(void *));
t_dlist				*ft_dlstmap(t_dlist *dlst, void *(*f)(void *),
						void (*del)(void *));
t_dlist				*ft_dlstremove_one(t_dlist **adlst, t_dlist *dlst);

/*
** memory
*/
void				ft_swap(void *a, void *b);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *b, size_t n);
char				*ft_chardup(char const c);
void				ft_free_tab(char **tab);

/*
** numeric
*/
int					ft_nbrlen(int n);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
char				*ft_itoa(int nbr);
long				ft_atol(const char *nptr);
char				*ft_uitoa(unsigned int n);
char				*ft_ltoa(long n);
char				*ft_ltoa_base(unsigned long nb, char *base_to);
char				*ft_uitoa_base(unsigned int nb, char *base_to);
char				*ft_itoa_width(int nb, int width);
double				ft_pow(double nb, double pow);
void				ft_print_tabstr(char **tab);
int					ft_atoi(const char *str);
int					ft_atoi_strict(const char *nptr);
float				ft_atof(const char *str);
int					ft_atoi_base(char *str, char *base);
int					ft_max_int(int a, int b);
float				ft_max_float(float a, float b);
int					ft_min_int(int a, int b);
float				ft_min_float(float a, float b);
int					check_base(char *base);
char				*fill_positivenbr_base(long nbr, char *base,
						char *res, int i);
char				*fill_nbr_base(char *res, long nbr, char *base, int sign);

/*
** string
*/
int					ft_is_from_charset(const char *str, const char *charset);
char				*ft_strrev_minus_1(char *res);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strndup(char const *src, int size);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strcat(char *dest, const char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp_rev(const char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split_set(const char *str, char *charset);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_sep(int size, char **strs, char *sep);
char				*ft_strjoin_free(char *s1, const char *s2);
char				*ft_strtrim(char const *str, char const *set);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);
int					ft_isprint(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_issign(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_in_charset(char c, char const *charset);
char				**ft_split(char const *s, char c1);

/*
** tabs
*/
void				sort_int(int *tab, int size);
void				sort_str(char *tabstr[], int size);

#endif
