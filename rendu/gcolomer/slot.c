/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolomer <gcolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:29:04 by gcolomer          #+#    #+#             */
/*   Updated: 2021/04/05 15:29:04 by gcolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slot.h"
#include "hash.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int		search(t_data **tab, char *line, int len, int nbo)
{
	int i;

	if (line[nbo - 1] == '\n')
		line[nbo - 1] = '\0';
	i = comp_hash(tab, line, len) % len;
	if (i >= 0)
	{
		write(1, tab[i]->value, strlen(tab[i]->value));
		write(1, "\n", 1);
	}
	else
		write(1, "Not found\n", 10);
	return (i);
}

void	remove_data(t_data **tab, char *line, int len, int nbo)
{
	int i;

	if (line[nbo - 1] == '\n')
		line[nbo - 1] = '\0';
	i = comp_hash(tab, &(line[1]), len);
	if (i >= 0)
	{
		free(tab[i]);
		tab[i] = NULL;
	}
}

int		add(t_data **tab, t_data *data, int len)
{
	int	i;
	int j;
	int colision;

	colision = 0;
	j = hash_func(data->key);
	i = j % len;
	while (tab[i] != NULL)
		i++;
	tab[i] = data;
	tab[i]->hashc = j;
	colision++;
	return (colision);
}
