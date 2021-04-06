/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/06 15:03:19 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static uint64_t	hash(char *key, size_t size_database)
{
	uint64_t    value;
    size_t      i;

    i = 0;
	value = 17;
	size_t len = ft_strlen(key);
	while (i < len)
	{
		value = (value * key[i] * 31) % size_database;
		i++;
	}
	return (value);
}


char type_entry(char *line, t_data *data)
{
	data->key = line;
	if (line[0] == '!')
	{
		data->key++;
		data->length_key = ft_strlen(data->key);
		data->value = NULL;
		return (DELETE);
	}
	if (in_charset('=', line, &(data->length_key)))
	{
		data->key[data->length_key] = '\0';
		data->value = &line[data->length_key + 1];
		return (ENTRY);
	}
	return (SEARCH);
}

t_data	*get_data(const t_list *table)
{
	return ((t_data *)(table->content));
}


bool	is_in_dict(t_list **table, char *key)
{
	t_list	*tmp;

	if ((tmp = table[hash(key, SIZE_DATABASE)]))
	{
		while (tmp != *table)
		{
			if (!ft_strcmp(key, get_data(*table)->key))
				return (true);
			tmp = tmp->next;
		}
	}
	return (false);
}

void	add_to_dict(t_list **table, t_data *data)
{
	printf("hash:%llu\n", hash(data->key, SIZE_DATABASE));
	ft_lstadd_front(&table[hash(data->key, SIZE_DATABASE)], ft_lstnew(data));
}

char	*find_value(t_list **table, char *key)
{
	t_list	*tmp;
	int		h;

	h = hash(key, SIZE_DATABASE);
	// printf("find_value: %s\n", key);
	if ((tmp = table[h]))
	{
		if (!ft_strcmp(key, get_data(table[h])->key))
			return (get_data(table[h])->value);
		while (tmp != table[h])
		{
			if (!ft_strcmp(key, get_data(table[h])->key))
				return (get_data(table[h])->value);
			tmp = tmp->next;
		}
	}
	return (ft_strdup("Not found"));
}

int		main(int argc, char const *argv[])
{
	char	*line;
	t_data	data;
	t_list	**table;
	t_list	*outputs;

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
		char type = type_entry(line, &data);
		if (type == ENTRY)
		{
			// printf("main:%s: %s\n", data.key, data.value);
			if (!is_in_dict(table, data.key))
				add_to_dict(table, &data);
		}
		else if (type == SEARCH)
		{
			char	*output;
			if ((data.value = find_value(table, data.key)))
			{
				output = ft_strjoin(data.key, ": ");
				output = ft_strjoin_free(output, data.value);
			}
			else
			{
				output = ft_strjoin(data.key, ": ");
				output = ft_strjoin_free(output, "Not found");
			}
			ft_lstadd_back(&outputs, ft_lstnew(output));
		}
		else if (type == DELETE)
		{
			/* code */
		}
		else
			free(line);
		// free(key);
		// free(value);
	}
	print_clean_dlist(outputs);
	free(line);
	return (0);
}
