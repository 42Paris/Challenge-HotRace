/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 21:35:38 by aldubar           #+#    #+#             */
/*   Updated: 2020/11/17 18:23:34 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*new;

	new = NULL;
	while (lst)
	{
		map = ft_lstnew((*f)(lst->content));
		if (!map)
		{
			ft_lstclear(&new, (*del));
			return (0);
		}
		ft_lstadd_back(&new, map);
		lst = lst->next;
	}
	return (new);
}
