/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/06 11:17:09 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static uint64_t	hash(char *key, size_t size_database)
{
	uint64_t    value;
    size_t      i;

    i = 0;
	value = 17;
	size_t len = ft_strlen(key);
	while (i < len)
	{
		value = (value * key[i] * 19) % size_database;
		i++;
	}
	return (value);
}

char	*find_value(t_dlist **table, char *key)
{
	return (ft_strdup("Not found"));
}

void	add_to_dict(t_dlist **table, t_data *data)
{

}

int is_valid_entry(char *line, t_data *data)
{
	int	ret;

	ret = in_charset('=', line, &(data->length_key));
	line[data->length_key] = '\0';
	data->key = line;
	data->value = &line[data->length_key + 1];
	return (ret);
}

int		is_in_dict(t_dlist **table, char *key)
{
	return (0);
}

int		main(int argc, char const *argv[])
{
	char	*line;
	t_data	*data;
	t_dlist	**table;
	t_dlist	*outputs;

	if (argc != 1)
		return (0);
	(void) argv;
	table = NULL;
	outputs = NULL;
	while (get_next_line(&line, 0))
	{
		data = NULL;
		if (is_valid_entry(line, data))
		{
			printf("main:%s: %s\n", data->key, data->value);
			if (!is_in_dict(table, data->key))
				add_to_dict(table, data);
			else
			{
				char *output = ft_strjoin(data->key, ": ");
				if ((data->value = find_value(table, data->key)))
					output = ft_strjoin_free(output, data->value);
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
