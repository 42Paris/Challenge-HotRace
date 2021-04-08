/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:55:42 by eparisot          #+#    #+#             */
/*   Updated: 2021/04/06 14:55:42 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

void sig_handler(int signum) {
	if (signum == SIGINT) {
		free(*g_env->buf);
		cleanup();
		exit(0);
	}
}

void init_env() {
	if ((g_env = malloc(sizeof(t_env))) == NULL) {
		exit(0);
	}
	g_env->buf = NULL;
	g_env->index_table = NULL;
	g_env->data_table = NULL;
	if ((g_env->buf = malloc(sizeof(char*))) == NULL) {
		free(g_env);
		exit(0);
	}
	if ((g_env->index_table = ft_lstnew(NULL, sizeof(t_index_slot))) == NULL) {
		cleanup();
		exit(0);
	}
		if ((g_env->data_table = ft_lstnew(NULL, sizeof(t_data_slot))) == NULL) {
		cleanup();
		exit(0);
	}
}

unsigned long calc_hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

void del_data(void *addr, size_t size)
{
	(void)size;
	if ((t_data_slot*)addr) {
		free(((t_data_slot*)addr)->key);
		free(((t_data_slot*)addr)->val);
	}
	free(addr);
}

void del(void *addr, size_t size)
{
	(void)size;
	free(addr);
}

void cleanup() {
	free(g_env->buf);
	ft_lstdel(&g_env->index_table, del);
	ft_lstdel(&g_env->data_table, del_data);
	free(g_env);
}