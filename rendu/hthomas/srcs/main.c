/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/06 18:12:55 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static uint64_t	hash(char *key, size_t size_database)
{
	uint64_t    h;
    size_t      i;

    i = 0;
	h = PRIME_1;
	size_t len = ft_strlen(key);
	while (i < len)
	{
		h = (h * PRIME_2 + key[i]) % size_database;
		i++;
	}
	return (h);
}


char type_entry(char *line, t_data *data)
{
	data->key = line;
	if (line[0] == '!')
	{
		data->key++;
		data->length_key = ft_strlen(data->key);
		data->value = NULL;
		// printf("key = %s\n", data->key);
		return (DELETE);
	}
	if (in_charset('=', line, &(data->length_key)))
	{
		data->key[data->length_key] = '\0';
		data->value = &line[data->length_key + 1];
		// printf("key = %s\n", data->key);
		return (ENTRY);
	}
	// printf("key = %s\n", data->key);
	// data->value = 0; //! todo
	data->length_key = ft_strlen(data->key);
	return (SEARCH);
}

t_data	*get_data(const t_dlist *table)
{
	return ((t_data *)(table->content));
}

bool	is_in_table(t_dlist **table, char *key)
{
	t_dlist	*tmp;
	t_dlist	*start;

	start = table[hash(key, SIZE_DATABASE)];
	if (start)
	{
		if (!ft_strcmp(key, get_data(start)->key))
			return (true);
		tmp = start->next;
		while (tmp != start)
		{
			if (!ft_strcmp(key, get_data(tmp)->key))
				return (true);
			tmp = tmp->next;
		}
	}
	return (false);
}

void	add_to_table(t_dlist **table, t_data *data)
{
	// printf("%s:%llu\n", data->key, hash(data->key, SIZE_DATABASE));
	ft_dlstadd_back(&(table[hash(data->key, SIZE_DATABASE)]), ft_dlstnew(data));
}

char	*find_value(t_dlist **table, char *key)
{
	t_dlist		*tmp;
	t_dlist		*start;
	uint64_t	h;

	h = hash(key, SIZE_DATABASE);
	// printf("find_value: %s\n", key);
	if (table[h])
	{
		// start = table[h];
		t_data *data = get_data(table[h]);
		// printf("key  : %s\nvalue: %s\n", data->key, data->value);
		if (!ft_strcmp(key, data->key))
			return (data->value);
		tmp = table[h]->next;
		while (tmp != table[h])
		{
			data = get_data(tmp);
			if (!ft_strcmp(key, data->key))
				return (data->value);
			tmp = tmp->next;
		}
	}
	return (ft_strdup("Not found"));
}

void	remove_from_table(t_dlist ***table, char *key)
{
	t_dlist		*tmp;
	t_dlist		*start;
	uint64_t	h;

	h = hash(key, SIZE_DATABASE);
	// printf("find_value: %s\n", key);
	if ((*table)[h])
	{
		// start = (*table)[h];
		t_data *data = get_data((*table)[h]);
		// printf("key  : %s\nvalue: %s\n", data->key, data->value);
		if (!ft_strcmp(key, data->key))
		{
			// printf("delete\n");
			free(ft_dlstremove_one(&((*table)[h]), (*table)[h]));
			return ;
		}
		tmp = (*table)[h]->next;
		while (tmp != (*table)[h])
		{
			data = get_data(tmp);
			if (!ft_strcmp(key, data->key))
			{
				free(ft_dlstremove_one(&((*table)[h]), tmp));
				return ;
			}
			tmp = tmp->next;
		}
	}
}

int		main(int argc, char const *argv[])
{
	char	*line;
	t_data	*data;
	t_dlist	**table;
	t_dlist	*outputs;

	if (argc != 1)
		return (0);
	(void) argv;
	table = malloc(sizeof(*table) * SIZE_DATABASE);
	// int i = 0;
	// while (i < SIZE_DATABASE)
	// {
	// 	table[i] = NULL;
	// 	i++;
	// }

	outputs = NULL;
	while (get_next_line(&line, 0))
	{
		data = malloc(sizeof(*data));
		char type = type_entry(line, data);
		// printf("*******************%c %s: %s\n", type, data->key, data->value);
		if (type == ENTRY)
		{
			if (!is_in_table(table, data->key))
				add_to_table(table, data);
		}
		else if (type == SEARCH)
		{
			char	*output;
			data->value = find_value(table, data->key);
			// printf("text %s=%s\n", data->key, data->value);
			output = ft_strjoin(data->key, ": ");
			output = ft_strjoin_free(output, data->value);
			ft_dlstadd_back(&outputs, ft_dlstnew(output));
		}
		else if (type == DELETE)
			remove_from_table(&table, data->key);
		else
			free(line);
		// free(key);
		// free(value);
	}
	print_clean_dlist(outputs);
	free(line);
	return (0);
}
