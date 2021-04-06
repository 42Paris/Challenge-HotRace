/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:37:07 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/06 14:54:02 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

char	*get_str(t_list *outputs)
{
	return ((char *)(outputs->content));
}

void	print_clean_dlist(t_list *output)
{
	t_list	*tmp;

	tmp = output;
	if (tmp)
	{
		printf("%s\n", get_str(tmp));
		tmp = tmp->next;
	}
	while (tmp && tmp != output)
	{
		if (tmp != output)
		{
			printf("%s\n", get_str(tmp));
			tmp = tmp->next;
		}
	}
}
