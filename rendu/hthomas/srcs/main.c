/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/06 09:00:46 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

int	in_charset(char const c, char const *charset, int *pos)
{
	*pos = 0;
	while (charset[*pos])
	{
		if (c == charset[*pos])
			return (1);
		(*pos)++;
	}
	return (0);
}

char	*find_value(t_chain_tab *dict, char *key)
{
	if (!*key)
		return (dict->value);
	return (find_value(dict->nexts[(int)*key - MIN_CHAR], &key[1]));
}

void	add_to_dict(t_chain_tab **dict, char *key, char *value)
{
	if (!*key)
	{
		(*dict)->value = value;
		return ;
	}
	(*dict)->letters[(int)*key - MIN_CHAR]++;
	add_to_dict(&(*dict)->nexts[(int)*key - MIN_CHAR], &key[1], value);
}

int is_valid_entry(char *line, char **key, char **value, int *pos)
{
	int	ret;

	ret = in_charset('=', line, pos);
	line[*pos] = '\0';
	*key = line;
	*value = &line[*pos + 1];
	return (ret);
}

void	malloc_dict(t_chain_tab **dict)
{
	if (!(*dict) && !((*dict) = malloc(sizeof(**dict))))
		exit(-1);
	for (size_t i = 0; i < MAX_CHAR - MIN_CHAR + 1; i++)
		(*dict)->letters[i] = 0;
}

int		is_in_dict(t_chain_tab **dict, char *key, int length)
{
	if (!length || !*key)
		return (1);
	malloc_dict(dict);
	printf("is_in_dict1:%d\n", (int)*key - MIN_CHAR);
	printf("is_in_dict2:%d\n", (*dict)->letters[(int)*key - MIN_CHAR]);
	if ((*dict)->letters[(int)*key - MIN_CHAR])
		return (is_in_dict(&(*dict)->nexts[(int)*key - MIN_CHAR], &key[1] /*key + 1*/, length--)); //! todo
	return (0);
}

int		main(int argc, char const *argv[])
{
	char	*line;
	char	*key;
	char	*value;
	t_chain_tab	*dict;
	t_dlist	*outputs;
	int		length;

	if (argc != 1)
		return (0);
	(void) argv;
	dict = NULL;
	outputs = NULL;
	while (get_next_line(&line, 0))
	{
		if (is_valid_entry(line, &key, &value, &length))
		{
			printf("main:%s: %s\n", key, value);
			if (!is_in_dict(&dict, key, length))
				add_to_dict(&dict, key, value);
			else
			{
				char *output = ft_strjoin(key, ": ");
				if ((value = find_value(dict, key)))
					output = ft_strjoin_free(output, value);
				else
					output = ft_strjoin_free(output, "Not found");
				ft_dlstadd_back(&outputs, ft_dlstnew(output));
			}
		}
		else
			free(line);
		// free(key);
		// free(value);
	}
	print_clean_dlist(outputs);
	free(line);
	return (0);
}
