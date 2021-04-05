/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:29:33 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:42:35 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	free_tab(char **tab, int d1)
{
	while (--d1 + 1)
		free(tab[d1]);
	free(tab);
	return (0);
}

static int	*count_lengths(int *words_len, const char *s, char c)
{
	int	i_length;
	int	i_s;

	i_length = 0;
	i_s = 0;
	while (s[i_s])
	{
		while (s[i_s])
		{
			if (s[i_s] != c)
				break ;
			i_s++;
		}
		while (s[i_s])
		{
			if (s[i_s] == c)
				break ;
			i_s++;
			words_len[i_length]++;
		}
		i_length++;
	}
	return (words_len);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	i_s;

	count = 0;
	i_s = 0;
	while (s[i_s])
	{
		while (s[i_s])
		{
			if (s[i_s] != c)
			{
				count++;
				break ;
			}
			i_s++;
		}
		while (s[i_s])
		{
			if (s[i_s++] == c)
				break ;
		}
	}
	return (count);
}

static int	fill_tab(char ***tab, int *words_len, const char *s, char c)
{
	int		d1;
	int		d2;
	int		i_s;
	int		words_count;

	d1 = 0;
	i_s = 0;
	words_count = count_words(s, c);
	while (d1 < words_count && s[i_s])
	{
		(*tab)[d1] = malloc((words_len[d1] + 1) * sizeof(char));
		if (!(*tab)[d1])
			return (free_tab(*tab, d1));
		while (s[i_s] == c)
			i_s++;
		d2 = 0;
		while (s[i_s] && s[i_s] != c)
			(*tab)[d1][d2++] = s[i_s++];
		(*tab)[d1++][d2] = '\0';
	}
	(*tab)[d1] = 0;
	return (1);
}

/*
** split str into a char ** each time there is c
** @param str	"sentence" that will be splited
** @param c		"delimiter" that will delimits the "words"
** @return		a tab of "words"
*/

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		words_count;
	int		*words_len;
	int		allgood;
	int		i;

	if (!s)
		return (NULL);
	words_len = malloc((count_words(s, c)) * sizeof(int));
	if (!words_len)
		return (NULL);
	words_count = count_words(s, c);
	tab = malloc((words_count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < words_count)
		words_len[i++] = 0;
	count_lengths(words_len, s, c);
	allgood = fill_tab(&tab, words_len, s, c);
	free(words_len);
	if (allgood)
		return (tab);
	return (NULL);
}
