#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LISTSIZE 1178743

typedef struct Entry {
	char *name;
	char *value;
	struct Entry *next;
} Entry;

typedef size_t t_index;

void insert(Entry **list, char *name, char *value);
t_index hash(char *s);
void show(Entry *list, char *name);
void rm(Entry **list, char *name);
void free_list(Entry **list);

#define FREEE(entry)							\
	do {										\
		free(entry->name);						\
		free(entry->value);						\
		free(entry);							\
	}while(0);

#define MAKEE(entry, name, value)				\
	do { \
	entry = malloc(sizeof(Entry));				\
	entry->name = malloc(strlen(name) + 1);		\
	strcpy(entry->name, name);					\
	entry->value = malloc(strlen(value) + 1);	\
	strcpy(entry->value, value);				\
	entry->next = NULL; \
}while(0);

#define UPDATEW(entry, new)                       \
	do {                                          \
		free((entry)->value);                     \
		(entry)->value = malloc(strlen(new) + 1); \
		strcpy((entry)->value, new);              \
	} while (0)

int main()
{
	size_t ieq, i;
	char *name, *value;
	Entry **list = malloc(sizeof(Entry) * LISTSIZE);
	char *lineptr = NULL;
	size_t n = 0;

	memset(list, 0, LISTSIZE * sizeof(Entry));
	while (getline(&lineptr, &n, stdin) > 0) {
		ieq = 0;
		i = 1;
		while (lineptr[i] != '\0') {
			if (lineptr[i] == '=')
				ieq = i;
			++i;
		}
		if (i > 0 && lineptr[i - 1] == '\n')
			lineptr[i - 1] = '\0';
		if (ieq != 0) {
			lineptr[ieq] = 0;
			name = lineptr;
			value = lineptr + ieq + 1;
			insert(&list[hash(name) % LISTSIZE], name, value);
		}
		else if (lineptr[0] != '!')
			show(list[hash(lineptr) % LISTSIZE], lineptr);
		else
			rm(&list[hash(lineptr + 1) % LISTSIZE], lineptr + 1);
	}

	free_list(list);
	free(lineptr);

	return 0;
}

void free_list(Entry **list)
{
	Entry *p, *pn;
	for (int i = 0; i < LISTSIZE; ++i) {
		p = list[i];
		while (p) {
			pn = p->next;
			FREEE(p);
			p = pn;
		}
	}
	free(list);
}

t_index hash(char *s)
{
	t_index hash = 5381;

	while (*s)
		hash = ((hash << 5) + hash) + *s++;
	return hash;
}

void insert(Entry **root, char *name, char *value)
{
    Entry *p, *pn;
    Entry *entry;
    int cmp;

    if (*root == NULL) {
        MAKEE(entry, name, value);
        *root = entry;
        return;
    }

    if ((cmp = strcmp(name, (*root)->name)) <= 0) {
        if (cmp < 0) {
            MAKEE(entry, name, value);
            entry->next = *root;
            *root = entry;
        }
		else
			UPDATEW(*root, value);	
        return;
    }

    p = *root;
    while (p->next != NULL) {
        pn = p->next;
        cmp = strcmp(name, pn->name);
        if (cmp <= 0)
        {
            if (cmp < 0) {
                MAKEE(entry, name, value);
                entry->next = pn;
                p->next = entry;
            }
			else
				UPDATEW(pn, value);
            return;
        }
        p = pn;
    }
    MAKEE(entry, name, value);
    p->next = entry;
}

void rm(Entry **list, char *name)
{
    Entry *p, *pn;
    int cmp;

    if (*list == NULL)
        return;
    if ((cmp = strcmp((*list)->name, name)) >= 0) {
        if (!cmp) {
            p = *list;
            *list = (*list)->next;
            FREEE(p);
        }
        return;
    }

    p = *list;
    while (p->next != NULL) {
        pn = p->next;
        if ((cmp = strcmp(pn->name, name)) >= 0)
        {
            if (!cmp) {
                p->next = pn->next;
                FREEE(pn);
            }
            return ;
        }
        p = pn;
    }
}

void show(Entry *p, char *name)
{
    int cmp;

	while (p) {
		if ((cmp = strcmp(p->name, name)) >= 0) {
			if (!cmp) {
                printf("%s\n", p->value);
                return;
            }
            else
                break;
		}
		p = p->next;
	}
	printf("%s: Not found\n", name);
}