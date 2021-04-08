/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:01:13 by asoursou          #+#    #+#             */
/*   Updated: 2021/04/07 19:43:11 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

#define FNV1A_PRIME	0x1000193
#define FNV1A_SEED	0x811c9dc5

// Hash a string using FNV-1a, returns: 0 <= value < HASH_TABLE_SIZE
static unsigned fnv1a_hash(const char *s)
{
	unsigned h;

	h = FNV1A_SEED;
	while (*s)
		h = (*s++ ^ h) * FNV1A_PRIME;
	return ((h >> HASH_TABLE_POWER) ^ (h & HASH_TABLE_MASK));
}

bool dict_add(t_dict *d, const t_str *k, const t_str *v)
{
	t_rbtree	**r;
	t_rbtree	*b;

	r = d->t + fnv1a_hash(k->s);
	b = rbtree_find(*r, k);
	if (b)
		return (1);
	else if (!(b = rbtree_new(k, v)))
		return (0);
	rbtree_insert(r, b);
	return (1);
}

void dict_erase(t_dict *d, const t_str *k)
{
	t_rbtree	**r;
	t_rbtree	*b;

	r = d->t + fnv1a_hash(k->s);
	b = rbtree_find(*r, k);
	if (b)
		rbtree_remove(r, b);
}

const t_str *dict_find(const t_dict *d, const t_str *k)
{
	t_rbtree *b;

	b = rbtree_find(d->t[fnv1a_hash(k->s)], k);
	return (b ? &b->value : NULL);
}
