/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 09:40:14 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/06 06:15:15 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

/*
** ALGO QUICK SORT
** 	if size 2 or 3
** 		sort + push on a if needed
** 		return
** 	find median node
** 	if (on stack a):
** 		put lowers than median on stack b
** 		put median at the end of stack (with rb after pb)
** 		then rrb to put the median at the rigth place
** 	else:
** 		put biggers than median on stack a
** 		put median at the end of stack (with ra after pa)
** 		then rra to put the median at the rigth place
**
** 	recursion on lowers (stack to median)
** 	recursion on biggers (stack from median)
** 	push on current stack all nodes from other stack (smallers)
** 	(median is now in place)
** DONE
*/

void	init_begin_end(t_dict *ab, t_dlist **begin, t_dlist **end, int p_a)
{
	if (p_a)
	{
		*begin = find_node(ab->values, get_value(*begin));
		*end = find_node(ab->values, get_value(*end));
	}
	else
	{
		*begin = find_node(ab->keys, get_value(*begin));
		*end = find_node(ab->keys, get_value(*end));
	}
}

void	end_quicksort(t_dict *ab, t_dlist *begin, t_dlist *end, t_sp *norm)
{
	int	cpt;

	cpt = 0;
	norm->i = ft_dlstsize(ab->values);
	if (ab->values)
		cpt = sort_quick(ab, ab->values, ab->values->prev,
				norm);
	while (cpt--)
		ra(ab);
	if (begin != ab->keys)
		ra(ab);
	norm->i = ft_dlstsize(ab->values);
	if (ab->keys)
		cpt = sort_quick(ab, begin, end, norm);
	while (cpt--)
		ra(ab);
}

void	sort_quick2(t_dict *ab, t_dlist **tmp, t_begin_end *be, t_sp *norm)
{
	int	later;

	later = 0;
	while (norm->len--)
		later += divide_stack(ab, tmp, norm->index, be);
	if (norm->i)
		rra(ab);
	else
		rrb(ab);
	while (later--)
	{
		reverse(&ab->keys);
		ft_dlstadd_back(&ab->oper, ft_dlstnew(ft_strdup("rra")));
	}
}

/*
** Sort a stack with the help of a second stack using only the
** autorized operations and print them.
** The algo used is kind of a quick sort modified to work with 2 stacks
** @param ab		pointer on the struct tu coco
** @param begin		start of the stack to sort
** @param end		end of the stack to sort
** @param p_a	change the comparaison in divide_stack
*/

int		sort_quick(t_dict *ab, t_dlist *begin, t_dlist *end, t_sp *norm)
{
	t_dlist		*median;
	t_dlist		*tmp;
	t_begin_end	*be;

	if (!ab || !begin || !end)
		return (0);
	init_begin_end(ab, &begin, &end, norm->i);
	if (size_stack(begin, end) <= 3)
		return (sort_stack_under_3(ab, &begin, end, norm->i));
	median = find_median(begin, end);
	if (!median)
		return (0);
	norm->index = get_value(median);
	tmp = begin;
	norm->len = size_stack(begin, end);
	begin = NULL;
	end = NULL;
	be = malloc(sizeof(*be));
	be->begin = &begin;
	be->end = &end;
	sort_quick2(ab, &tmp, be, norm);
	free(be);
	end_quicksort(ab, begin, end, norm);
	return (0);
}
