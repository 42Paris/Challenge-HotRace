/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <fbecerri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:51:25 by fbecerri          #+#    #+#             */
/*   Updated: 2021/04/07 10:24:11 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H

# define FT_STRING_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "io_write.h"

typedef struct	s_string {
	int		index;
	size_t	len;
	char	*buffer;
}				t_string;

t_string		create_string(char *buf, size_t len);
t_string		join_string(t_string s1, t_string s2);
void			print_string(t_write *r, t_string s1);
bool			ft_strcmp(t_string s1, t_string s2);

#endif
