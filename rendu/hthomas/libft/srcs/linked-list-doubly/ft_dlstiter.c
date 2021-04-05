/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:33:57 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/25 16:40:04 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** Iterates the list ’dlst’ and applies the function ’f’ to the content of each
**  node.
** @param dlst	The adress of a pointer to an node.
** @param f		The adress of the function used to iterate on the list.
*/

void	ft_dlstiter(t_dlist *dlst, void (*f)(void *))
{
	t_dlist	*tmp;

	if (!dlst)
		return ;
	tmp = dlst;
	while (tmp->next && tmp->next != dlst)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
	f(tmp->content);
}
