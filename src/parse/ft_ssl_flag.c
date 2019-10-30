/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:42:19 by seli              #+#    #+#             */
/*   Updated: 2019/10/29 20:38:07 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void flag_s_handler(t_parser_state *state)
{
	char *dgst;

	if (++(state->i_ac) >= state->ac)
	{
		printf("-s need a following string\n");
		exit(0);
	}
	dgst = state->dgst_func(state->av[state->ac]);
	print_hash(state, dgst);
	free(dgst);
	state->flag_s = 0;
}

void flag_p_handler(t_parser_state *state)
{
	char *msg, *dgst;

	if (!(msg = file_to_str(STDIN_FILENO)))
		return (void)printf("Failed To Read STDIN\n");
	dgst = state->dgst_func(msg);
	free(msg);
	printf("%s\n", dgst);
	free(dgst);
}
