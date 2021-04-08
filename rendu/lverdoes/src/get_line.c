/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_line.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 21:31:23 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 23:27:29 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static inline char	*append(char *s1, const char *s2)
{
	char	*dst;
	size_t	len;

	if (!s1)
	{
		s1 = strdup("\0");
		if (!s1)
			return (NULL);
	}
	if (!s2)
		return (s1);
	len = strlen(s1) + strlen(s2);
	dst = calloc(len + 1, sizeof(char));
	if (!dst)
	{
		free(s1);
		return (NULL);
	}
	strlcat(dst, s1, len + 1);
	strlcat(dst, s2, len + 1);
	free(s1);
	return (dst);
}

inline int	get_line(char **line)
{
	int		ret;
	char	buffer[BUFFER_SIZE + 1];
	char	*ptr;

	while (1)
	{
		ret = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (ret <= 0)
			return (-1);
		ptr = strchr(buffer, '\n');
		if (ptr)
		{
			*ptr = '\0';
			*line = append(*line, buffer);
			if (!*line)
				return (-1);
			return (1);
		}
		buffer[ret] = '\0';
		*line = append(*line, buffer);
		if (!*line)
			return (-1);
	}
	return (1);
}
