/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:53:06 by ciglesia          #+#    #+#             */
/*   Updated: 2021/04/07 15:33:19 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdio.h>
# include <stdlib.h>

typedef unsigned char	t_uchar;

typedef struct			s_trie
{
	t_uchar				children;
	t_uchar				end;
	struct s_trie		**map;
	char 				*value;
}						t_trie;

char					*ft_strdup(const char *s1);
size_t					ft_strlen(const char *s);

#endif
