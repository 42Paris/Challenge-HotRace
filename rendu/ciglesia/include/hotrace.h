/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:53:06 by ciglesia          #+#    #+#             */
/*   Updated: 2021/04/08 10:50:35 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef unsigned char	t_uchar;

typedef struct			s_trie
{
	t_uchar				children;
	t_uchar				end;
	struct s_trie		**map;
	char 				*value;
}						t_trie;

#endif
