/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:00:24 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/07 13:08:07 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

int	in_charset(char const c, char const *charset, size_t *pos)
{
	*pos = 0;
	while (charset[*pos])
	{
		if (c == charset[*pos])
			return (1);
		(*pos)++;
	}
	return (0);
}

char	*get_str(t_list *outputs)
{
	return ((char *)(outputs->content));
}

void	print_clean_list(t_list *output)
{
	t_list	*tmp;

	tmp = output;
	if (tmp)
	{
		printf("%s\n", get_str(tmp));
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp)
		{
			printf("%s\n", get_str(tmp));
			tmp = tmp->next;
		}
	}
}

// void	print_clean_list(t_list *output) // big buffer to avoid write calls
// {
// 	t_list	*tmp;
// 	char 	buff[1000000];
// 	int		i;

// 	tmp = output;
// 	while (tmp)
// 	{
// 		i = 0;
// 		while (i < 999900 && tmp)
// 		{
// 			ft_strcpy(&buff[i], get_str(tmp));
// 			i += ft_strlen(get_str(tmp));
// 			buff[i++] = '\n';
// 			tmp = tmp->next;
// 		}
// 		write(1, buff, i);
// 	}
// }
