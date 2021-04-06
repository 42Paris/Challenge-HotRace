/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 14:51:12 by pde-bakk       #+#    #+#                */
/*   Updated: 2019/11/14 12:02:43 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*link;
	t_list	*tmp;

	if (!(lst))
		return ;
	link = *lst;
	while (link)
	{
		tmp = link->next;
		del(link->content);
		free(link);
		link = tmp;
	}
	*lst = NULL;
}
