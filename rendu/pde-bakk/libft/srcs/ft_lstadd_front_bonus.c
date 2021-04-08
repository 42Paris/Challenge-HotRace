/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 19:53:27 by pde-bakk      #+#    #+#                 */
/*   Updated: 2020/10/02 23:00:42 by peerdb        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *newitem)
{
	if (!(alst) || !(newitem))
		return ;
	newitem->next = *alst;
	*alst = newitem;
}
