/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolomer <gcolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:18:56 by gcolomer          #+#    #+#             */
/*   Updated: 2021/04/05 15:18:56 by gcolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "stdlib.h"
#include <string.h>

int		hash_func(char *key)
{
	t_cook			hash;
	t_num			n;
	unsigned int	res;
	int				i;
	int				len;

	n.a = 24;
	n.b = 9043;
	n.c = 1565;
	i = 0;
	res = 0;
	len = strlen(key);
	while (i < len)
	{
		bzero(hash.temp, 8);
		if (len < 8)
			strlcpy(hash.temp, key, len);
		else
			strlcpy(hash.temp, &key[i], 8);
		res ^= (hash.content[0] * n.a + hash.content[1] * n.b + n.c);
		if (strlen(&key[i]) < 8)
			i += strlen(&key[i]);
		else
			i += 8;
	}
	return (res);
}

int		comp_hash(t_data **tab, char *key, int len)
{
	int				i;
	char			cmp[9];

	strlcpy(cmp, key, 9);
	i = hash_func(key) % len;
	while (i < len)
	{
		if (tab[i] != NULL)
		{
			if (strcmp(tab[i]->hash, cmp) == 0)
			{
				if (strcmp(tab[i]->key, key) == 0)
					return (i);
			}
			i++;
		}
		else
			i++;
	}
	return (-1);
}
