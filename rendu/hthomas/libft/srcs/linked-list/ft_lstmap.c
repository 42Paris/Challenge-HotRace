/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:51:17 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:41:00 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Iterates the list ’lst’ and applies the function ’f’ to the content of each
**  node. Creates a newlist resulting of the successive applications of the
**  function ’f’. The ’del’ function is used to delete the content of an
**  node if needed.
** @param lst	The adress of a pointer to an node.
** @param f		The adress of the function used to iterate on the list.
** @param del	The adress of the function used to delete the content of an
**				 node if needed.
** @return		The new list. NULL if the allocation fails.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*mapedlst;

	if (!lst || !f || !del)
		return (NULL);
	tmp = lst;
	mapedlst = ft_lstnew(f(tmp->content));
	if (!mapedlst)
		ft_lstclear(&mapedlst, del);
	tmp = tmp->next;
	while (tmp)
	{
		new = ft_lstnew(f(tmp->content));
		if (!new)
			ft_lstclear(&mapedlst, del);
		ft_lstadd_back(&mapedlst, new);
		tmp = tmp->next;
	}
	return (mapedlst);
}
