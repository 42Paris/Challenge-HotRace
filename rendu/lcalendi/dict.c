#include "hotrace.h"
#include <unistd.h>
#include <string.h>

extern t_dict **g_dict;

t_dict	*create_dict_entry(char *key, char *value, void *next)
{
	t_dict *ret;

	if (!(ret = malloc(sizeof(t_dict))))
		exit(EXIT_FAILURE);
	ret->key = key;
	ret->value = value;
	ret->next = next;
	return (ret);
}

unsigned	get_hash_and_value(char *str, char **assign)
{
	unsigned hash = 0;

	while (*str && *str != '=')
	{
		hash = hash * 31 + *str;
		str++;
	}
	if (*str == '=')
	{
		*assign = str + 1;
		*str = 0;
	}
	else
		*assign = 0;
	return (hash % HASHSIZE);
}

unsigned	get_hash(char *str)
{
	unsigned hash = 0;

	while (*str && *str != '=')
	{
		hash = hash * 31 + *str;
		str++;
	}
	return (hash % HASHSIZE);
}

void	put_dict(char *key, char *value, unsigned hash)
{
	if (g_dict[hash])
	{
		t_dict *temp;

		temp = g_dict[hash];
		while (temp)
		{
			if (!strcmp(temp->key, key))
				return ;
			temp = temp->next;
		}
	}
	g_dict[hash] = create_dict_entry(key, value, g_dict[hash]);
}

void	remove_dict(char *key)
{
	unsigned hash;

	hash = get_hash(key);
	if (g_dict[hash])
	{
		t_dict *temp;
		t_dict *recall = 0;

		temp = g_dict[hash];
		while (temp)
		{
			if (!strcmp(temp->key, key))
			{
				if (recall)
					recall->next = temp->next;
				else
					g_dict[hash] = temp->next;
				free(temp->key);
				free(temp);
				free(key - 1);
				return ;
			}
			recall = temp;
			temp = temp->next;
		}
	}
}

void	print_dict_entry(char *key, unsigned hash)
{
	if (g_dict[hash])
	{
		t_dict *temp;

		temp = g_dict[hash];
		while (temp)
		{
			if (!strcmp(temp->key, key))
			{
				printf("%s\n", temp->value);
				free(key);
				return ;
			}
			temp = temp->next;
		}
	}
	printf("%s: Not found\n", key);
}
