/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:00:24 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/08 09:30:39 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

int	contains_equal(char const c, char const *charset, size_t *pos)
{
	*pos = 0;
	while (charset[*pos])
	{
		if (c == charset[*pos])
			return (1);
		(*pos)++;
	}
	return (0);
}

void	set_data(t_data **data, char *line, size_t length_key)
{
	*data = malloc(sizeof(**data));
	(*data)->key = line;
	(*data)->key[length_key] = '\0';
	(*data)->value = &line[length_key + 1];
}

void	free_data(void *content)
{
	t_data	*data = content;
	if (data->key)
		free(data->key);
	free(data);
}

t_list	**init_table(void)
{
	t_list	**table;

	table = malloc(sizeof(*table) * SIZE_DATABASE);
	int	i = 0;
	while (i < SIZE_DATABASE)
		table[i++] = 0;
	return (table);
}

void 	free_table(t_list **table)
{
	int i = 0;
	while (i < SIZE_DATABASE)
	{
		if (table[i])
			ft_lstclear(&(table[i]), &free_data);
		i++;
	}
	free(table);
}
