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