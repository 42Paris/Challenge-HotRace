#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifndef HASHMAP_CAPACITY
# define HASHMAP_CAPACITY 10000
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

# define EMPTY_NODE (0xDEADBEEF)

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

/* If key is already present, do nothing */
bool hashmap_add(t_hashmap* map, const t_string* key, const t_string* value)
{
    size_t hash = fnv1a_32(*key);
    t_hm_node* dest = map->data + (hash % map->capacity);

    if (dest->next != EMPTY_NODE)
    {
        while (dest->next != NULL && dest->hash != hash && strcmp(key->string, dest->key.string) != 0)
            dest = dest->next;

//        t_hm_node* new = malloc(sizeof(t_hm_node));

        new->next = dest->next;
        dest->next = new;
        dest = new;
    }
    dest->hash = hash;
    dest->key.string = hm_memdup();
}

bool hashmap_get(t_hashmap* map, const t_string* key)
{
    size_t hash = fnv1a_32(*key);
    t_hm_node
}

int main(void)
{
    t_string line = STRING_NULL;
    size_t getline_size;
    ssize_t  read;
    t_hashmap map;
    size_t equal;
    t_string key, value;

    if (!(map.data = malloc(sizeof(t_hm_node) * HASHMAP_CAPACITY)))
        return 1;
    map.capacity = HASHMAP_CAPACITY;
    map.size = 0;
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
//            hm_remove(line.string + 1, line.length - 1);
            printf("Remove '%.*s'\n", (int)key.length, key.string);
        }
        else
        {
            equal = 0;
            while (line.string[equal] != '\0' && line.string[equal] != '=')
                ++equal;
            if (line.string[equal] == '\0')
            {
                printf("Look for '%.*s'\n", (int)line.length, line.string);
//                if (hm_get(&line, &value))
//                    printf("%*s: %*s\n", line.length, line.string, value.length, value.string);
            }
            else
            {
                key.string = line.string;
                key.length = equal;
                value.string = line.string + equal + 1;
                value.length = line.length - equal - 1;
                printf("Set '%.*s' as '%.*s'\n", (int)key.length, key.string, (int)value.length, value.string);
                hashmap_add(&map, &key, &value);
            }
        }

    }
    free(line.string);
    return 0;
}
