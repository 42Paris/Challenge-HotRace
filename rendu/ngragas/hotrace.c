/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:24:22 by ngragas           #+#    #+#             */
/*   Updated: 2021/04/07 23:33:29 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_dict	*g_table[TABLE_SIZE];

int		main(int ac, char **av)
{
	char		*line;
	ssize_t		len;
	char		*eq_pos;
	t_output	buffer;

//	return (generate_testdata_plain());
	(void)av;
	if (ac != 1)
		return (EXIT_FAILURE);
	buffer.len = 0;
	line = NULL;
	len = 0;
	while ((len = getline(&line, (size_t *)&len, stdin)) >= 0)
	{
		len--;
		if (line[0] == '!')
		{
			line[len--] = '\0';
			key_remove(line + 1, len);
			free(line);
		}
		else if ((eq_pos = memchr(line, '=', len)))
			key_add(line, eq_pos, len);
		else
		{
			line[len] = '\0';
			key_print(line, len, &buffer);
			free(line);
		}
		line = NULL;
		len = 0;
	}
//	generate_removedata_plain(false, &buffer);
//	generate_printdata_plain(false, &buffer);
	write(STDOUT_FILENO, buffer.str, buffer.len);
//	table_analyze(false);
	return (EXIT_SUCCESS);
}

static inline size_t	hash_get(const char *key, unsigned int key_len)
{
	size_t	hash;

	hash = 0;
	while (key_len--)
		hash = HASH1 * hash + HASH2 * key[key_len];
	return (hash);
}

void	key_add(const char *kv_str, char *eq_pos, unsigned int kv_len)
{
	const unsigned	key_len = eq_pos - kv_str;
	const unsigned	hash = hash_get(kv_str, key_len) % TABLE_SIZE;
	t_dict			*new;
	t_dict			*table;

	*eq_pos = '\0';
	if (g_table[hash])
	{
		table = g_table[hash];
		while (true)
		{
			if (memcmp(table->key, kv_str, key_len + 1) == 0)
			{
				free((void *)kv_str);
				return ;
			}
			if (table->next == NULL)
				break ;
			table = table->next;
		}
		if (!(new = malloc(sizeof(t_dict))))
			exit(EXIT_FAILURE);
		*new = (t_dict) {kv_str, eq_pos + 1, NULL, kv_len - key_len};
		table->next = new;
	}
	else
	{
		if (!(new = malloc(sizeof(t_dict))))
			exit(EXIT_FAILURE);
		*new = (t_dict) {kv_str, eq_pos + 1, NULL, kv_len - key_len};
		g_table[hash] = new;
	}
}

void	key_remove(const char *key, unsigned int key_len)
{
	const unsigned	hash = hash_get(key, key_len) % TABLE_SIZE;
	t_dict			*table;
	t_dict			*prev;

	table = g_table[hash];
	prev = NULL;
	while (table)
	{
		if (memcmp(table->key, key, key_len + 1) == 0)
		{
			if (prev)
				prev->next = table->next;
			else
				g_table[hash] = table->next;
			free((void *)table->key);
			free(table);
			return ;
		}
		prev = table;
		table = table->next;
	}
}

void	key_print(const char *key, size_t key_len, t_output *buffer)
{
	const unsigned		hash = hash_get(key, key_len) % TABLE_SIZE;
	t_dict				*table;
	static const char	*notfound = ": Not found\n";

	table = g_table[hash];
	while (table && memcmp(table->key, key, key_len + 1) != 0)
		table = table->next;
	if (table == NULL)
	{
//		if (key_len < 1024)
//		{
//			char *notfound_str = malloc(key_len + 12);
//			memcpy(notfound_str, key, key_len);
//			memcpy(notfound_str + key_len, ": Not found\n", 12);
//			write(1, notfound_str, key_len + 12);
//			free(notfound_str);
//		}
//		else
//		{
//			write(1, key, key_len);
//			write(1, g_notfound, 12);
//		}
		if (buffer->len + key_len + 12 > sizeof(buffer->str))
		{
			write(STDOUT_FILENO, buffer->str, buffer->len);
			buffer->len = 0;
			if (key_len > sizeof(buffer->str))
			{
				write(STDOUT_FILENO, key, key_len);
				memcpy(buffer->str + buffer->len, notfound, 12);
				return ;
			}
		}
		memcpy(buffer->str + buffer->len, key, key_len);
		memcpy(buffer->str + buffer->len + key_len, notfound, 12);
		buffer->len += key_len + 12;
	}
	else
//		write(1, table->value, table->value_len_with_n);
	{
		if (buffer->len + table->value_len_with_n > sizeof(buffer->str))
		{
			write(STDOUT_FILENO, buffer->str, buffer->len);
			buffer->len = 0;
			if (table->value_len_with_n > sizeof(buffer->str))
			{
				write(STDOUT_FILENO, table->value, table->value_len_with_n);
				return ;
			}
		}
		memcpy(buffer->str + buffer->len, table->value, table->value_len_with_n);
		buffer->len += table->value_len_with_n;
	}
}
