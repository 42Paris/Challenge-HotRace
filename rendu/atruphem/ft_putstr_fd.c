/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 10:17:34 by atruphem          #+#    #+#             */
/*   Updated: 2020/11/22 10:35:10 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int		size;
	int		i;

	if (s == NULL)
		return ;
	size = 0;
	i = 0;
	while (s[i] != '\0')
	{
		size++;
		i++;
	}
	write(fd, s, size);
}
