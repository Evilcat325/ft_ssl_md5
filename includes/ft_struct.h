/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:02:13 by seli              #+#    #+#             */
/*   Updated: 2019/10/29 22:46:26 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# include <stdint.h>

typedef char	*(*t_dgst_t)(char *msg);

typedef struct		s_parser_state
{
	int						i_ac;
	int						ac;
	char					**av;
	t_dgst_t				dgst_func;
	char					*err;

	unsigned int	flag_r;
	unsigned int	flag_p;
	unsigned int	flag_q;
	unsigned int	flag_s;
}					t_parser_state;

typedef struct s_md5_ctx {
	uint64_t			num_block, init_len, padded_len, rounds;
	uint32_t			a,b,c,d,f,g,temp,*words;
	uint32_t			digest[4];
	uint8_t				*msg, *result;
} t_MD5_CTX;

# define BUF_SIZE 2048

#endif
