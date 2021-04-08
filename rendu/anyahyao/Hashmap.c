# include "HotRace.h"

unsigned long hash_function(char* str) {
    // P et M 2 nombre premier
    int p = 127;
    int m = CAPACITY;
    long long power_of_p = 1;
    long long hash_val = 0;
    
    // calcul la valeur de hashage
    for (int i = 0; str[i]; i++)
    {
        hash_val = (hash_val + (str[i] -5) * power_of_p) % m;
        power_of_p = (power_of_p * p) % m;
    }
    return hash_val;
}

Ht_item* create_item(char* key, char* value) {
    Ht_item *item = (Ht_item*)malloc(sizeof(Ht_item));
    item->key = (char*)malloc(strlen(key) + 1);
    item->value = (char*)malloc(strlen(value) + 1);
    strcpy(item->key, key);
    strcpy(item->value, value);
    return item;
}
 
HashTable* create_table(int size)
{
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item**)calloc(table->size, sizeof(Ht_item*));
    return table;
}
 
void free_item(Ht_item* item) {
    free(item->key);
    free(item->value);
    free(item);
}
 
void free_table(HashTable* table) {
    for (int i=0; i<table->size; i++) {
        Ht_item* item = table->items[i];
        if (item != NULL)
            free_item(item);
    }
    free(table->items);
    free(table);
}
 
void handle_collision(HashTable* table, unsigned long index, Ht_item* item) {
    (void) table;
    (void) index;
    (void) item;
    // prions ensemble que cela n'arrive jamais !
}
 
void ht_insert(HashTable *table, char *key, char *value)
{
    Ht_item         *item;
    unsigned long   index = hash_function(key);
    Ht_item         *current_item = table->items[index];
     
    if (current_item == NULL)
    {
        if (table->count == table->size)
        {
            // Test vraiment abusez
            printf("Insert Error: Hash Table is full\n");
            exit(1);
        }
        item = create_item(key, value);
        table->items[index] = item; 
        table->count++;
    }
    else
    {
        if (strcmp(current_item->key, key))
        {
            item = create_item(key, value);
            handle_collision(table, index, item);
        }
    }
}
 
char* ht_search(HashTable* table, char* key) {

    int index = hash_function(key);
    Ht_item* item = table->items[index];
 
    if (item != NULL) {
        if (strcmp(item->key, key) == 0)
            return item->value;
    }
    return NULL;
}
 