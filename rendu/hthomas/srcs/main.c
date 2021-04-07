/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/07 17:34:32 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static const unsigned int	hash(char const *key, size_t const size_database)
{
	unsigned int	h;
	size_t			i;

	i = 0;
	h = PRIME_1;
	size_t len = strlen(key);
	while (i < len)
	{
		h = (h * PRIME_2 + key[i]) % size_database;
		i++;
	}
	return (h);
}

char const	type_entry(char *line, t_data *data)
{
	size_t	length_key;

	if (line[0] == '!')
	{
		data->key = &line[1];
		data->value = NULL;
		return (DELETE);
	}
	else if (in_charset('=', line, &length_key))
	{
		data->key = line;
		data->key[length_key] = '\0';
		data->value = &line[length_key + 1];
		return (ENTRY);
	}
	else
	{
		data->key = line;
		return (SEARCH);
	}
}

t_data	*get_data(t_list const *table)
{
	return ((t_data *)(table->content));
}

bool const	is_in_table(t_list **table, char const *key)
{
	t_list	*tmp;
	t_list	*start;

	start = table[hash(key, SIZE_DATABASE)];
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

void	add_to_table(t_list **table, t_data *data)
{
	ft_lstadd_back(&(table[hash(data->key, SIZE_DATABASE)]), ft_lstnew(data));
}

void	find_value(t_list **table, char const *key)
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
			if (!strcmp(key, get_data(tmp)->key))
			{
				printf("%s\n", get_data(tmp)->value);
				return ;
			}
			tmp = tmp->next;
		}
	}
	printf("%s%s\n", key, ": Not found");
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
			if (!strcmp(key, get_data(tmp)->key))
			{
				free(ft_lstremove_one(&((*table)[h]), tmp));
				return ;
			}
			tmp = tmp->next;
		}
	}
}

void	free_data(void *content)
{
	t_data	*data = content;
	if (data->key)
		free(data->key);
	// if (data->value)
	// 	free(data->value);
	free(data);
}

int		main(int argc, char const *argv[])
{
	char	*line;
	t_data	*data;
	t_list	**table;
	// t_list	*outputs;

	if (argc != 1)
		return (0);
	(void) argv;
	table = malloc(sizeof(*table) * SIZE_DATABASE);
	// outputs = NULL;
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
			find_value(table, data->key);
			// char	*output;
			// data->value = find_value(table, data->key);
			// output = strjoin(data->key, ": ");
			// output = strjoin_free(output, data->value);
			// ft_lstadd_back(&outputs, ft_lstnew(output));
			// free(data->value);
		}
		else if (type == DELETE)
			remove_from_table(&table, data->key);
		else
		{
			free(data);
			free(line);
		}
		// free(key);
		// free(value);
	}
	// print_clean_list(outputs);
	int	i = 0;
	while (i < SIZE_DATABASE)
	{
		if (table[i])
			ft_lstclear(&(table[i]), &free_data);
		i++;
	}
	// ft_lstclear(&outputs, free);
	free(table);
	return (0);
}
