/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:40:04 by geargenc          #+#    #+#             */
/*   Updated: 2021/04/08 11:38:43 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void		ft_bzerohtrc(t_htrc *list)
{
	int		i;

	i = 0;
	while (i < 95)
	{
		list[i].content = NULL;
		list[i].next = NULL;
		i++;
	}
}

char		**searchcreate(t_htrc **list, char *key)
{
	while (*key)
	{
		if (*list == NULL)
		{
			if ((*list = (t_htrc *)malloc(95 * sizeof(t_htrc))) == NULL)
				return (NULL);
			ft_bzerohtrc(*list);
			*list -= 32;
		}
		if (key[1] == '\0')
			return (&((*list)[(int)*key].content));
		list = &((*list)[(int)*key].next);
		key++;
	}
	return (NULL);
}

int			hotrace(t_htrc **list, char *line)
{
	char	*key;
	char	*value;
	char	**content;

	if (line[0] == '\0')
		return (0);
	key = line[0] == '!' ? line + 1 : line;
	value = ft_strchr(line, '=');
	if (value)
	{
		*value = '\0';
		value++;
	}
	if ((content = searchcreate(list, key)) == NULL)
		return (-1);
	if (*content == NULL)
	{
		if (value != NULL)
		{
			if ((*content = ft_strdup(value)) == NULL)
				return (-1);
			return (1);
		}
		else if (line[0] != '!')
			printf("%s: Not found\n", key);
		return (0);
	}
	if (line[0] == '!')
	{
		free(*content);
		*content = NULL;
		return (1);
	}
	if (value == NULL)
	{
		printf("%s\n", *content);
		return (1);
	}
	return (0);
}

int			main(void)
{
	t_htrc	*list;
	char	*line;
	int		ret;

	list = NULL;
	while ((ret = readstdin(&line)) > 0)
	{
		if (hotrace(&list, line) < 0)
			return (1);
		free(line);
	}
	return (0);
}