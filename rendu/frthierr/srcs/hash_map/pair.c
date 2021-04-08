/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:31:35 by frthierr          #+#    #+#             */
/*   Updated: 2021/04/08 10:44:44 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.h"
#include "stdio.h"

#define	INIT_PAIR(pair, line)\
			char * sep = strchr(line, '=');\
				pair.key = line;\
				if (sep) {\
					*sep = '\0';\
					sep++;\
					pair.value = sep;\
				}\
				else\
					pair.value = NULL;

void	init_pair(t_pair *pair, char *line) {
	char * sep = strchr(line, '=');
	pair->key = line;
	if (sep) {
		*sep = '\0';
		sep++;
		pair->value = sep;
	}
	else
		pair->value = NULL;
}
