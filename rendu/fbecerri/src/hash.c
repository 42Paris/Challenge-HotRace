/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <fbecerri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:28:55 by fbecerri          #+#    #+#             */
/*   Updated: 2021/04/07 10:28:57 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static inline uint32_t murmur_32_scramble(uint32_t k)
{
	k *= 0xcc9e2d51;
	k = (k << 15) | (k >> 17);
	k *= 0x1b873593;
	return k;
}

uint32_t murmur3_32(t_string str)
{
	const uint8_t* key = (uint8_t *)str.buffer;
	size_t len = str.len;
	uint32_t h = 42;
	uint32_t k;

	for (size_t i = len >> 2; i; i--) {
		memcpy(&k, key, sizeof(uint32_t));
		key += sizeof(uint32_t);
		h ^= murmur_32_scramble(k);
		h = (h << 13) | (h >> 19);
		h = h * 5 + 0xe6546b64;
	}
	k = 0;
	for (size_t i = len & 3; i; i--) {
		k <<= 8;
		k |= key[i - 1];
	}
	h ^= murmur_32_scramble(k);
	h ^= len;
	h ^= h >> 16;
	h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;
	return h;
}

static uint32_t		hash(t_string str) {
	return (murmur3_32(str));
}

t_hashtable		*create_hashtable(size_t size)
{
	t_hashtable	*hash;
	size_t		i;

	if (!(hash = (t_hashtable *)malloc(sizeof(*hash) + size * sizeof(*hash->bucket))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		hash->bucket[i].key.buffer = NULL;
		hash->bucket[i].fill = false;
		i++;
	}
	hash->size = size;
	return (hash);
}

t_entry			create_entry(t_string key)
{
	return ((t_entry) {
			.key = key,
			.hash = hash(key),
			.fill = true
			});
}

bool			grow_hashtable(t_hashtable **old)
{
	t_hashtable	*table;
	size_t		i;
	t_entry		*entry;

	if (!(table = create_hashtable((*old)->size * GROWTH_RATIO)))
		return (false);
	i = 0;
	while (i < (*old)->size)
	{
		entry = (*old)->bucket + i;
		if (entry->key.buffer)
			insert_hashtable(&table, *entry);
		i++;
	}
	free(*old);
	*old = table;
	return (true);
}

t_entry			*insert_hashtable(t_hashtable **table, t_entry entry)
{
	size_t			i;
	size_t			j;
	const t_entry	*curr = (*table)->bucket;

	j = 0;
	i = entry.hash % (*table)->size;
	while (curr[i % (*table)->size].key.buffer != NULL
			&& j < DISPERTION)
	{
		if (entry.hash == curr[i % (*table)->size].hash)
			if (ft_strcmp(entry.key, curr[i % (*table)->size].key) == true)
				return (NULL);
		i++;
		j++;
	}
	if (j == DISPERTION)
	{
		if (!grow_hashtable(table))
			return (NULL);
		return (insert_hashtable(table, entry));
	}
	(*table)->bucket[i % (*table)->size] = entry;
	return ((*table)->bucket + (i % (*table)->size));
}

t_entry			*hashtable_get(t_hashtable *table, t_string name)
{
	uint32_t		hash_name;
	size_t			i;
	size_t			j;
	t_entry *const	curr = table->bucket;

	hash_name = hash(name);
	i = hash_name % table->size;
	j = 0;
	while (j < DISPERTION
			&& curr[i % table->size].fill
			&& (curr[i % table->size].hash != hash_name
				|| ft_strcmp(curr[i % table->size].key, name) == false))
	{
		i++;
		j++;
	}
	if (curr[i % table->size].key.buffer && j < DISPERTION)
		return (curr + i % table->size);
	else
		return (NULL);
}

void		hashtable_delete(t_hashtable *table, t_string name) {
	uint32_t		hash_name;
	size_t			i;
	size_t			j;
	t_entry *const	curr = table->bucket;

	hash_name = hash(name);
	i = hash_name % table->size;
	j = 0;
	while (j < DISPERTION
			&& curr[i % table->size].fill
			&& (curr[i % table->size].hash != hash_name
				|| ft_strcmp(curr[i % table->size].key, name) == false))
	{
		i++;
		j++;
	}
	if (curr[i % table->size].key.buffer && j < DISPERTION) {
		curr[i % table->size].key.buffer = NULL;			
	}
}
