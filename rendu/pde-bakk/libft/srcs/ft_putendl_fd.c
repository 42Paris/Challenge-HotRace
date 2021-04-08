/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pde-bakk <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:47:03 by pde-bakk      #+#    #+#                 */
/*   Updated: 2021/03/29 16:56:49 by pde-bakk      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	int	ret;

	if (s)
		ret = write(fd, s, ft_strlen(s));
	ret = write(fd, "\n", 1);
	(void)ret;
}
