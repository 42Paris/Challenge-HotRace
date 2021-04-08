/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readstdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:05:15 by geargenc          #+#    #+#             */
/*   Updated: 2021/04/08 11:30:34 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char				*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char				*ft_strdup(const char *s1)
{
	size_t			i;
	char			*s2;

	i = 0;
	while (s1[i])
		i++;
	if (!(s2 = (char *)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char				*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*sub;

	while (start--)
		s++;
	if (!(sub = (char *)malloc(len + 1)))
		return (NULL);
	sub[len] = '\0';
	while (len--)
		sub[len] = s[len];
	return (sub);
}

char				*ft_strjoinfreefirst(char *s1, char *s2)
{
	char			*join;
	int				i;
	int				j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	if (!(join = (char *)malloc(i + j + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = -1;
	while (s2[++j])
		join[i + j] = s2[j];
	join[i + j] = '\0';
	free(s1);
	return (join);
}

int                 readstdin(char **line)
{
    static char     *content = NULL;
    char            buf[BUFF_SIZE + 1];
    char            *chr;
    int             ret;
    char            *tmp;

    chr = NULL;
    ret = 0;
    while ((content == NULL || (chr = ft_strchr(content, '\n')) == NULL) && (ret = read(STDIN_FILENO, buf, BUFF_SIZE)) > 0)
    {
        buf[ret] = '\0';
        if (content == NULL ? (content = ft_strdup(buf)) == NULL : (content = ft_strjoinfreefirst(content, buf)) == NULL)
            return (-1);
    }
    if (ret < 0)
        return (-1);
    if (chr == NULL ? content != NULL && (*line = ft_strdup(content)) == NULL : (*line = ft_strsub(content, 0, chr - content)) == NULL)
        return (-1);
    if (chr && chr[1])
    {
        tmp = content;
        if ((content = ft_strdup(chr + 1)) == NULL)
            return (-1);
        free(tmp);
        return (1);
    }
    else if (content)
    {
        free(content);
        content = NULL;
        return (1);
    }
    return (0);
}
