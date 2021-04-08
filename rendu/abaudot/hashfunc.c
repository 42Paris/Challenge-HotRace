/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:45:03 by abaudot           #+#    #+#             */
/*   Updated: 2021/04/07 22:22:46 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*---------------------------------------------------------------------------*/
/* SipHash reference C implementation										 */
/*																			 */
/* Copyright (c) 2012-2016 Jean-Philippe Aumasson							 */
/* <jeanphilippe.aumasson@gmail.com>										 */
/* Copyright (c) 2012-2014 Daniel J. Bernstein <djb@cr.yp.to>				 */
/*																			 */
/*	https://github.com/veorq/SipHash/blob/master/siphash.c					 */
/*---------------------------------------------------------------------------*/
#include "hashmap.h"

#define U64TO8_LE(p, v) \
    { U32TO8_LE((p), (uint32_t)((v))); \
      U32TO8_LE((p) + 4, (uint32_t)((v) >> 32)); }

#define U32TO8_LE(p, v) \
    { (p)[0] = (uint8_t)((v)); \
      (p)[1] = (uint8_t)((v) >> 8); \
      (p)[2] = (uint8_t)((v) >> 16); \
      (p)[3] = (uint8_t)((v) >> 24); }

#define ROTL(x, b) (uint64_t)(((x) << (b)) | ((x) >> (64 - (b))))

#define SIPROUND \
    { v0 += v1; v1 = ROTL(v1, 13); \
      v1 ^= v0; v0 = ROTL(v0, 32); \
      v2 += v3; v3 = ROTL(v3, 16); \
      v3 ^= v2; \
      v0 += v3; v3 = ROTL(v3, 21); \
      v3 ^= v0; \
      v2 += v1; v1 = ROTL(v1, 17); \
      v1 ^= v2; v2 = ROTL(v2, 32); }

uint64_t spihash(const uint8_t *in, const size_t inlen) 
{
    uint64_t v3 = 0x7465646279746573UL;
    uint64_t v2 = 0x6c7967656e657261UL;
    uint64_t v1 = 0x646f72616e646f6dUL;
    uint64_t v0 = 0x736f6d6570736575UL;
    const uint8_t *end = in + inlen - (inlen & 7);
    for (; in != end; in += 8) {
        uint64_t m = *(uint64_t*)(in);
        v3 ^= m;
        SIPROUND; SIPROUND;
        v0 ^= m;
    }
    const int left = inlen & 7;
    uint64_t b = ((uint64_t)inlen) << 56;
    switch (left) {
    case 7: b |= ((uint64_t)in[6]) << 48;
    case 6: b |= ((uint64_t)in[5]) << 40;
    case 5: b |= ((uint64_t)in[4]) << 32;
    case 4: b |= ((uint64_t)in[3]) << 24;
    case 3: b |= ((uint64_t)in[2]) << 16;
    case 2: b |= ((uint64_t)in[1]) << 8;
    case 1: b |= ((uint64_t)in[0]);break;
    case 0: break;
    }
    v3 ^= b;
    SIPROUND; SIPROUND;
    v0 ^= b;
    v2 ^= 0xff;
    SIPROUND; SIPROUND; SIPROUND; SIPROUND;
    b = v0 ^ v1 ^ v2 ^ v3;
    uint64_t out = 0;
    U64TO8_LE((uint8_t*)&out, b);
    return out;
}
