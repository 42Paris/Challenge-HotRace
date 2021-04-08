

#include "HotRace.h"

#define MAXLINELEN 1024


void supprime(HashTable *ht, char *key)
{
    int index = hash_function(key);
    Ht_item* item = ht->items[index];
    if (item != NULL) {
        free_item(item);
        ht->items[index] = NULL;
    }
}
 
void print_search(HashTable* table, char* key) {
    char    *val;
    
    if ((val = ht_search(table, key)) == NULL)
    {
        printf("%s: Not found\n", key);
        return;
    }
    else
        printf("%s\n", val);
}
 
void print_table(HashTable* table) {
    int count = 0;
    printf("\nHash Table\n-------------------\n");
    for (int i=0; i<table->size; i++) {
        if (table->items[i])
        {
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i]->key, table->items[i]->value);
            count++;
            if (count >= table->count)
                break;
        }
    }
    printf("-------------------\n\n");
}

void process(HashTable *ht, char *line)
{
    char *separator;
    char *second_part;

    if (!line)
        return;
    if (line[0] == '!')
        supprime(ht, &line[1]);
    else if ((separator = strchr(line, '=')))
    {
        // Todo verifier que "=" ne soit pas en derniere case
        second_part =  &separator[1];
        *separator = '\0';
        ht_insert(ht, line, second_part);
    }
    else
    {
        print_search(ht, line);
    }
}

void parsing() {
    char *line = malloc(sizeof(char) * MAXLINELEN);
    size_t maxlen = MAXLINELEN;
    size_t len;
    HashTable* ht = create_table(CAPACITY);

    while (getline(&line, &maxlen, stdin) != -1) 
    {
        len = strlen(line);
        if (line[len-1] == '\n')
            line[len-1] = '\0';
        process(ht, line);
    }
}

int main() {
    parsing();
    return 0;
}