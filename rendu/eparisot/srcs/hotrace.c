/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:55:42 by eparisot          #+#    #+#             */
/*   Updated: 2021/04/06 14:55:42 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

int add_entry(char *l_member, char *r_member, unsigned long hash) {
	t_data_slot new_data_slot;
	t_index_slot new_index_slot;
	t_list *new_data_node;
	t_list *new_index_node;
	t_list *tmp_data_lst = g_env->data_table;
	t_list *tmp_index_lst = g_env->index_table;
	int index_idx = 0;

	new_data_slot.key = ft_strdup(l_member);
	new_data_slot.val = ft_strdup(r_member);
	new_data_slot.hash = hash;
	new_data_slot.deleted = 0;
	if ((new_data_node = ft_lstnew(&new_data_slot, sizeof(t_data_slot))) == NULL) {
		free(new_data_slot.key);
		free(new_data_slot.val);
		return -1;
	}
	// find the right place to append the node
	if (tmp_data_lst->next) {
		while (tmp_index_lst->next) {
			// if smaller than the smallest data
			if ((index_idx == 0 && hash < ((t_index_slot*)tmp_index_lst->content)->start_hash)) {
				ft_lstadd(&g_env->data_table, new_data_node);
				if (((t_index_slot*)tmp_index_lst->content)->nb_nodes < CHUNK_SIZE) {
					((t_index_slot*)tmp_index_lst->content)->start_addr = new_data_node;
					((t_index_slot*)tmp_index_lst->content)->start_hash = hash;
					((t_index_slot*)tmp_index_lst->content)->nb_nodes++;
				} else {
					new_index_slot.start_hash = hash;
					new_index_slot.start_addr = new_data_node;
					new_index_slot.nb_nodes = 1;
					if ((new_index_node = ft_lstnew(&new_index_slot, sizeof(t_index_slot))) == NULL) {
						return -1;
					}
					ft_lstadd(&g_env->index_table, new_index_node);
					g_env->index_table = new_index_node;
				}
			} else if (hash >= ((t_index_slot*)tmp_index_lst->content)->start_hash && (tmp_index_lst->next->content == NULL || hash < ((t_index_slot*)tmp_index_lst->next->content)->start_hash)) {
				tmp_data_lst = (t_list*)((t_index_slot*)tmp_index_lst->content)->start_addr;
				while (tmp_data_lst->next) {
					// if data already exists
					if (hash == ((t_data_slot*)tmp_data_lst->content)->hash) {
						if (ft_strcmp(l_member, ((t_data_slot*)tmp_data_lst->content)->key)) {
							printf("COLLISION !\n");
							exit(1);
						}
						if (((t_data_slot*)tmp_data_lst->content)->deleted == 0) {
							free(new_data_node->content);
							free(new_data_node);
							free(new_data_slot.key);
							free(new_data_slot.val);
							return 0;
						} else {
							new_data_slot.deleted = 0;
							return 0;
						}
					}
					// else append data
					if (hash >= ((t_data_slot*)tmp_data_lst->content)->hash && (tmp_data_lst->next->content == NULL || hash < ((t_data_slot*)tmp_data_lst->next->content)->hash)) {
						new_data_node->next = tmp_data_lst->next;
						tmp_data_lst->next = new_data_node;
						// if enought place in indexes
						if (((t_index_slot*)tmp_index_lst->content)->nb_nodes < CHUNK_SIZE) {
							if (((t_index_slot*)tmp_index_lst->content)->start_hash > hash) {
								((t_index_slot*)tmp_index_lst->content)->start_hash = hash;
								((t_index_slot*)tmp_index_lst->content)->start_addr = new_data_node;
							}
							((t_index_slot*)tmp_index_lst->content)->nb_nodes++;
						// if not enought place in indexes
						} else {
							new_index_slot.start_hash = hash;
							new_index_slot.start_addr = new_data_node;
							int remaining = 0;
							tmp_data_lst = new_data_node;
							while (tmp_data_lst && tmp_data_lst->content && (tmp_data_lst->next != NULL || (tmp_index_lst->next->content && tmp_data_lst != ((t_index_slot*)tmp_index_lst->next->content)->start_addr))) {
								remaining++;
								tmp_data_lst = tmp_data_lst->next;
							}
							new_index_slot.nb_nodes = remaining + 1;
							if ((new_index_node = ft_lstnew(&new_index_slot, sizeof(t_index_slot))) == NULL) {
								return -1;
							}
							new_index_node->next = tmp_index_lst->next;
							tmp_index_lst->next = new_index_node;
							((t_index_slot*)tmp_index_lst->next->content)->nb_nodes -= remaining;
						}
						break;
					}
					tmp_data_lst = tmp_data_lst->next;
				}
				break;
			}
			tmp_index_lst = tmp_index_lst->next;
			index_idx++;
		}
	} else {
		ft_lstadd(&g_env->data_table, new_data_node);
		new_index_slot.start_hash = hash;
		new_index_slot.start_addr = new_data_node;
		new_index_slot.nb_nodes = 1;
		if ((new_index_node = ft_lstnew(&new_index_slot, sizeof(t_index_slot))) == NULL) {
			return -1;
		}
		ft_lstadd(&g_env->index_table, new_index_node);
		g_env->index_table = new_index_node;
	}
	return 0;
}

char *get_entry(unsigned long hash) {
	t_list *tmp_data_lst = g_env->data_table;
	t_list *tmp_index_lst = g_env->index_table;

	while (tmp_index_lst->next) {
		if (hash >= ((t_index_slot*)tmp_index_lst->content)->start_hash && (tmp_index_lst->next->content == NULL || hash < ((t_index_slot*)tmp_index_lst->next->content)->start_hash)) {
			tmp_data_lst = (t_list*)((t_index_slot*)tmp_index_lst->content)->start_addr;
			while (tmp_data_lst->next) {
				if (hash == ((t_data_slot*)tmp_data_lst->content)->hash) {
					if (((t_data_slot*)tmp_data_lst->content)->deleted == 0) {
						return ((t_data_slot*)tmp_data_lst->content)->val;
					}
				}
				tmp_data_lst = tmp_data_lst->next;
			}
		}
		tmp_index_lst = tmp_index_lst->next;
	}
	return NULL;
}

void del_entry(unsigned long hash) {

	t_list *tmp_data_lst = g_env->data_table;
	t_list *tmp_index_lst = g_env->index_table;

	while (tmp_index_lst->next) {
		if (hash >= ((t_index_slot*)tmp_index_lst->content)->start_hash && (tmp_index_lst->next->content == NULL || hash < ((t_index_slot*)tmp_index_lst->next->content)->start_hash)) {
			tmp_data_lst = (t_list*)((t_index_slot*)tmp_index_lst->content)->start_addr;
			while (tmp_data_lst->next) {
				if (hash == ((t_data_slot*)tmp_data_lst->content)->hash) {
					((t_data_slot*)tmp_data_lst->content)->deleted = 1;
					break;
				}
				tmp_data_lst = tmp_data_lst->next;
			}
			break;
		}
		tmp_index_lst = tmp_index_lst->next;
	}
}

int handle_input(char *str) {
	char *l_member = NULL;
	char *r_member = NULL;
	int in = 0;
	int to_del = 0;
	unsigned long hash;
	char *res;

	if (ft_strlen(str) > 0 && str[0] == '!') {
		to_del = 1;
	}
	r_member = ft_strchr(str, '=');
	if(r_member) {
		in = 1;
		size_t index = r_member - str;
		
		if ((l_member = ft_strdup(str)) == NULL) {
			return -1;
		}
		for (size_t i = 0; i < ft_strlen(str); ++i) {
			if (i >= index) {
				l_member[i] = '\0';
			}
		}
	} else {
		l_member = str;
	}
	hash = calc_hash((to_del) ? (unsigned char *)l_member + 1 : (unsigned char *)l_member);
	// handle setting key/val
	if (r_member) {
		r_member++;
		if (add_entry(l_member, r_member, hash)) {
			if (in)
				free(l_member);
			return -1;
		}
	// handle getting key/val
	} else if (to_del == 0) {
		if ((res = get_entry(hash)) == NULL) {
			printf("%s: Not found\n", l_member);
		} else {
			printf("%s\n", res);
		}
	// handle removing key/val
	} else {
		l_member++;
		del_entry(hash);
	}
	if (in)
		free(l_member);
	return 0;
}

int main(void) 
{
	init_env();
	signal(SIGINT, sig_handler);
	while (get_next_line(0, g_env->buf) > 0) {
		if (handle_input(*g_env->buf)) {
			free(*g_env->buf);
			break;
		}
		free(*g_env->buf);
	}
	cleanup();
	return 0;
}