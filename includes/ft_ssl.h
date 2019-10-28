/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:34:40 by seli              #+#    #+#             */
/*   Updated: 2019/10/28 16:00:47 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

#include "ft_md5.h"

#endif
