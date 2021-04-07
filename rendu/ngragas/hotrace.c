/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:01:14 by ngragas           #+#    #+#             */
/*   Updated: 2021/04/07 19:52:43 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "get_next_line_libc.h"

t_dict		*g_table[TABLE_SIZE];
t_output	g_res;

int		main(int ac, char **av)
{
	int			gnl_return;
	char		*line;
	unsigned	len;
	char		*eq_pos;

//	return (generate_testdata_plain());
	(void)av;
	if (ac != 1)
		return (EXIT_FAILURE);
	while ((gnl_return = get_next_line(&line, &len)) >= 0)
	{
		if (line[0] == '\0' && gnl_return == 0)
		{
			free(line);
			break;
		}
		else if (line[0] == '!')
		{
			key_remove(line + 1, len - 1);
			free(line);
		}
		else if ((eq_pos = memchr(line, '=', len)))
			key_add(line, eq_pos, len);
		else
		{
			key_print(line, len);
			free(line);
		}
		if (gnl_return == 0)
			break ;
	}
//	generate_removedata_plain(false);
//	generate_printdata_plain(false);
	write(STDOUT_FILENO, g_res.str, g_res.len); // !!!
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

void	key_add(char *kv_str, char *eq_pos, unsigned int kv_len)
{
	const unsigned	key_len = eq_pos - kv_str;
	const unsigned	hash = hash_get(kv_str, key_len) % TABLE_SIZE;
	t_dict			*new;
	t_dict			*table;

	*eq_pos = '\0';
	kv_str[kv_len] = '\n';
	kv_str[kv_len + 1] = '\0';
	table = g_table[hash];
	if (table)
		while (true)
		{
			if (memcmp(table->key, kv_str, key_len + 1) == 0)
				return ;
			if (table->next == NULL)
				break ;
			table = table->next;
		}
	if (!(new = malloc(sizeof(t_dict))))
		exit(EXIT_FAILURE);
	*new = (t_dict){kv_str, eq_pos + 1, key_len, kv_len - key_len, NULL};
	if (table)
		table->next = new;
	else
		g_table[hash] = new;
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

void	key_print(const char *key, size_t key_len)
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
			bufcpy(key, key_len);
			bufcpy(notfound, 12);
//		}
//		else
//		{
//			write(1, key, key_len);
//			write(1, g_notfound, 12);
//		}
	}
	else
		bufcpy(table->value, table->value_len_with_n);
//		write(1, table->value, table->value_len_with_n);
}

void	bufcpy(const char *str, unsigned n)
{
	if (g_res.len + n > sizeof(g_res.str))
	{
		write(STDOUT_FILENO, g_res.str, g_res.len); // !!!
		g_res.len = 0;
		if (n > sizeof(g_res.str))
		{
			write(STDOUT_FILENO, str, n); // !!!
			return ;
		}
	}
	memcpy(g_res.str + g_res.len, str, n);
	g_res.len += n;
}