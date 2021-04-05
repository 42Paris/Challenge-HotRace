/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:00:24 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/05 18:22:18 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

void	error(char *str, t_dlist *a, t_dict *ab, t_sp *norm)
{
	printf("Error: %s\n", str);
	if (a)
		ft_dlstclear(&a, a, free);
	if (ab)
	{
		if (ab->keys)
			ft_dlstclear(&ab->keys, ab->keys, free);
		if (ab->values)
			ft_dlstclear(&ab->values, ab->values, free);
		if (ab->oper)
			ft_dlstclear(&ab->oper, ab->oper, free);
		free(ab);
	}
	if (norm)
		free(norm);
	exit(1);
}

void	error_a_b(char *str, t_dlist *a, t_dlist *b, char *line)
{
	printf("Error: %s\n", str);
	if (a)
		ft_dlstclear(&a, a, free);
	if (b)
		ft_dlstclear(&b, b, free);
	if (line)
		free(line);
	exit(1);
}

int		get_value(t_dlist *stack)
{
	return (*(int *)(stack->content));
}

char	*get_str(t_dlist *stack)
{
	return ((char *)(stack->content));
}
