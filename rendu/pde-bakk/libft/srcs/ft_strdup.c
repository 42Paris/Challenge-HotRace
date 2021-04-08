/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 19:23:08 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 11:34:57 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	i = ft_strlen(s1) + 1;
	dup = (char *)malloc(i);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s1, i);
	return (dup);
}
