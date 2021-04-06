/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:27:38 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/06 10:25:00 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static void	remove_key(t_elem **dico, char *s)
{
	t_elem	*tmp;
	t_elem	*prev_node;

	tmp = *dico;
	prev_node = NULL;
	while (tmp != NULL)
	{
		if (ft_strcmp(s, tmp->key) == 0)
		{
			if (prev_node == NULL)
				*dico = tmp->next;
			else
				prev_node->next = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			break ;
		}
		prev_node = tmp;
		tmp = tmp->next;
	}
}

static void	parse(t_elem **dico, char *line)
{
	if (line[0] == '!' && line[1] != '\0')
		remove_key(dico, line + 1);
	else
		search_or_add(dico, line);
}

int			main(void)
{
	char	*line;
	int		fd;
	t_elem	*dico;

	dico = NULL;
	fd = STDIN_FILENO;
	while (ft_gnl(fd, &line) == 1)
	{
		parse(&dico, line);
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	clear_dico(dico);
	return (0);
}
