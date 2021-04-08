/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashishae <ashishae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:39:06 by ashishae          #+#    #+#             */
/*   Updated: 2021/04/08 12:45:54 by ashishae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// # define TABLE_SIZE 1000000
# define BASICHASH_SUBSTR 10
#define TABLE_SIZE 1355000


typedef struct s_hashmap_node {
	const char *keyval;
	size_t eqSign;
	struct s_hashmap_node *next;
}			hashmap_node;

typedef struct s_hashmap
{
	hashmap_node *table[TABLE_SIZE];

}				hashmap;

int hn_cmp(hashmap_node *h, const char *key);
int hn_cmp_kv(hashmap_node *h, const char *kv, size_t eqSign);
hashmap_node *new_hnode(const char *kv, size_t eqSign);
hashmap *new_hashmap();
int hm_print(hashmap *h, const char *k);
void hm_put(hashmap *h, const char *kv, size_t eqSign);

void hm_remove(hashmap *h, const char *k);

#endif