/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/07 22:13:07 by hthomas          ###   ########.fr       */
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

char const	type_entry(char *line, size_t *length_key)
{
	if (line[0] == '!')
		return (DELETE);
	else if (contains_equal('=', line, length_key))
		return (ENTRY);
	else
		return (SEARCH);
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
				// printf("%s\n", get_data(tmp)->value);
				return ;
			}
			tmp = tmp->next;
		}
	}
	// printf("%s%s\n", key, ": Not found");
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
	char	*line;
	t_list	**table;

	if (argc != 1)
		return (0);
	(void) argv;
	table = malloc(sizeof(*table) * SIZE_DATABASE);
	int	i = 0;
	while (i < SIZE_DATABASE)
		table[i++] = 0;
	// printf("table: %p\n", table);
	while (get_next_line(&line, 0))
	{
		size_t	length_key;
		char	type;
		t_data	*data;

		type = type_entry(line, &length_key);
		if (type == ENTRY)
		{
			char *tmp_key = strndup(line, length_key);
			if (!is_in_table(table, tmp_key))
			{
				set_data(&data, line, length_key);
				add_to_table(table, data);
				free(tmp_key);
				continue ;
			}
			free(tmp_key);
		}
		else if (type == SEARCH)
			find_value(table, line);
		else if (type == DELETE)
			remove_from_table(&table, &line[1]);
		free(line);
	}
	if (line)
		free(line);
	i = 0;
	while (i < SIZE_DATABASE)
	{
		if (table[i])
		{
			// printf("table[i]: %p\n", table[i]);
			ft_lstclear(&(table[i]), &free_data);
		}
		i++;
	}
	free(table);
	return (0);
}
