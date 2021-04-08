/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:36:01 by frthierr          #+#    #+#             */
/*   Updated: 2021/04/08 09:12:48 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_LST_H

# define	FT_LST_H

# include <stdlib.h>
# include "pair.h"
typedef struct	s_list {
	char			*key;
	char			*value;
	struct s_list	*next;
}				t_list;

void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst);
void		ft_lstdelone(t_list *lst);
t_list		*ft_lstnew(t_pair *pair);


#endif