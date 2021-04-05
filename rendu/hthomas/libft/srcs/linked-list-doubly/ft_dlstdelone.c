/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:33:49 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:40:04 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Takes as a parameter an node and frees the memory of
**  the node’s content using the function ’del’ given as a parameter
**  and free the node. The memory of ’next’ must not be freed
** @param dlst	The adress of a pointer to an node.
** @param del	The adress of the function used to delete the content of the
**				 node.
*/

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void*))
{
	if (!dlst)
		return ;
	del(dlst->content);
	free(dlst);
}
