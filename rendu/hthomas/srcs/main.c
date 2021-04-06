/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/06 06:14:57 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

void	print_value(t_dict *dict, char *key)
{

}

void	add_to_dict(t_dict *dict, char *key, char *value)
{

}

int is_entry(t_dict *dict, char *line, char **key, char **value)
{
	return (1);
}

int is_in_dict(t_dict *dict, char *key)
{
	return (1);
}

void	main2(t_dlist **a, t_dlist **b)
{
	char	*line;
	char	*key;
	char	*value;
	t_dict	*dict;

	dict = NULL;
	while (get_next_line(&line, 0))
	{
		if (is_entry(dict, line, &key, &value) && !is_in_dict(dict, key))
			add_to_dict(dict, key, value);
		else
			print_value(dict, key);
		free(key);
		free(value);
		free(line);
	}
	free(line);
	ft_dlstclear(b, *b, free);
	if (*b)
		printf("KO\n");
	else
		printf("OK\n");
}

int		main(int argc, char const *argv[])
{
	t_dlist	*a;
	t_dlist	*b;
	int		print;

	b = NULL;
	if (argc != 1)
		return (0);
	a = scan_input(argc, argv, &print);
	main2(&a, &b);
	ft_dlstclear(&a, a, free);
	return (0);
}
