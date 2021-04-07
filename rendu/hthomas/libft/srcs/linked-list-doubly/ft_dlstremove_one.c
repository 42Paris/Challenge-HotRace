/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremove_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:56:00 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:40:30 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Remove the node 'dlst' of the list and return it.
** @param dlst	The address of the node to remove from the list.
** @return		The address of the node removed from the list.
*/

t_dlist	*ft_dlstremove_one(t_dlist **adlst, t_dlist *dlst)
{
	if (!*adlst || !dlst)
		return (NULL);
	if (*adlst == dlst)
	{
		if (*adlst == (*adlst)->next)
		{
			*adlst = NULL;
			return (dlst);
		}
		*adlst = dlst->next;
	}
	if (dlst->prev)
		dlst->prev->next = dlst->next;
	if (dlst->next)
		dlst->next->prev = dlst->prev;
	dlst->next = NULL;
	dlst->prev = NULL;
	return (dlst);
}
