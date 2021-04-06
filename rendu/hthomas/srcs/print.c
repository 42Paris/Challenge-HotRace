/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:37:07 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/06 06:15:01 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

void	print_dlist_line(t_dlist *stack, char name)
{
	t_dlist	*tmp;
	int		*num;

	tmp = stack;
	ft_putchar_fd(name, 2);
	ft_putstr_fd(": ", 2);
	while (tmp && tmp->next != stack)
	{
		num = tmp->content;
		ft_putnbr_fd(*num, 2);
		ft_putchar_fd(' ', 2);
		tmp = tmp->next;
	}
	if (tmp)
	{
		num = tmp->content;
		ft_putnbr_fd(*num, 2);
	}
	ft_putchar_fd('\n', 2);
}

void	print_clean_dlist(t_dlist *oper)
{
	t_dlist	*tmp;

	tmp = oper;
	if (tmp)
	{
		printf("%s\n", get_str(tmp));
		tmp = tmp->next;
	}
	while (tmp && tmp != oper)
	{
		if (tmp != oper)
		{
			printf("%s\n", get_str(tmp));
			tmp = tmp->next;
		}
	}
}
