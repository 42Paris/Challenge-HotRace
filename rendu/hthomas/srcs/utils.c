/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:00:24 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/07 22:54:16 by hthomas          ###   ########.fr       */
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
