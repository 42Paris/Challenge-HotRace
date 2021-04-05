/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:30:13 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:43:13 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	count_size(char const *str, char const *set)
{
	int	blanks;
	int	i;

	if (!*str)
		return (0);
	blanks = 0;
	i = 0;
	while (ft_in_charset(str[i++], set))
		blanks++;
	if (!(ft_strlen(str) - blanks))
		return (0);
	i = ft_strlen(str) - 1;
	while (ft_in_charset(str[i--], set))
		blanks++;
	return (ft_strlen(str) - blanks);
}

/*
** remove from str the chars in set
** @param str	string that will be trimed
** @param set	set of chars to remove from str
** @return		the str trimed
*/

char		*ft_strtrim(char const *str, char const *set)
{
	int		i;
	int		start;
	int		size;
	char	*new;

	if (!str)
		return (NULL);
	size = count_size(str, set);
	new = malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	if (!size)
	{
		*new = '\0';
		return (new);
	}
	start = 0;
	while (ft_in_charset(str[start], set))
		start++;
	i = -1;
	while (++i < size)
		new[i] = str[start + i];
	new[i] = '\0';
	return (new);
}
