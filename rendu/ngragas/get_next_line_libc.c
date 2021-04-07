/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:59:26 by ngragas           #+#    #+#             */
/*   Updated: 2021/04/07 13:51:25 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_libc.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*cur;

	if (!(substr = malloc(++len + 2)))
		return (NULL);
	cur = substr;
	s += start;
	while (--len)
		*cur++ = *s++;
	*cur = '\0';
	return (substr);
}

static int	gnl_terminate(int return_value, char **line, t_buf *buf)
{
	if (return_value == -1)
		*line = NULL;
	else if (!(*line = ft_substr(buf->cur, 0, buf->max)))
		return_value = -1;
	free(buf->s);
	*buf = (t_buf){NULL, NULL, 0, 0};
	return (return_value);
}

static int	gnl_buf_realloc(t_buf *buf)
{
	char	*newbuf;

	if (buf->max + BUFFER_SIZE > buf->cap)
	{
		buf->cap *= 4;
		if (!(newbuf = malloc(buf->cap)))
			return (0);
		memcpy(newbuf, buf->cur, buf->max);
		free(buf->s);
		buf->s = newbuf;
	}
	else
		memcpy(buf->s, buf->cur, buf->max);
	buf->cur = buf->s;
	return (1);
}

static int	gnl_fetch_fd(char **line, t_buf *buf, unsigned *len)
{
	ssize_t	bytes_read;
	char	*newline;

	while (1)
	{
		if (buf->cur + buf->max + BUFFER_SIZE - buf->s > buf->cap)
			if (!(gnl_buf_realloc(buf)))
				return (gnl_terminate(-1, line, buf));
		bytes_read = read(STDIN_FILENO, buf->cur + buf->max, BUFFER_SIZE);
		if (bytes_read < 1)
			return (gnl_terminate(bytes_read, line, buf));
		newline = memchr(buf->cur + buf->max, '\n', bytes_read);
		if (newline)
		{
			*len = newline - buf->cur;
			if (!(*line = ft_substr(buf->cur, 0, newline - buf->cur)))
				return (gnl_terminate(-1, line, buf));
			buf->max += buf->cur + bytes_read - newline - 1;
			buf->cur = newline + 1;
			return (1);
		}
		buf->max += bytes_read;
	}
}

int			get_next_line(char **line, unsigned *len)
{
	static t_buf	buf;
	char			*newline;

	if (!buf.s)
	{
		buf.cap = BIG_BUF;
		buf.s = malloc(buf.cap);
		if (!buf.s)
			return (gnl_terminate(-1, line, &buf));
		buf.cur = buf.s;
		buf.max = 0;
	}
	else if ((newline = memchr(buf.cur, '\n', buf.max)))
	{
		*len = newline - buf.cur;
		if (!(*line = ft_substr(buf.cur, 0, newline - buf.cur)))
			return (gnl_terminate(-1, line, &buf));
		buf.max -= newline - buf.cur + 1;
		buf.cur = newline + 1;
		return (1);
	}
	return (gnl_fetch_fd(line, &buf, len));
}
