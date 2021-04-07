/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_charset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:51:36 by hthomas           #+#    #+#             */
/*   Updated: 2021/03/21 09:10:59 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_in_charset(char const c, char const *charset)
{
	int	i_charset;

	i_charset = 0;
	while (charset[i_charset])
	{
		if (c == charset[i_charset++])
			return (1);
	}
	return (0);
}
