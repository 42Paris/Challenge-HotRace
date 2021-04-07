/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 21:27:04 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 22:54:03 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static inline void	remove_keyword(t_dict *head, char *line)
{
	t_dict	*page;

	page = keyword_find(head, line);
	if (page)
	{
		free(page->content);
		page->content = NULL;
	}
}

static inline int	new_keyword(t_dict **head, char *key, char *line)
{
	int	ret;

	*key = '\0';
	key = strdup(key + 1);
	if (!key)
		return (-1);
	ret = keyword_new(head, key, line);
	if (ret <= 0)
		free(key);
	return (ret);
}

static inline void	look_up(t_dict *head, char *line)
{
	t_dict	*page;

	page = keyword_find(head, line); 
	if (page && page->content)
	{
		write(STDOUT_FILENO, page->content, strlen(page->content));
		write(STDOUT_FILENO, "\n", 1);
	}
	else
	{
		write(STDOUT_FILENO, line, strlen(line));
		write(STDOUT_FILENO, ": Not found\n", 12);
	}
}

inline int	parse(t_dict **head, char *line)
{
	char	*key;

	if (*line == '!')
		remove_keyword(*head, line + 1);
	else
	{
		key = strchr(line, '=');
		if (key)
		{
			if (new_keyword(head, key, line) < 0)
				return (-1);
		}
		else
			look_up(*head, line);
	}
	return (1);
}