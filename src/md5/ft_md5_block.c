/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:21:37 by seli              #+#    #+#             */
/*   Updated: 2019/10/29 23:34:06 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static uint32_t g_r[] ={
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

static uint32_t g_k[] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

static uint32_t ft_left_rotate(t_MD5_CTX *ctx, uint32_t round)
{
	uint32_t x, c;

	x = ctx->a + ctx->f + g_k[round] + ctx->words[ctx->g];
	c = g_r[round];
	return (((x) << (c)) | ((x) >> (32 - (c))));
}

void ft_md5_block_body(t_MD5_CTX *ctx)
{
	int round = -1;

	while (++round < 64)
	{
		if (round < 16) {
			ctx->f = (ctx->b & ctx->c) | ((~ctx->b) & ctx->d);
			ctx->g = round;
		} else if (round < 32) {
			ctx->f = (ctx->d & ctx->b) | ((~ctx->d) & ctx->c);
			ctx->g = (5*round + 1) % 16;
		} else if (round < 48) {
			ctx->f = ctx->b ^ ctx->c ^ ctx->d;
			ctx->g = (3*round + 5) % 16;
		} else {
			ctx->f = ctx->c ^ (ctx->b | (~ctx->d));
			ctx->g = (7*round) % 16;
		}
		ctx->temp = ctx->d;
		ctx->d = ctx->c;
		ctx->c = ctx->b;
		ctx->b += ft_left_rotate(ctx, round);
		ctx->a = ctx->temp;
	}
}

void ft_md5_block_init(t_MD5_CTX *ctx)
{
	ctx->a = ctx->digest[0];
	ctx->b = ctx->digest[1];
	ctx->c = ctx->digest[2];
	ctx->d = ctx->digest[3];
	ctx->words = (uint32_t *)(ctx->msg + ctx->num_block * 64);
}

void ft_md5_block_final(t_MD5_CTX *ctx)
{
	ctx->digest[0] += ctx->a;
	ctx->digest[1] += ctx->b;
	ctx->digest[2] += ctx->c;
	ctx->digest[3] += ctx->d;
}

void ft_md5_block(t_MD5_CTX *ctx)
{
	ft_md5_block_init(ctx);
	ft_md5_block_body(ctx);
	ft_md5_block_final(ctx);
}
