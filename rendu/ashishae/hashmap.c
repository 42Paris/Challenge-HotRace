/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:51:13 by ashishae          #+#    #+#             */
/*   Updated: 2021/04/08 12:45:43 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

inline size_t sdbm(const char *str) {
	size_t hash = 33;
	size_t i = 0;
	unsigned char c;

	while((c = str[i++]) && i < BASICHASH_SUBSTR)
		hash = *str++ + (hash << 6) + (hash << 16) - hash;
	return hash % TABLE_SIZE;
}

inline size_t sdbm_kv(const char *kv, size_t eq) {
	size_t hash = 33;
	unsigned char c;
	size_t i = 0;

	while((c = kv[i++]) && i < eq && i < BASICHASH_SUBSTR)
		hash = c + (hash << 6) + (hash << 16) - hash;

	return hash % TABLE_SIZE;
}

hashmap_node *new_hnode(const char *kv, size_t eqSign)
{
	hashmap_node *ret = (hashmap_node *)malloc(sizeof(hashmap_node));
	ret->keyval = kv;
	ret->eqSign = eqSign;
	ret->next = NULL;
	return ret;
}

hashmap *new_hashmap()
{
	hashmap *ret;
	ret = calloc(TABLE_SIZE, sizeof(hashmap_node *));
	return ret;
}

int hm_print(hashmap *h, const char *k) {
	size_t hashValue = sdbm(k);
	hashmap_node *cursor = h->table[hashValue];
	if (cursor)
	{
		puts(cursor->keyval+cursor->eqSign+1);
		fflush(stdout);
		return 1;
	}
	printf("%s: Not found\n", k);
	return 0;
}

void hm_put(hashmap *h, const char *kv, size_t eqSign)
{
	size_t hashValue = sdbm_kv(kv, eqSign);

	if (h->table[hashValue] == NULL)
		h->table[hashValue] = new_hnode(kv, eqSign);
}

void hm_remove(hashmap *h, const char *k)
{
	size_t hashValue = sdbm(k);

	hashmap_node *cursor = h->table[hashValue];
	if (cursor)
	{
		h->table[hashValue] = NULL;
		free((void *)cursor->keyval);
		free(cursor);
		cursor = NULL;
	}
}