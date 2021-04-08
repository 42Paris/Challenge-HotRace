/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolomer <gcolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:18:21 by gcolomer          #+#    #+#             */
/*   Updated: 2021/04/08 11:18:21 by gcolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab.h"
#include "hash.h"
#include <stdlib.h>

void	clean(t_data **data, int len)
{
	len--;
	while (len >= 0)
	{
		if (data[len] != NULL)
		{
			free(data[len]->key);
			free(data[len]->value);
		}
		free(data[len]);
		len--;
	}
}

t_data	**new_tab(t_data **old, int *len)
{
	t_data **tab;
	int i;
	int j;
	int leno;


	leno = *len;
	i = 0;
	j = 0;
	tab = create_tab(len);
	while (i < leno)
	{
		if (old[i] != NULL)
		{
			j = old[i]->hashc % *len;
			while (tab[j] != NULL)
				j++;
			tab[j] = old[i];
		}
		i++;
	}
	return (tab);
}

t_data	**create_tab(int *len)
{
	static int	pow = 2048;
	t_data	**tab;

	if (*len == 2048)
		pow *= pow;
	tab = calloc(pow, sizeof(t_data));
	if (tab == NULL)
		return (NULL);
	*len = pow;
	return (tab);
}
