/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:46:04 by asoursou          #+#    #+#             */
/*   Updated: 2021/04/08 00:55:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdbool.h>
#include <stddef.h>

#define GLINE_INIT_BUFSIZE	1024
#define HASH_TABLE_POWER	19
#define HASH_TABLE_SIZE		(1 << HASH_TABLE_POWER)
#define HASH_TABLE_MASK		(HASH_TABLE_SIZE - 1)

#define MIN(A, B)	((A) < (B) ? (A) : (B))

typedef struct s_str
{
	const char	*s;
	size_t		n; // Avoid calls to strlen
}	t_str;

typedef enum e_rbcolor
{
	RB_BLACK,
	RB_RED
}	t_rbcolor;

typedef struct s_rbtree t_rbtree;
struct s_rbtree
{
	t_rbtree	*parent;
	t_rbtree	*left;
	t_rbtree	*right;
	t_rbcolor	color : 1;
	t_str		key;
	t_str		value;
};

typedef struct s_dict
{
	t_rbtree	*t[HASH_TABLE_SIZE];
}	t_dict;

// Add an entry in dictionnary, returns false on error (failed alloc)
bool dict_add(t_dict *d, const t_str *key, const t_str *value);

// Removes an entry in dictionnary
void dict_erase(t_dict *d, const t_str *key);

// Finds an entry in dictionnary, returns NULL if not found
const t_str *dict_find(const t_dict *d, const t_str *key);

// Finds an element in the red black tree matching key
t_rbtree *rbtree_find(t_rbtree *root, const t_str *key);

// Inserts an element in a red black tree
void rbtree_insert(t_rbtree **root, t_rbtree *element);

// Allocates memory for a new red black tree, val must be a deep copy
t_rbtree *rbtree_new(const t_str *key, const t_str *val);

// Removes an element from the red black tree 
void rbtree_remove(t_rbtree **root, t_rbtree *element);

// Compares 2 strings
int str_cmp(const t_str *a, const t_str *b);

// Initializes a string without deep copy
void str_init(t_str *s, const char *value, size_t n);
