/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:59:32 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/06 10:26:29 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static void	search(t_elem *dico, char *line)
{
	int		res;

	res = 0;
	while (dico)
	{
		if (ft_strcmp(line, dico->key) == 0)
		{
			ft_putstr(dico->value);
			ft_putchar('\n');
			res++;
		}
		dico = dico->next;
	}
	if (!res)
	{
		ft_putstr(line);
		ft_putstr(": Not found\n");
	}
}

static int	check_line(char *s)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == '=')
			res++;
		i++;
	}
	return (res);
}

static int	existing_key(t_elem **dico, char *s)
{
	t_elem	*tmp;

	tmp = *dico;
	while (tmp)
	{
		if (ft_strcmp(s, tmp->key) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		search_or_add(t_elem **dico, char *line)
{
	t_elem	*new;
	char	*key;
	char	*value;

	if (!check_line(line))
		search(*dico, line);
	else
	{
		key = get_key(line);
		if (existing_key(dico, key))
		{
			free(key);
			return ;
		}
		value = get_value(line);
		new = new_elem(key, value);
		free(key);
		free(value);
		if (!new)
			return ;
		add_front(dico, new);
	}
}
