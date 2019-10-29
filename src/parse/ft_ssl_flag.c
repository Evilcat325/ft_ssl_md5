/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:42:19 by seli              #+#    #+#             */
/*   Updated: 2019/10/29 14:42:53 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void flag_s_handler(t_parser_state *state)
{
	char *hash;

	if (++(state->i_ac) >= state->ac)
	{
		printf("-s need a following string\n");
		exit(0);
	}
	hash = state->dgst_func(state->av[state->ac]);
	print_hash(state, hash);
	//free hash
	state->flag_s = 0;
}

void flag_p_handler(t_parser_state *state)
{
	state->flag_p = 2;
}
