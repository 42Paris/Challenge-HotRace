#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifndef HASHMAP_CAPACITY
# define HASHMAP_CAPACITY 16384
#endif

typedef struct string
{
    char*  string;
    size_t length;
} t_string;

#define STRING(STR, LEN) (t_string){ .string = STR, .length = LEN }
#define STRING_NULL STRING(NULL, 0)

typedef struct hm_node
{
    struct hm_node* next;
    t_string key;
    t_string value;
    size_t   hash;
} t_hm_node;

# define EMPTY_NODE (void*)(0xDEADBEEF)

typedef struct hashmap
{
    t_hm_node* data;
    size_t capacity;
    size_t size;
} t_hashmap;

size_t fnv1a_32(t_string key)
{
    size_t hash;
    size_t c;

    hash = 2166136261;
    while (key.length --> 0)
    {
        c = (unsigned char)*(key.string)++;
        hash ^= c;
        hash *= 16777619;
    }
    return hash;
}

void* ft_memdup(const void* src, size_t len)
{
    void* dst;
    char* tmp;

    if ((dst = malloc(len)))
    {
        tmp = dst;
        while (len --> 0)
            *tmp++ = *(const char *)(src++);
    }
    return dst;
}

bool hashmap_remove(t_hashmap* map, const t_string* key)
{
    size_t hash = fnv1a_32(*key);
    t_hm_node* ptr = map->data + (hash % map->capacity);
    t_hm_node* prev = NULL;

    if (ptr->next == EMPTY_NODE)
        return false;
    while (ptr != NULL
           && (ptr->hash != hash || strncmp(key->string, ptr->key.string, key->length) != 0))
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
        return false;
    free(ptr->key.string);
    free(ptr->value.string);
    if (prev == NULL)
        ptr->next = EMPTY_NODE;
    else
        prev->next = ptr->next;
    return true;
}

/* If key is already present, do nothing */
bool hashmap_add(t_hashmap* map, const t_string* key, const t_string* value)
{
    size_t hash = fnv1a_32(*key);
    t_hm_node* dest = map->data + (hash % map->capacity);
    t_hm_node* prev = NULL;

    if (dest->next != EMPTY_NODE)
    {
        while (dest != NULL
               && (dest->hash != hash || strncmp(key->string, dest->key.string, key->length) != 0))
        {
            prev = dest;
            dest = dest->next;
        }
        if (dest != NULL)
            return false;
        dest = malloc(sizeof(t_hm_node));
        prev->next = dest;
    }
    dest->next = NULL;
    dest->hash = hash;
    dest->key.string = ft_memdup(key->string, key->length + 1);
    dest->key.string[key->length] = '\0';
    dest->key.length = key->length;
    dest->value.string = ft_memdup(value->string, value->length + 1);
    dest->value.string[value->length] = '\0';
    dest->value.length = value->length;
    return true;
}

bool hashmap_get(const t_hashmap* map, const t_string* key, t_string* out_result)
{
    size_t hash = fnv1a_32(*key);
    const t_hm_node* ptr = map->data + (hash % map->capacity);

    if (ptr->next == EMPTY_NODE)
        return false;
    while (ptr != NULL
           && (ptr->hash != hash || strncmp(key->string, ptr->key.string, key->length) != 0))
        ptr = ptr->next;
    if (ptr == NULL)
        return false;
    *out_result = ptr->value;
    return true;
}

int main(void)
{
    t_string line = STRING_NULL;
    size_t getline_size;
    ssize_t  read;
    t_hashmap map;
    size_t equal;
    t_string key, value;

    if (!(map.data = calloc(HASHMAP_CAPACITY, sizeof(t_hm_node))))
        return 1;
    map.capacity = HASHMAP_CAPACITY;
    map.size = 0;
    for (unsigned i = 0; i < map.capacity; i++)
        map.data[i].next = EMPTY_NODE;

    printf("Node size : %lu\n", sizeof(t_hm_node));
    while ((read = getline(&(line.string), &getline_size, stdin)) >= 0)
    {
        line.length = strlen(line.string);
        if (line.length < 2)
            continue;
        line.length -= 1; /* Remove the trailing '\n' */
        if (line.string[0] == '!')
        {
            key.string = line.string + 1;
            key.length = line.length - 1;
            bool ret = hashmap_remove(&map, &key);
            printf("Remove '%.*s' : %i\n", (int)key.length, key.string, ret);
        }
        else
        {
            equal = 0;
            while (line.string[equal] != '\0' && line.string[equal] != '=')
                ++equal;
            if (line.string[equal] == '\0')
            {
                printf("Look for '%.*s'\n", (int)line.length, line.string);
                if (hashmap_get(&map, &line, &value))
                    printf("%.*s\n", (int)value.length, value.string);
                else
                    printf("%.*s: Not Found\n", (int)line.length, line.string);
            }
            else
            {
                key.string = line.string;
                key.length = equal;
                value.string = line.string + equal + 1;
                value.length = line.length - equal - 1;
                bool ret = hashmap_add(&map, &key, &value);
                printf("Set '%.*s' as '%.*s' : %i\n", (int)key.length, key.string, (int)value.length, value.string, ret);
            }
        }

    }
    free(line.string);
    return 0;
}
