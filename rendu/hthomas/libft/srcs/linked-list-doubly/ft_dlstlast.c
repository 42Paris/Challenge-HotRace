/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:34:03 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:44:50 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Returns the last node of the list
** @param dlst	The beginning of the list
** @return		Last node of the list
*/

t_dlist	*ft_dlstlast(t_dlist *dlst)
{
	t_dlist	*tmp;

	if (!dlst)
		return (NULL);
	tmp = dlst;
	while (tmp->next && tmp->next != dlst)
		tmp = tmp->next;
	return (tmp);
}
