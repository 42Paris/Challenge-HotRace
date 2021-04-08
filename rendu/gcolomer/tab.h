/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolomer <gcolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:30:41 by gcolomer          #+#    #+#             */
/*   Updated: 2021/04/08 11:30:41 by gcolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_H
# define TAB_H

# include "hash.h"

void	clean(t_data **data, int len);
t_data	**new_tab(t_data **old, int *len);
t_data	**create_tab(int *len);

#endif
