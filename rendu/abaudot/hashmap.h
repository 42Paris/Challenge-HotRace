/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:52:38 by abaudot           #+#    #+#             */
/*   Updated: 2021/04/07 22:05:11 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
#define HASHMAP_H

# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdint.h>

/*
**	sizeof s_bckt && t_str
*/
# define BCKTSZ	24
# define STRSZ	16

struct s_bckt
{
	uint64_t hash:48;
	uint64_t dib:16;
};

typedef struct	s_str
{
	char	*s;
	uint32_t key;
	uint32_t len;
}				t_str;

struct s_map
{
	uint64_t	cap;
	uint64_t	nbckts;
	uint64_t	count;
	uint64_t	mask;
	uint64_t	grwat;
	uint64_t	shrnkat;
	void		*bckts;
	void		*tmp;
	void		*edata;
};

/*
**	Hash function
*/
uint64_t		spihash(const uint8_t *in, const uint64_t inlen);

/*
** Hashmap functions
*/
struct s_map	*new_(size_t cap);
void			*get_(struct s_map *map, void *item);
uint8_t			add_(struct s_map *map, void *item);
void			*del_(struct s_map *map, void *item);
void			clean_(struct s_map *map);
#endif
