/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:33:41 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:40:04 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Deletes and frees the given node and every successor of that node,
**  using the function ’del’ and free(3).
** Finally, the pointer to the list must be set to NULL.
** @param adlst	The adress of the start of the list.
** @param dlst	The node where to start to delete.
** @param del	The adress of the function used to delete the content of the
**  node.
*/

void	ft_dlstclear(t_dlist **adlst, t_dlist *dlst, void (*del)(void*))
{
	if (!(*adlst) || !dlst)
		return ;
	if (dlst->next != *adlst)
		ft_dlstclear(adlst, dlst->next, del);
	ft_dlstdelone(dlst, del);
	dlst = NULL;
}
