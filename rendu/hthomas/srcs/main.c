/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/08 13:48:57 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

char	*g_last_value = NULL;
char	*g_last_key = NULL;

static unsigned int	hash(char const *key, size_t const size_database, ssize_t const len)
{
	unsigned int	h;
	ssize_t			i;

	i = 0;
	h = PRIME_1;
	while (i < len)
	{
		h = (h * PRIME_2 + key[i]) % size_database;
		i++;
	}
	return (h);
}

char	type_entry(char *line, size_t *length_key)
{
	if (line[0] == '!')
		return (DELETE);
	else if (contains_equal('=', line, length_key))
		return (ENTRY);
	else
		return (SEARCH);
}

t_data const	*get_data(t_list const *table)
{
	return ((t_data *)(table->content));
}

bool	is_in_table(t_list **table, char const *key, ssize_t const len)
{
	t_list	*tmp;
	t_list	*start;

	start = table[hash(key, SIZE_DATABASE, len)];
	if (start)
	{
		tmp = start;
		while (tmp)
		{
			if (!strcmp(key, get_data(tmp)->key))
				return (true);
			tmp = tmp->next;
		}
	}
	return (false);
}

void	add_to_table(t_list **table, t_data *data, ssize_t const len)
{
	ft_lstadd_back(&(table[hash(data->key, SIZE_DATABASE, len)]), ft_lstnew(data));
}

void	find_value(t_list **table, char const *key, ssize_t const len)
{
	t_list		*tmp;
	unsigned int	h;

	if (g_last_key && key && !strcmp(g_last_key, key))
	{
		printf("%s\n", g_last_value);
		return ;
	}
	h = hash(key, SIZE_DATABASE, len);
	if (table[h])
	{
		tmp = table[h];
		while (tmp)
		{
			if (!strcmp(key, get_data(tmp)->key))
			{
				g_last_key = key;
				g_last_value = get_data(tmp)->value;
				printf("%s\n", g_last_value);
				return ;
			}
			tmp = tmp->next;
		}
	}
	printf("%s%s\n", key, ": Not found");
}

void	remove_from_table(t_list ***table, char *key, ssize_t const len)
{
	t_list			*tmp;
	unsigned int	h;

	g_last_key = NULL;
	h = hash(key, SIZE_DATABASE, len);
	if ((*table)[h])
	{
		tmp = (*table)[h];
		while (tmp)
		{
			if (!strcmp(key, get_data(tmp)->key))
			{
				t_list *to_del = ft_lstremove_one(&((*table)[h]), tmp);
				free_data(to_del->content);
				free(to_del);
				return ;
			}
			tmp = tmp->next;
		}
	}
}

int		main(int argc, char const *argv[])
{
	t_list	**table;

	if (argc != 1)
		return (0);
	(void) argv;
	table = init_table();

	char *line;
	ssize_t ret;
	while (!(line = NULL) && (ret = getline(&line, (size_t *)&ret, stdin)) >= 0)
	{
		size_t	length_key;
		char	type;
		t_data	*data;
		ret--;
		line[ret] = 0;
		type = type_entry(line, &length_key);
		if (type == ENTRY)
		{
			char *tmp_key = strndup(line, length_key);
			if (!is_in_table(table, tmp_key, length_key))
			{
				set_data(&data, line, length_key);
				add_to_table(table, data, length_key);
				free(tmp_key);
				continue ;
			}
			free(tmp_key);
		}
		else if (type == SEARCH)
			find_value(table, line, ret);
		else if (type == DELETE)
			remove_from_table(&table, &line[1], ret - 1);
	}
	if (line)
		free(line);
	free_table(table);
	return (0);
}
