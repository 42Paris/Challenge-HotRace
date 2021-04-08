/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:17:57 by ashishae          #+#    #+#             */
/*   Updated: 2021/04/08 12:47:41 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

int find(char const *s, char c)
{
	size_t i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return i;
		i++;
	}
	return -1;
}

int main(void)
{
	char *line = NULL;
	int read = 0;
	size_t read2 = 0;

	hashmap *h = calloc(TABLE_SIZE, sizeof(hashmap_node *));

	while ((read = getline(&line, &read2, stdin)) != -1)
	{
		line[read-1]='\0';
		if (line[0] == '!')
		{
			hm_remove(h, line + 1);
			free(line);
			line = NULL;
			continue;
		}
		int eq = find(line, '=');
		if (eq == -1)
		{
			hm_print(h, line);
			free(line);
			line = NULL;
			continue;
		}
		else
		{
			hm_put(h, line, eq);
			line = NULL;
			continue;
		}
	}

	return (0);
}