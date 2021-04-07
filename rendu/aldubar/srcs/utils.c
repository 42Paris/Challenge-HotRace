/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:19:36 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/06 00:04:33 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

t_elem	*new_elem(char *key, char *value)
{
	t_elem	*new;

	new = (t_elem *)malloc(sizeof(t_elem));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

void	add_front(t_elem **alst, t_elem *new)
{
	if (alst)
		new->next = *alst;
	*alst = new;
}

char	*get_key(char *s)
{
	int		i;
	char	*key;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	key = ft_strndup(s, i);
	return (key);
}

char	*get_value(char *s)
{
	int		i;
	char	*value;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	value = ft_strndup(s + i + 1, ft_strlen(s) - i);
	return (value);
}

void	clear_dico(t_elem *dico)
{
	t_elem	*be_free;

	while (dico)
	{
		be_free = dico;
		free(be_free->key);
		free(be_free->value);
		dico = dico->next;
		free(be_free);
	}
	dico = NULL;
}
