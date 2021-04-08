/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 16:07:51 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 23:27:54 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>
#include <string.h>

int main(void)
{
	t_dict	*head;
	char	*line;

	head = NULL;
	while (1)
	{
		line = strdup("");
		if (!line)
			return (0);
		if (get_line(&line) <= 0)
			return (0);
		if (*line != '\0')
		{
			if (parse(&head, line) < 0)
				return (0);
		}
		free(line);
	}
	return (0);
}
