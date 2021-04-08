/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolomer <gcolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:33:25 by gcolomer          #+#    #+#             */
/*   Updated: 2021/04/05 15:33:25 by gcolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLOT_H
# define SLOT_H
# include "hash.h"

int		add(t_data **tab, t_data *data, int len);
void	remove_data(t_data **tab, char *line, int len, int nbo);
int		search(t_data **tab, char *line, int len, int nbo);
t_data	*init_struct(char *line);
#endif
