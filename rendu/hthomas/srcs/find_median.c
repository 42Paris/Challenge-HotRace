/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:10:52 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/06 06:14:52 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

int		*ft_dlst_to_tabn(t_dlist *dlst, int max)
{
	t_dlist	*tmp;
	int		*tab;
	int		i;

	if (!dlst)
		return (NULL);
	tab = malloc(sizeof(int) * max);
	if (!tab)
		return (NULL);
	tab[0] = get_value(dlst);
	tmp = dlst->next;
	max--;
	i = 1;
	while (tmp != dlst && max--)
	{
		tab[i] = get_value(tmp);
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

/*
** Find the node with the corresponding value in the stack
** @param stack	the stack containing node
** @param value	value of the node we are looking for
** @return		node with the corresponding value
*/

t_dlist	*find_node(t_dlist *stack, int value)
{
	t_dlist	*tmp;

	if (!stack)
		return (NULL);
	if (get_value(stack) == value)
		return (stack);
	tmp = stack->next;
	while (tmp != stack)
	{
		if (get_value(tmp) == value)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		size_stack(t_dlist *begin, t_dlist *end)
{
	int		cpt;
	t_dlist	*tmp;

	cpt = 0;
	tmp = begin;
	if (!begin || !end || !find_node(begin, get_value(end)))
		return (0);
	while (tmp != end)
	{
		cpt++;
		tmp = tmp->next;
	}
	return (cpt + 1);
}

/*
** Find and return median node (relative to the value) in the given stack
** @param stack	stack where to find the node
** @return		the median node
*/

t_dlist	*find_median(t_dlist *stack, t_dlist *end)
{
	int		*tab;
	int		median_value;
	int		size;

	size = size_stack(stack, end);
	if (!stack || size < 0)
		return (NULL);
	tab = ft_dlst_to_tabn(stack, size);
	sort_int(tab, size);
	median_value = tab[(size - 1) / 2];
	free(tab);
	return (find_node(stack, median_value));
}
