/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:20:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 03:25:34 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	sort_str(char *tabstr[], int size)
{
	int	swap;
	int	i;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(tabstr[i], tabstr[i + 1]) > 0)
			{
				ft_swap(&tabstr[i], &tabstr[i + 1]);
				swap = 1;
			}
			i++;
		}
	}
}
