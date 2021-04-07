/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:25:50 by abaudot           #+#    #+#             */
/*   Updated: 2021/04/07 20:38:29 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

/*
** Smalls utils functions
*/
static inline uint8_t compare(t_str *a, t_str *b)
{
	return (memcmp(a->s, b->s, a->key));
}

static inline struct s_bckt *bckt_at(struct s_map *h, uint64_t index)
{
	return (struct s_bckt*)(((uint8_t*)h->bckts) + (BCKTSZ * index));
}

static inline void *bckt_item(struct s_bckt *entry)
{
	return ((char*)entry) + 8;
}

static inline uint64_t get_hash(t_str *key)
{
	return spihash((uint8_t*)key->s, key->key) << 16 >> 16;
}

/*
** Make a new hashmap
*/
struct s_map *new_(size_t cap)
{
	if (cap < 16)
		cap = 16;

	uint64_t size = sizeof(struct s_map) + 48;
	struct s_map *h = malloc(size);
	if (!h)
		return (NULL);
	memset(h, 0, sizeof(struct s_map));
	h->tmp = ((char*)h) + sizeof(struct s_map);
	h->edata = (char*)h->tmp + 24;
	h->cap = cap;
	h->nbckts = cap;
	h->mask = h->nbckts - 1;
	h->bckts = malloc(BCKTSZ * h->nbckts);
	if (!h->bckts) {
		free(h);
		return NULL;
	}
	memset(h->bckts, 0, BCKTSZ * h->nbckts);
	h->grwat = h->nbckts * 0.75;
	h->shrnkat = h->nbckts * 0.10;
	return (h);    
}

/*
**	resize the hashmap if needed
*/
static uint8_t resize(struct s_map *h, uint64_t new_cap)
{
	struct s_map *h2 = new_(new_cap);

	if (!h2)
		return (0);
	for (uint64_t i = 0; i < h->nbckts; i++) {
		struct s_bckt *entry = bckt_at(h, i);
		if (!entry->dib)
			continue;
		entry->dib = 1;
		uint64_t j = entry->hash & h2->mask;
		
		while (1)
		{
			struct s_bckt *bckt = bckt_at(h2, j);
			if (bckt->dib == 0) {
				memcpy(bckt, entry, BCKTSZ);
				break;
			}
			if (bckt->dib < entry->dib) {
				memcpy(h2->tmp, bckt, BCKTSZ);
				memcpy(bckt, entry, BCKTSZ);
				memcpy(entry, h2->tmp, BCKTSZ);
			}
			j = (j + 1) & h2->mask;
			++entry->dib;
		}
	}
	free(h->bckts);
	h->bckts = h2->bckts;
	h->nbckts = h2->nbckts;
	h->mask = h2->mask;
	h->grwat = h2->grwat;
	h->shrnkat = h2->shrnkat;
	free(h2);
	return (1);
}

/*
** add entry to hashmap if entry is free
*/
uint8_t add_(struct s_map *h, void *item)
{
	if (h->count == h->grwat)
	{
		if (!resize(h, h->nbckts << 1))
			return (0);
	}

	struct s_bckt *entry = h->edata;
	entry->hash = get_hash(item);
	entry->dib = 1;
	memcpy(bckt_item(entry), item, STRSZ);

	uint64_t i = entry->hash & h->mask;
	while (42)
	{
		struct s_bckt *bckt = bckt_at(h, i);
		if (bckt->dib == 0)
		{
			memcpy(bckt, entry, BCKTSZ);
			++h->count;
			return (1);
		}
		if (entry->hash == bckt->hash &&
				compare(bckt_item(entry), bckt_item(bckt)) == 0)
		{
			free(((t_str*)item)->s);
			return (0);
		}
		if (bckt->dib < entry->dib)
		{
			memcpy(h->tmp, bckt, BCKTSZ);
			memcpy(bckt, entry, BCKTSZ);
			memcpy(entry, h->tmp, BCKTSZ);
		}
		i = (i + 1) & h->mask;
		++entry->dib;
	}
}

/*
**	return an entry if it is found, null otherwise
*/
void *get_(struct s_map *h, void *key)
{
	const uint64_t	hash = get_hash(key);
	uint64_t		i = hash & h->mask;

	while (42)
	{
		struct s_bckt *bckt = bckt_at(h, i);
		if (!bckt->dib)
			return (NULL);
		if (bckt->hash == hash && compare(key, bckt_item(bckt)) == 0)
			return bckt_item(bckt);
		i = (i + 1) & h->mask;
	}
}

/*
** Delet entry from hashmap
*/
void	*del_(struct s_map *h, void *key)
{
	const uint64_t	hash = get_hash(key);
	uint64_t		i = hash & h->mask;

	while (42)
	{
		struct s_bckt *bckt = bckt_at(h, i);
		if (!bckt->dib)
			return NULL;
		if (bckt->hash == hash && compare(key, bckt_item(bckt)) == 0)
		{
			free(((t_str*)bckt_item(bckt))->s);
			bckt->dib = 0;
			while (1)
			{
				struct s_bckt *prev = bckt;
				i = (i + 1) & h->mask;
				bckt = bckt_at(h, i);
				if (bckt->dib <= 1) {
					prev->dib = 0;
					break;
				}
				memcpy(prev, bckt, BCKTSZ);
				prev->dib--;
			}
			h->count--;
			if (h->nbckts > h->cap && h->count <= h->shrnkat)
				resize(h, h->nbckts >> 1);
		}
		i = (i + 1) & h->mask;
	}
}

/*
**	CLEAAAAANNNNNNN
*/
void	clean_(struct s_map *h)
{
	if (!h)
		return;
	for (uint64_t i = 0; i < h->nbckts; i++)
	{
		struct s_bckt *bckt = bckt_at(h, i);
		if (bckt->dib)
			free(((t_str*)bckt_item(bckt))->s);
	}
	free(h->bckts);
	free(h);
}
