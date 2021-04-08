/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:04:15 by abaudot           #+#    #+#             */
/*   Updated: 2021/04/07 10:50:12 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

uint8_t		initilize_reader(t_reader *reader, uint32_t n)
{
	if (!(reader->s = (char *)malloc(n + 1)))
		return (0);
	*reader->s = 0;
	reader->len = 0;
	reader->size = n;
	return (1);
}

static uint8_t		update_reader(t_reader *str, const char *src, int32_t n)
{
//	char		*tmp;
	const uint32_t	wanted = n + str->len;

	if (str->size < wanted)
	{
		while (str->size < wanted)
			str->size <<= 1;
		/*
		tmp = str->s;
		if (!(str->s = (char *)malloc(str->size + 1)))
		{
			free(tmp);
			return (0);
		}
		ft_memcpy(str->s, tmp, str->len);
		free(tmp);
		*/
		str->s = realloc(str->s, str->size + 1);
	}
	//ft_memcpy(str->s + str->len, src, n);
	memcpy(str->s + str->len, src, n);
	str->len = wanted;
	str->s[str->len] = 0;
	return (1);
}

static int32_t		get_nl(const char *s, size_t n)
{
	/*
	uint64_t	long_word;
	uint32_t	i;

	i = 0;
	while (i + 0xf < n)
	{
		long_word = *(uint64_t *)(s + i) ^ NL;
		if ((long_word - LOMAGIC) & ~long_word & HIMAGIC)
			break ;
		i += 8;
	}
	while (i < n)
	{
		if (s[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
	*/
	const char *p = memchr(s, '\n', n);
	
	if (!p)
		return (-1);
	return (p - s);
}

static int32_t		read_line(int32_t fd, t_reader *str, char *sheet, 
		int32_t *sheet_len)
{
	int32_t	a_nl;

	while ((*sheet_len = read(fd, sheet, BUFFER_SIZE)) > 0)
	{
		sheet[*sheet_len] = 0;
		if ((a_nl = get_nl(sheet, *sheet_len)) != -1)
		{
			if (!(update_reader(str, sheet, a_nl)))
				return (-1);
			*sheet_len -= a_nl;
			memcpy(sheet, sheet + a_nl + 1, *sheet_len);
			return (1);
		}
		if (!(update_reader(str, sheet, *sheet_len)))
			return (-1);
	}
//	str->s = 0;
	*sheet = 0;
	return (-(*sheet_len == -1));
}

int32_t				getNextLine(int32_t fd, t_reader *my_line)
{
	static char		sheets[BUFFER_SIZE + 1];
	static int32_t	sheet_len;
	int32_t			a_nl;

	if (sheets[0] == 0)
		return (read_line(fd, my_line, sheets, &sheet_len));
	--sheet_len;
	if ((a_nl = get_nl(sheets, sheet_len)) != -1)
	{
		if (!(update_reader(my_line, sheets, a_nl)))
			return (-1);
		memcpy(sheets, sheets + a_nl + 1, sheet_len - a_nl);
		return (1);
	}
	if (!(update_reader(my_line, sheets, sheet_len)))
		return (-1);
	return (read_line(fd, my_line, sheets, &sheet_len));
}
