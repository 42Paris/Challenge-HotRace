/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:26:41 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 16:56:53 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(const char c, int fd)
{
	int	ret;

	ret = write(fd, &c, 1);
	(void)ret;
}
