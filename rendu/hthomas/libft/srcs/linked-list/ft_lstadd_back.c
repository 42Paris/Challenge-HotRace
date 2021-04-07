/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:49:44 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:40:04 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Adds the node ’new’ at the end of the list
** @param alst	The address of a pointer to the first link of a list.
** @param new	The address of a pointer to the node to be added to the list.
*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*pt;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	pt = *alst;
	while (pt->next)
		pt = pt->next;
	pt->next = new;
}
