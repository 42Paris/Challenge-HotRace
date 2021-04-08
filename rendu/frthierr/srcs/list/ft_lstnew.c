/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:19:52 by frthierr          #+#    #+#             */
/*   Updated: 2021/04/07 12:31:33 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

t_list		*ft_lstnew(t_pair *pair)
{
	t_list	*new;

	if (!pair)
		return (NULL);
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->key = pair->key;
	new->value = pair->value;
	if (!new->key || !new->value)
		return NULL;
	new->next = NULL;
	return (new);
}
