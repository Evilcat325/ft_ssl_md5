/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:48:37 by seli              #+#    #+#             */
/*   Updated: 2019/10/29 22:55:35 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void ft_md5_padding(t_MD5_CTX *ctx, uint8_t *msg)
{
	uint64_t bits_len;

	bits_len = ctx->init_len * 8;
	ctx->msg = (uint8_t *)ft_strnew(ctx->padded_len + 8);
	ft_memcpy(ctx->msg, msg, ctx->init_len);
	ctx->msg[ctx->init_len] = 0b10000000;
	ft_memcpy(ctx->msg + ctx->padded_len, &bits_len, 8);
	ctx->rounds = (ctx->padded_len + 8) / 64;
}

void ft_md5_init(t_MD5_CTX *ctx, uint8_t *msg)
{
	ft_bzero(ctx, sizeof(ctx));
	ctx->digest[0] = 0x67452301;
	ctx->digest[1] = 0xefcdab89;
	ctx->digest[2] = 0x98badcfe;
	ctx->digest[3] = 0x10325476;
	ctx->num_block = 0;
	ctx->init_len = ft_strlen((const char *)msg);
	ctx->padded_len = ((((ctx->init_len + 8) / 64) + 1) * 64) - 8;
}

void ft_md5_final(t_MD5_CTX *ctx)
{
	uint8_t i, *as_byte;
	char hex[3];

	as_byte = (uint8_t *)ctx->digest;
	i = 0;
	ctx->result = (uint8_t *)ft_strnew(0);
	while (i < 16)
	{
		sprintf(hex, "%2.2x", as_byte[i]);
		ctx->result = (uint8_t *)ft_strjoin_free((char *)ctx->result, hex, TRUE, FALSE);
		i++;
	}
}

char *ft_md5(char* msg)
{
	t_MD5_CTX			ctx;

	ft_md5_init(&ctx, (uint8_t *)msg);
	ft_md5_padding(&ctx, (uint8_t *)msg);
	while (ctx.num_block < ctx.rounds)
	{
		ft_md5_block(&ctx);
		ctx.num_block++;
	}
	ft_md5_final(&ctx);
	return (char *)ctx.result;
}
