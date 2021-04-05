#ifndef HASHCODE_H

# define HASHCODE_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include "ft_string.h"

typedef struct	    s_entry
{
	t_string		key;
	uint64_t	    hash;
	t_string		data;
}				    t_entry;

typedef struct	    s_hashtable
{
	size_t		    size;
	t_entry		    bucket[];
}				    t_hashtable;

static uint64_t	hash(t_string str)
{
	uint64_t    value;
    size_t      i;

    i = 0;
	value = 456;
	while (i < str.len)
	{
		value = value * 31 + str.buffer[i];
		i++;
	}
	return (value);
}

t_hashtable		*create_hashtable(size_t size)
{
	t_hashtable *hash;
	size_t		i;

	if (!(hash = (t_hashtable *)malloc(sizeof(*hash) + size * sizeof(*hash->bucket))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		hash->bucket[i].key.buffer = NULL;
		i++;
	}
	hash->size = size;
	return (hash);
}

t_entry			create_entry(t_string key)
{
	return ((t_entry) {
		.key = key,
		.hash = hash(key)
	});
}

t_entry			*insert_hashtable(t_hashtable **table, t_entry entry);

bool			grow_hashtable(t_hashtable **old)
{
	t_hashtable	*table;
	size_t		i;
	t_entry		*entry;

	if (!(table = create_hashtable((*old)->size * 2)))
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
		&& j < (*table)->size / 16)
	{
		if (entry.hash == curr[i % (*table)->size].hash)
			if (ft_strcmp(entry.key, curr[i % (*table)->size].key) == true)
				return (NULL);
		i++;
		j++;
	}
	if (j == (*table)->size / 16)
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
	uint64_t		hash_name;
	size_t			i;
	size_t			j;
	t_entry *const	curr = table->bucket;

	hash_name = hash(name);
	i = hash_name % table->size;
	j = 0;
	while (j < table->size
		&& curr[i % table->size].key.buffer
		&& (curr[i % table->size].hash != hash_name
			|| ft_strcmp(curr[i % table->size].key, name) == false))
	{
		i++;
		j++;
	}
	if (curr[i % table->size].key.buffer && j < table->size)
		return (curr + i % table->size);
	else
		return (NULL);
}

void		hashtable_delete(t_hashtable *table, t_string name) {
	uint64_t		hash_name;
	size_t			i;
	size_t			j;
	t_entry *const	curr = table->bucket;

	hash_name = hash(name);
	i = hash_name % table->size;
	j = 0;
	while (j < table->size
		&& curr[i % table->size].key.buffer
		&& (curr[i % table->size].hash != hash_name
			|| ft_strcmp(curr[i % table->size].key, name) == false))
	{
		i++;
		j++;
	}
	if (curr[i % table->size].key.buffer && j < table->size) {
		j = 0;
		while (j < table->size && curr[i % table->size].key.buffer) {
			curr[i % table->size].key.buffer = curr[(i + 1) % table->size].key.buffer;
			curr[i % table->size].hash = curr[(i + 1) % table->size].hash;
			curr[i % table->size].data = curr[(i + 1) % table->size].data;
			i++;
			j++;
		}
		
	}
}

#endif

