/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolomer <gcolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:16:50 by gcolomer          #+#    #+#             */
/*   Updated: 2021/04/05 15:16:50 by gcolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "struct.h"
#include "slot.h"
#include "tab.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	t_data	**tab;
	t_var	var;
	char	*line;
	int		len;
	size_t	buf;

	var.nbo = 0;
	var.colision = 0;
	tab = create_tab(&len);
	line = NULL;
	buf = 0;
	while ((var.nbo = getline(&line, &buf, stdin)) >= 0)
	{
		if (strchr((const char *)line, '=') != NULL)
		{
			var.colision += add(tab, init_struct(line), len);
		}
		else if (line[0] == '!')
		{
			remove_data(tab, line, len, var.nbo);
		}
		else
		{
			search(tab, line, len, var.nbo);
		}
		if (var.colision >= len / 2)
		{
			tab = new_tab(tab, &len);
		}
	}
	free(line);
	clean(tab, len);
}
