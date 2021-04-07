/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:26:40 by hthomas           #+#    #+#             */
/*   Updated: 2021/04/07 13:06:01 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define SIZE_DATABASE	1242419
# define PRIME_1		13
# define PRIME_2		31

# define MAX_CHAR	126
# define MIN_CHAR	32

# define ENTRY		'E'
# define SEARCH		'S'
# define DELETE		'D'

typedef struct	s_data
{
	char	*key;
	char	*value;
	size_t	length_key;
}			t_data;

void	print_clean_list(t_list *output);
int		in_charset(char const c, char const *charset, size_t *pos);

#endif
