/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:10:04 by frthierr          #+#    #+#             */
/*   Updated: 2021/04/06 11:01:44 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*nav;
	t_list	*list;

	if (!lst)
		return ;
	nav = *lst;
	while (nav)
	{
		list = nav->next;
		ft_lstdelone(nav);
		nav = list;
	}
}
