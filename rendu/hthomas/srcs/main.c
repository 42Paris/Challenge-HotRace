/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/07 13:08:39 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static	unsigned int	hash(char *key, size_t size_database)
{
	unsigned int	h;
	size_t			i;

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

char	type_entry(char *line, t_data *data)
{
	data->key = line;
	if (line[0] == '!')
	{
		data->key++;
		data->length_key = ft_strlen(data->key);
		data->value = NULL;
		return (DELETE);
	}
	else if (in_charset('=', line, &(data->length_key)))
	{
		data->key[data->length_key] = '\0';
		data->value = &line[data->length_key + 1];
		return (ENTRY);
	}
	data->length_key = ft_strlen(data->key);
	return (SEARCH);
}

t_data	*get_data(const t_list *table)
{
	return ((t_data *)(table->content));
}

bool	is_in_table(t_list **table, char *key)
{
	t_list	*tmp;
	t_list	*start;

	start = table[hash(key, SIZE_DATABASE)];
	if (start)
	{
		tmp = start;
		while (tmp)
		{
			if (!ft_strcmp(key, get_data(tmp)->key))
				return (true);
			tmp = tmp->next;
		}
	}
	return (false);
}

void	add_to_table(t_list **table, t_data *data)
{
	ft_lstadd_back(&(table[hash(data->key, SIZE_DATABASE)]), ft_lstnew(data));
}

char	*find_value(t_list **table, char *key)
{
	t_list		*tmp;
	t_list		*start;
	unsigned int	h;

	h = hash(key, SIZE_DATABASE);
	if (table[h])
	{
		tmp = table[h];
		while (tmp)
		{
			if (!ft_strcmp(key, get_data(tmp)->key))
				return (get_data(tmp)->value);
			tmp = tmp->next;
		}
	}
	return (ft_strdup("Not found"));
}

void	remove_from_table(t_list ***table, char *key)
{
	t_list		*tmp;
	t_list		*start;
	int	h;

	h = hash(key, SIZE_DATABASE);
	if ((*table)[h])
	{
		tmp = (*table)[h];
		while (tmp)
		{
			if (!ft_strcmp(key, get_data(tmp)->key))
			{
				free(ft_lstremove_one(&((*table)[h]), tmp));
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
	t_list	**table;
	t_list	*outputs;

	if (argc != 1)
		return (0);
	(void) argv;
	table = malloc(sizeof(*table) * SIZE_DATABASE);
	outputs = NULL;
	while (get_next_line(&line, 0))
	{
		data = malloc(sizeof(*data));
		char type = type_entry(line, data);
		if (type == ENTRY)
		{
			if (!is_in_table(table, data->key))
				add_to_table(table, data);
		}
		else if (type == SEARCH)
		{
			char	*output;
			data->value = find_value(table, data->key);
			output = ft_strjoin(data->key, ": ");
			output = ft_strjoin_free(output, data->value);
			ft_lstadd_back(&outputs, ft_lstnew(output));
		}
		else if (type == DELETE)
			remove_from_table(&table, data->key);
		else
			free(line);
		// free(key);
		// free(value);
	}
	print_clean_list(outputs);
	free(line);
	return (0);
}
