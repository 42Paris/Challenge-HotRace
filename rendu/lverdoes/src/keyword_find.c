/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyword_find.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 08:13:32 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 22:54:12 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

inline t_dict	*keyword_find(t_dict *head, char *str)
{
	int		i;
	t_dict	*tmp;

	if (!str)
		return (0);
	i = 0;
	tmp = head;
	while (str[i])
	{
		if (tmp && tmp->dict[(int)str[i]])
		{
			tmp = tmp->dict[(int)str[i]];
			i++;
		}
		else
			return (0);
	}
	return (tmp);
}
