/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_catcher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:45:18 by frthierr          #+#    #+#             */
/*   Updated: 2021/04/07 13:52:56 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sigint_catcher.h"

void	sigint_catcher(int __attribute__((unused))i) {
	// if (g_hash_map_ptr)
	// 	free_data(g_hash_map_ptr);
	if (g_line && *g_line)
		free(*g_line);
	exit(1);
}
