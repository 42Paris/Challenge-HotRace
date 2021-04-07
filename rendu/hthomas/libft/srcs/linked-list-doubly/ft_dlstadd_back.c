/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:32:54 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:40:04 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Adds the node ’new’ at the end of the list
** @param adlst	The address of a pointer to the first node of a list.
** @param new	The address of a pointer to the node to be added to the list.
*/

void	ft_dlstadd_back(t_dlist **adlst, t_dlist *new)
{
	t_dlist	*tmp;

	if (!adlst)
		return ;
	if (!*adlst)
	{
		*adlst = new;
		(*adlst)->prev = *adlst;
		(*adlst)->next = *adlst;
		return ;
	}
	tmp = ft_dlstlast(*adlst);
	tmp->next = new;
	new->next = *adlst;
	(*adlst)->prev = new;
	new->prev = tmp;
}
