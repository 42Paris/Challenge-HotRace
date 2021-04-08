#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 831431

typedef struct hashlist {
    char *name;
    char *value;
    struct hashlist *next;
}hlist;

static hlist *hashtab[HASHSIZE];

unsigned long	hash(char *str) { //djb2
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return hash % HASHSIZE;
}

hlist		*lookup(char *s) {
    hlist	*np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
          	return np;
    return NULL;
}

hlist		*install(char *name, char *value)
{
    hlist			*np;
    unsigned long	hashval;

    if ((np = lookup(name)) == NULL) { 
        np = (hlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
          	return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    	if ((np->value = strdup(value)) == NULL)
	       	return NULL;
    }
    return np;
}

void delete(char *name) {
	unsigned int hashval = hash(name);
	hlist *np, *prev = NULL;

	for (np = hashtab[hashval]; np != NULL; np = np->next) {
		if (strcmp(name, np->name) == 0)
			break ;
		prev = np;
	}
	if (np != NULL) {
		if (prev == NULL)
			hashtab[hashval] = np->next;
		else
			prev->next = np->next;
		free(np->name);
		free(np->value);
		free(np);
	}
}

void		output_value(char *name) {
	hlist	*elem;

	elem = lookup(name);
	if (!elem)
		printf("%s: Not found\n", name);
	else
		printf("%s\n", elem->value);
}

void		free_hashtable(void) {
	hlist	*np;

	for (size_t i = 0; i < 0; i++) {
		for (np = hashtab[i]; np != NULL; np = np->next) {
			hashtab[i] = np->next;
			free(np->name);
			free(np->value);
			free(np);
		}
	}
}

int main() {
	char*	line = NULL;
	size_t	len = 0;
	ssize_t	read;
	char*	name;	
	char*	value;

	bzero(hashtab, sizeof(hlist*) * HASHSIZE);
	while ((read = getline(&line, &len, stdin)) != -1) {
		if (read < 2)
			continue ;
		if (line[0] == '!' && read > 2)
			delete(strtok(line + 1, "\n"));
		else if (strpbrk(line, "=") == NULL)
			output_value(strtok(line, "\n"));
		else {
			name = strtok(line, "=");
			value = strtok(name + strlen(name) + 1, "\n");
			if (name && value)
				if (!(install(name, value)))
					exit(EXIT_FAILURE);
		}
	}
	free_hashtable();
	free(line);
	return 0;
}
