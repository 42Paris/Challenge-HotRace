/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:59:28 by eparisot          #+#    #+#             */
/*   Updated: 2017/11/14 14:51:06 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(t_list *lst)
{
	unsigned int count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

static void		ft_lstswap(void *mem, unsigned int mem_size, t_list *lst, \
							t_list *next)
{
	mem = lst->content;
	mem_size = lst->content_size;
	lst->content = next->content;
	lst->content_size = next->content_size;
	next->content = mem;
	next->content_size = mem_size;
}

void			ft_lstsort(t_list *lst, int (ft_cmp)(void *, void *))
{
	t_list			*first;
	t_list			*next;
	void			*mem;
	unsigned int	mem_size;
	unsigned int	count;

	first = lst;
	next = lst->next;
	mem = NULL;
	mem_size = 0;
	count = ft_count(lst);
	while (count--)
	{
		while (lst->next)
		{
			if (ft_cmp(lst->content, next->content) < 0)
			{
				ft_lstswap(mem, mem_size, lst, next);
			}
			lst = lst->next;
			next = next->next;
		}
		lst = first;
		next = lst->next;
	}
}
