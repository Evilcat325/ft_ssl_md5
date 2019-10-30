/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 22:29:51 by seli              #+#    #+#             */
/*   Updated: 2019/10/29 22:32:00 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include <stdint.h>
# include <stdio.h>
# include "ft_struct.h"
# include "libft.h"

void ft_md5_block_body(t_MD5_CTX *ctx);
void ft_md5_block_init(t_MD5_CTX *ctx);
void ft_md5_block_final(t_MD5_CTX *ctx);
void ft_md5_block(t_MD5_CTX *ctx);

void ft_md5_padding(t_MD5_CTX *ctx, uint8_t *msg);
void ft_md5_init(t_MD5_CTX *ctx, uint8_t *msg);
void ft_md5_final(t_MD5_CTX *ctx);

#endif
