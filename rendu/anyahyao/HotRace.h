#ifndef _HOTRACE_H__
# define _HOTRACE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define CAPACITY 1e9 + 9
// Size of the Hash Table

typedef struct Ht_item      Ht_item;
typedef struct HashTable    HashTable;
 
// Define the Hash Table Item here
typedef struct  Ht_item 
{
    char*       key;
    char*       value;
}               t_element;
 
// Define the Hash Table here
typedef struct HashTable
{
    // Contains an array of pointers
    // to items
    Ht_item**   items;
    int         size;
    int         count;
}               t_hashTable;
 
unsigned long hash_function(char* str);
Ht_item* create_item(char* key, char* value);
HashTable* create_table(int size);
void free_item(Ht_item* item);
void free_table(HashTable* table);
void handle_collision(HashTable* table, unsigned long index, Ht_item* item);
void ht_insert(HashTable *table, char *key, char *value);
char* ht_search(HashTable* table, char* key);
#endif