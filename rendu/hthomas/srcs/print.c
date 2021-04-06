/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:37:07 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/06 11:21:12 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

void	print_clean_dlist(t_dlist *output)
{
	t_dlist	*tmp;

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
