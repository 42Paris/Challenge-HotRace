/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 07:20:19 by jraffin           #+#    #+#             */
/*   Updated: 2021/04/08 13:54:47 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int		action_select(char *line, t_indexnode *treeroot)
{
	char	*value;

	if (line[0] == '!')
	{
		del_value(line + 1, treeroot);
		return (0);
	}
	else if ((value = strchr(line, '=')))
	{
		*value = '\0';
		value++;
		return (add_value(line, value, treeroot));
	}
	else if ((value = get_value(line, treeroot)))
	{
		return (fwrite(value, strlen(value), 1, stdout) == 0
		|| fwrite("\n", 1, 1, stdout) == 0);
	}
	else
	{
		return (fwrite(line, strlen(line), 1, stdout) == 0
		|| fwrite(": Not found\n", 12, 1, stdout) == 0);
	}
}

int		main(void)
{
	t_indexnode		*treeroot;
	char			*line;
	size_t			n;
	ssize_t			len;

	if (!(treeroot = calloc(1, sizeof(t_indexnode))))
		return (1);
	line = NULL;
	n = 0;
	while ((len = getline(&line, &n, stdin)) != -1)
	{
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (action_select(line, treeroot))
			break ;
	}
	free(line);
	free_tree(treeroot);
	if (errno)
	{
		perror(NULL);
		return (1);
	}
	return (0);
}
