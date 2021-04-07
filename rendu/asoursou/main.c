/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:35:15 by asoursou          #+#    #+#             */
/*   Updated: 2021/04/07 20:09:11 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "hotrace.h"

static bool add(t_dict *d, t_str *key, char *eq)
{
	t_str v;

	str_init(&v, eq + 1, key->s + key->n - eq - 1);
	key->n -= v.n + 1;
	*eq = '\0'; // comes from line buffer
	if (!key->n)
		return (1);
	return (dict_add(d, key, &v));
}

static void erase(t_dict *d, t_str *k)
{
	if (k->n < 1)
		return ;
	++k->s;
	dict_erase(d, k);
}

static void find(t_dict *d, t_str *k)
{
	const t_str *v;

	if (!k->n)
		return ;
	v = dict_find(d, k);
	if (v)
		puts(v->s);
	else
		printf("%s: Not found\n", k->s);
}

static bool parse(t_dict *d, const char *line, size_t n)
{
	t_str	s;
	char	*eq;

	str_init(&s, line, n);
	if (*s.s == '!')
		erase(d, &s);
	else
	{
		eq = memchr(s.s, '=', n);
		if (eq)
			return (add(d, &s, eq));
		else
			find(d, &s);
	}
	return (1);
}

int main()
{
	t_dict	dict = { NULL };
	char	*line = NULL;
	size_t	alloc_size = 1024;
	ssize_t	n;

	while ((n = getline(&line, &alloc_size, stdin)) > 0 && !feof(stdin))
	{
		line[--n] = '\0';
		if (!parse(&dict, line, n))
			break ;
	}
	free(line);
	return (0);
}
