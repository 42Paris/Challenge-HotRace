/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl_internal.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 12:21:37 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/04/05 15:24:52 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_INTERNAL_H
# define GNL_INTERNAL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>

void	*gnl_calloc(size_t count, size_t size);
char	*gnl_strdup(const char *s1, int n, int startpos);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoiner(char *s1, char *s2, int ret);
void	gnl_bzero(char *s, int n);

#endif
