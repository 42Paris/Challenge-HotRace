/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 19:23:33 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 11:37:24 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t				i;
	char				*dst;
	unsigned int		tmp;

	i = 0;
	if (!(s))
		return (NULL);
	tmp = ft_strlen(s);
	if (start > tmp)
		return (ft_strdup(""));
	if (tmp < len)
		len = (size_t)tmp;
	dst = (char *)malloc(len + 1);
	if (!(dst))
		return (NULL);
	while (i < len && s[start])
	{
		dst[i] = s[start];
		start++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
