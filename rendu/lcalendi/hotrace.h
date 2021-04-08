#ifndef	HOTRACE_H
# define HOTRACE_H

#define HASHSIZE 50000000

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_dict
{
	char *key;
	char *value;
	struct s_dict *next;
}				t_dict;

unsigned	get_hash_and_value(char *str, char **assign);
void		put_dict(char *key, char *value, unsigned hash);
void		remove_dict(char *key);
void		print_dict_entry(char *key, unsigned hash);

#endif
