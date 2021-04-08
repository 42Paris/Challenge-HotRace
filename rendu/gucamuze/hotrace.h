/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:31:47 by gucamuze          #+#    #+#             */
/*   Updated: 2021/04/08 13:24:51 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# define TABLE_SIZE 694200

# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

typedef struct	ht_node {
	char		*keyword;
	char		*value;
} 				t_node;

typedef struct	ht_list
{
	char		*keyword;
	char		*value;
	void		*next;
}				t_list;


typedef struct	HT  {
	t_node 		**nodes;
	t_list		**lists;
}				t_HT;

int				get_sign_index(char *str, int *index);
int				main(void);

unsigned		hash(char *str);
t_HT			*create_table();
void			free_table(t_HT *table);

char			*create_values(char *str, size_t size);
void			insert(t_HT *table, char *str, int sign_index);
char			*search(t_HT *table, char *keyword);
void			delete(t_HT *table, char *keyword);

t_node			*node_create(char *keyword, char *value);
void			node_delete(t_HT *table, unsigned int node_index);
void			node_free(t_node *node);

char			*list_search(t_list	*list_begin, char *keyword);
void			list_insert(t_list *list_begin, char *keyword, char *value);
void			list_delete(t_HT *table, char *keyword, unsigned int hash);
t_list			*list_create_item(char *keyword, char *value);
void			list_free_item(t_list *list_item);
void			list_free(t_list *list_begin);
void			__DEBUG_print_list(t_list *list_begin);


#endif