/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_catcher.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:41:22 by frthierr          #+#    #+#             */
/*   Updated: 2021/04/06 16:47:48 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SIGNAL_HANDLER_H

# define	SIGNAL_HANDLER_H

# include <signal.h>
# include <stdlib.h>
# include "hash_map.h"

t_hash_map	*g_hash_map_ptr;
char        **g_line;

void	sigint_catcher(int __attribute__((unused))i);

#endif