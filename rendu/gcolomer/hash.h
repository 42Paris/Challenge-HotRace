/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcolomer <gcolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:19:31 by gcolomer          #+#    #+#             */
/*   Updated: 2021/04/05 15:19:31 by gcolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

typedef struct
{
	char			*key;
	char			*value;
	unsigned int	hashc;
	char			hash[9];
}			t_data;

typedef union
{
	char			temp[9];
	unsigned int	content[2];
}			t_cook;

typedef struct
{
	int nbo;
	int colision;
}		t_var;

typedef struct
{
	int a;
	int b;
	int c;
}					t_num;

int		hash_func(char *key);
int		comp_hash(t_data **tab, char *key, int len);

#endif
