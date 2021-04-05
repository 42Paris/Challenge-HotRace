/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:56:15 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 09:14:00 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_itoa_width(int nb, int width)
{
	char	*res;
	char	*tmp;
	int		diff;
	int		i;

	res = malloc((width + 1) * sizeof(char));
	if (!res)
		return (NULL);
	diff = width - ft_nbrlen(nb);
	if (diff > 0)
	{
		i = 0;
		while (i < diff)
			res[i++] = '0';
	}
	tmp = ft_itoa(nb);
	ft_memcpy(res + diff, tmp, ft_nbrlen(nb));
	free(tmp);
	return (res);
}
