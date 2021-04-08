/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:38:36 by nforay            #+#    #+#             */
/*   Updated: 2021/04/08 04:01:57 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/hotrace.h"

static int	lookup(t_query *query, char *input)
{
	t_list	*link;

	link = query->hashtable[query->hash];
	while (link)
	{
		if (!ft_strncmp(input, link->content[KEY], query->key_len + 1))
		{
			ft_putendl_fd(link->content[VALUE], STDOUT_FILENO);
			return (0);
		}
		link = link->next;
	}
	(void)!write(STDOUT_FILENO, input, query->key_len);
	ft_putendl_fd(": Not found", STDOUT_FILENO);
	return (1);
}

static int	insert(t_query *query, char *input)
{
	t_list	*link;
	t_list	*new;
	int		val_len;

	link = query->hashtable[query->hash];
	while (link)
	{
		if (!ft_strncmp(input, link->content[KEY], query->key_len + 1))
			return (1);
		link = link->next;
	}
	if (!link)
	{
		val_len = ft_strlen(query->input);
		query->input++;
		new = malloc(sizeof(t_list));
		new->next = query->hashtable[query->hash];
		query->hashtable[query->hash] = new;
		new->content[KEY] = malloc(sizeof(char) * query->key_len + 1);
		new->content[VALUE] = malloc(sizeof(char) * val_len);
		ft_memcpy(new->content[KEY], input, query->key_len);
		new->content[KEY][query->key_len] = '\0';
		ft_memcpy(new->content[VALUE], query->input, val_len);
	}
	return (0);
}

static int	delete(t_query *query, char *input)
{
	t_list	*link;
	t_list	*tmp;

	link = query->hashtable[query->hash];
	while (link)
	{
		if (!ft_strncmp(input + 1, link->content[KEY], query->key_len + 1))
		{
			tmp = link->next;
			free(link->content[KEY]);
			free(link->content[VALUE]);
			free(link);
			if (link == query->hashtable[query->hash])
				query->hashtable[query->hash] = NULL;
			else
				link = tmp;
			return (0);
		}
		link = link->next;
	}
	return (1);
}

int	parse_query(t_list **hashtable, char *input)
{
	static t_function	process[3] = {lookup, insert, delete};
	t_query				query;

	ft_memset(&query, 0, sizeof(t_query));
	query.input = input;
	query.hashtable = hashtable;
	if (input[0] == '!')
	{
		query.state = DELETE;
		query.input++;
	}
	while (*query.input && *query.input != '=')
	{
		if (query.key_len < HASHLENGTH)
		{
		query.hash += *query.input;		// "one_at_a_time" hash, not great, not terrible
		query.hash += query.hash << 10;	// CRC32 or murmur with multiple bits per iteration
		query.hash ^= query.hash >> 6;	// would be better, I was in a "rush" :)
		}
		query.input++;
		query.key_len++;
	}
	query.hash += query.hash << 3;
	query.hash ^= query.hash >> 11;
	query.hash += query.hash << 15;
	query.hash = (query.hash % HASHTABLESIZE);
	if (*query.input == '=' && !query.state)
		query.state = INSERT;
	return (process[query.state](&query, input));
}

int	main(void)
{
	char			*line;
	t_list			**hashtable;

	if (!(hashtable = malloc(sizeof(*hashtable) * HASHTABLESIZE)))
		return (1);
	ft_memset(hashtable, 0, sizeof(*hashtable) * HASHTABLESIZE);
	while (get_next_line(STDIN_FILENO, &line))
	{
		parse_query(hashtable, line);
		free(line);
	}
	return (0);
}
