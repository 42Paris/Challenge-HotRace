/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:40:58 by eparisot          #+#    #+#             */
/*   Updated: 2017/11/29 16:37:02 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		test_chr(char c, char chr)
{
	if (c == chr)
		return (1);
	return (0);
}

static char		*r_str(char *s, int *len, int *w, char chr)
{
	if (s == NULL)
		return (NULL);
	while (s[*len])
	{
		if (s[*len] && test_chr(s[*len], chr) && s[*len - 1] &&
				!test_chr(s[*len - 1], chr))
			(*w)++;
		else if ((s[*len + 1] == '\0') && !test_chr(s[*len], chr))
			(*w)++;
		if (test_chr(s[*len], chr))
			s[*len] = '\0';
		(*len)++;
	}
	return (s);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		len;
	int		w;
	char	*str;
	char	**r;

	if (s == NULL)
		return (NULL);
	len = 0;
	w = 0;
	if ((str = r_str(ft_strdup(s), &len, &w, c)) == NULL)
		return (NULL);
	if ((r = (char **)malloc(sizeof(char *) * (w + 1))) == NULL)
		return (NULL);
	w = 0;
	i = -1;
	while (++i < len)
	{
		if (str[i] && ((i == 0) || !str[i - 1]))
			r[w++] = ft_strdup(&str[i]);
	}
	r[w] = NULL;
	free(str);
	return (r);
}
