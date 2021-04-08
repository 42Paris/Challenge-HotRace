/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolomer <gcolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:15:32 by gcolomer          #+#    #+#             */
/*   Updated: 2021/04/06 12:15:32 by gcolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include <stdlib.h>
#include <string.h>

t_data	*init_struct(char *line)
{
	int		i;
	int		j;
	t_data	*slot;

	i = 0;
	slot = NULL;
	while (line[i] != '=' && line[i])
		i++;
	if (i == 0 || line[i] != '=')
		return (slot);
	slot = malloc(sizeof(t_data));
	slot->key = malloc((i + 1) * sizeof(char));
	strlcpy(slot->key, line, i + 1);
	i++;
	j = strlen(&line[i]);
	if (line[j + i - 1] == '\n')
		j--;
	if (j != 0)
		slot->value = malloc((j + 1) * sizeof(char));
	strlcpy(slot->value, &line[i], j + 1);
	strlcpy(slot->hash, line, i);
	slot->hashc = 0;
	return (slot);
}
