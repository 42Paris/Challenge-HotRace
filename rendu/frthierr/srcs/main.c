/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:59:01 by frthierr          #+#    #+#             */
/*   Updated: 2021/04/08 09:06:50 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include "hash_map.h"
#include <stdio.h>
#include "sigint_catcher.h"
#include <sys/types.h>

#define LINE_BUFFER_SIZE 512

int	main(int argc, char __attribute__((unused))**argv) {
	if (argc > 1) {
		return 1;
	}
	t_hash_map	hash_map;
	signal(SIGINT, sigint_catcher);

	init_hash_map(&hash_map, HASH_MAP_INIT_VALUE);


	char	*line = NULL;
	size_t	size = 0;
	ssize_t	len;
	g_hash_map_ptr = &hash_map;
	g_line = &line;

	// int i = 0;
	while ((len = getline(&line, &size, stdin)) != -1) {
		if (line[--len] == '\n')
			line[len] = '\0';
		if (line[0] == '!' && line[1]) {
			delete_value(&hash_map, &line[1]);
			free(line);
		}
		else {
			if (!parse_command(&hash_map, line))
				free(line);
		}
		line = NULL;
	}
	if (line)
		free(line);
	free_data(&hash_map);
	return 0;
}