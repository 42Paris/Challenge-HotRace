/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 15:55:21 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 11:34:36 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (c == '\0')
		return (1);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			count++;
			while ((s[i]) && (s[i] != c))
				i++;
		}
	}
	return (count);
}

static int	ft_wordlength(const char *s, char c)
{
	int	i;

	i = 0;
	while ((s[i]) && (s[i] != c))
		i++;
	return (i);
}

static void	*ft_free_array(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	*ft_mallocword(const char *s, char c)
{
	int		i;
	char	*word;
	int		length;

	i = 0;
	length = 0;
	while ((s[i]) && (s[i] != c))
		i++;
	length = i;
	i = 0;
	word = (char *)malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);
	while ((s[i]) && length > 0)
	{
		word[i] = s[i];
		i++;
		length--;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		n;
	char	**arr;

	if (s == 0)
		return (0);
	i = 0;
	n = 0;
	arr = (char **)ft_calloc(sizeof(char *), (ft_countwords(s, c) + 1));
	if (arr == NULL || s == 0)
		return (NULL);
	while (s[i] && ft_countwords(s, c) > n)
	{
		if ((s[i] != c) && (ft_countwords(s, c) > n))
		{
			arr[n] = ft_mallocword(s + i, c);
			if (arr[n] == NULL)
				return (ft_free_array(arr));
			i = i + ft_wordlength(s + i, c);
			n++;
		}
		while (s[i] == c)
			i++;
	}
	return (arr);
}
