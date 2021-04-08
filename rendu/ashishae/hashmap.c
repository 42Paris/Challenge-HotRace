/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:51:13 by ashishae          #+#    #+#             */
/*   Updated: 2021/04/08 09:33:14 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

inline int hn_cmp(hashmap_node *h, const char *key)
{
	return !strncmp(h->keyval, key, h->eqSign-1);
}

inline int hn_cmp_kv(hashmap_node *h, const char *kv, size_t eqSign)
{
	return (eqSign==h->eqSign && !strncmp(h->keyval, kv, h->eqSign-1));
}

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
	ret = (hashmap *)malloc(sizeof(hashmap));
	for (size_t i = 0; i < TABLE_SIZE; i++)
	{
		ret->table[i] = NULL;
	}
	return ret;
}

int hm_print(hashmap *h, const char *k, size_t eqSign) {
	size_t hashValue = sdbm(k);
	hashmap_node *cursor = h->table[hashValue];
	while (cursor != NULL) {

		if (hn_cmp_kv(cursor, k, eqSign)) {
			puts(cursor->keyval+cursor->eqSign+1);
			fflush(stdout);
			return 1;
		}
		cursor = cursor->next;
	}
	write(1, k, strlen(k));
	write(1, ": Not found\n", 12);
	fflush(stdout);
	return 0;
}

void hm_put(hashmap *h, const char *kv, size_t eqSign)
{
	size_t hashValue = sdbm_kv(kv, eqSign);

	if (h->table[hashValue] == NULL)
		h->table[hashValue] = new_hnode(kv, eqSign);
	else {
		hashmap_node *cursor = h->table[hashValue];

		while (cursor->next != NULL) {
			if (hn_cmp_kv(cursor, kv, eqSign))
			{
				return;
			}
			cursor = cursor->next;
		}
		cursor->next = new_hnode(kv, eqSign);
	}
}

void hm_remove(hashmap *h, const char *k, size_t eqSign)
{
	size_t hashValue = sdbm(k);

	if (h->table[hashValue] == NULL)
		return;

	hashmap_node *cursor = h->table[hashValue];

	hashmap_node *prev = NULL;
	while (cursor->next != NULL && !hn_cmp_kv(cursor, k, eqSign)) {
		prev = cursor;
		cursor = cursor->next;
	}

	if (cursor == NULL)
		return;

	if (prev == NULL)
		h->table[hashValue] = cursor->next;
	else
		prev->next = cursor->next;

	free((void *)cursor->keyval);
	free(cursor);
	cursor = NULL;
}