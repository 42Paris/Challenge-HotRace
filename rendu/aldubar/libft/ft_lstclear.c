/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 21:15:55 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/05 14:56:14 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*be_free;

	while (*lst)
	{
		be_free = *lst;
		(*del)(be_free->content);
		*lst = (*lst)->next;
		free(be_free);
	}
	*lst = NULL;
}
