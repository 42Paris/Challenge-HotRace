/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotRace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:14:40 by abaudot           #+#    #+#             */
/*   Updated: 2021/04/08 10:43:28 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotRace.h"

static inline void	buildEntry(t_str* entry, const char *r, uint32_t len,
		uint32_t key)
{
	entry->s = malloc(len);
	memcpy(entry->s, r, len);
	entry->key = key;
	entry->len = len;
}

static inline void message(const t_str *out, const t_str *entry)
{
	if (out)
		printf("%.*s\n", out->len - out->key - 1, out->s + out->key + 1);
	else
		printf("%.*s: Not found\n", entry->key, entry->s);
}

int main(void)
{
	t_str		entry;
	t_str		*out;
	char		*reader = NULL;
	char		*tmp = NULL;
	size_t		len;
	ssize_t		av_read;
	
	struct s_map *hmap = new_(0);
	while ((av_read = getdelim(&reader, &len, '\n', stdin)) != -1)
	{
		--av_read;
		if (reader[0] == '!')
		{
			entry.s = reader + 1; entry.key = av_read - 1;
			del_(hmap, &entry);
		}
		else if ((tmp = memchr(reader, '=', av_read)))
		{
			buildEntry(&entry, reader, av_read, tmp - reader);
			add_(hmap, &entry);
		}
		else
		{
			entry.s = reader; entry.key = av_read;
			out = (t_str*)get_(hmap, &entry);
			message(out, &entry);
		}
	}
	clean_(hmap);
	if (reader)
		free(reader);
	return (0);
}
