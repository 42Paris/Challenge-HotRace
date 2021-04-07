/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:02:30 by atruphem          #+#    #+#             */
/*   Updated: 2021/04/07 22:14:46 by toni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include "get_next_line.h"
#include <stdlib.h>

int	test_new_key(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '=')
		       return (i + 1);
		i++;
	}
	return (0);
}	

static void handler(char *line, t_rb_node **root)
{
	char		*clean;
	char		*value;
	t_rb_node	*node;
	int		index;

	if (!(clean = malloc(sizeof(char) * (ft_strlen(line) + 1))))
		return;
	if (!(value = malloc(sizeof(char) * (ft_strlen(line) + 1))))
	{
		free(clean);
		return;
	}
	if (line[0] == '!')
	{
		ft_strlcpy(clean, line + 1, ft_strlen(line));
		if ((node = rb_search(*root, clean, &ft_strcmp)))
		{	
			node->enable = 0;
		}
		free(clean);
		free(value);
		return;
	}
	if ((index = test_new_key(line)) > 1)
	{
		ft_strlcpy(value, line + index, ft_strlen(line) - index + 1);
		ft_strlcpy(clean, line, index);
		if (rb_insert(root, clean, value, &ft_strcmp) == 0)
		{	
			free(clean);
			free(value);
		}
		else
			root_check(root);
		return;
	}
	if ((node = rb_search(*root, line, &ft_strcmp)) && (node->enable == 1))
	{
		ft_putstr_fd(node->value, 1);
		ft_putchar_fd('\n',1);
		free(clean); 
		free(value);
		return;
	}
	ft_putstr_fd(line, 1);
	ft_putstr_fd(": Not found\n",1);
	free(clean);
	free(value);
	return;
}

int main()
{
	char		*line;
	t_rb_node	*root;

	root = NULL;
	while (get_next_line(0, &line) > 0)
        {
                handler(line, &root);
                free(line);
        }
        free(line);
	clean_tree(root);
	free(root);
	return (0);
}

