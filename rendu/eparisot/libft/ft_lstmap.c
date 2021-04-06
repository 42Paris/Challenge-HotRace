/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:40:58 by eparisot          #+#    #+#             */
/*   Updated: 2017/10/30 10:55:27 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*new_item;

	if (lst == NULL || (*f) == NULL)
		return (NULL);
	new_item = (*f)(lst);
	new_list = new_item;
	lst = lst->next;
	while (lst)
	{
		new_item->next = (*f)(lst);
		new_item = new_item->next;
		lst = lst->next;
	}
	return (new_list);
}
