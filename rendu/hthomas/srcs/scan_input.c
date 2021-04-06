/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:13:23 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/06 06:16:10 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

/*
** check if there are duplicates in the list
** @return	0 if no duplicates where found, 1 otherwise
*/

int		duplicates(t_dlist *a)
{
	t_dlist	*tmp;
	t_dlist	*tmp2;

	tmp = a;
	while (tmp && tmp->next != a)
	{
		tmp2 = tmp->next;
		while (tmp2 && tmp2 != a)
		{
			if (get_value(tmp) == get_value(tmp2))
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int		int_overflow(char const *str, int sign)
{
	if (sign)
		return (ft_strlen(str) == 10 && (ft_strcmp(str, "2147483648")) > 0);
	else
		return (ft_strlen(str) == 10 && (ft_strcmp(str, "2147483647")) > 0);
}

void	scan_input2(t_dlist **a, char const *argv[], int *i)
{
	int		*num;
	int		j;

	j = 0;
	if (argv[*i][j] && argv[*i][j] == '-')
		j++;
	if (ft_strlen(&argv[*i][j]) > 10 || int_overflow(&argv[*i][j], j))
		error_a_b("Int overflow", *a, NULL, NULL);
	while (argv[*i][j])
	{
		if (argv[*i][j] == 'v' && !argv[*i][j + 1])
		{
			(*i)++;
			return ;
		}
		else if (!ft_isdigit(argv[*i][j]))
			error_a_b("Is not number", *a, NULL, NULL);
		j++;
	}
	num = malloc(sizeof(int));
	if (!num)
		error_a_b("Malloc failed", *a, NULL, NULL);
	*num = ft_atol(argv[(*i)++]);
	ft_dlstadd_back(a, ft_dlstnew(num));
}

void	scan_if_print(int argc, char const *argv[], int *print)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i] && !ft_strcmp(argv[i], "-v"))
			*print = 1;
		i++;
	}
}

t_dlist	*scan_input(int argc, char const *argv[], int *print)
{
	int		i;
	t_dlist	*a;

	a = NULL;
	if (print)
		*print = 0;
	i = 1;
	while (i < argc)
		scan_input2(&a, argv, &i);
	if (duplicates(a))
		error_a_b("Duplicates", a, NULL, NULL);
	return (a);
}
