/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:24:56 by asoursou          #+#    #+#             */
/*   Updated: 2021/04/07 19:16:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "hotrace.h"

int str_cmp(const t_str *a, const t_str *b)
{
	return (memcmp(a->s, b->s, MIN(a->n, b->n) + 1));
}

void str_init(t_str *s, const char *value, size_t n)
{
	s->s = value;
	s->n = n;
}
