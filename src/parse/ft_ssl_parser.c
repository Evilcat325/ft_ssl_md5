/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:43:40 by seli              #+#    #+#             */
/*   Updated: 2019/10/29 15:53:39 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int parse_option(t_parser_state *state)
{
	char	*flag;

	if (state->i_ac >= state->ac || state->av[state->i_ac][0] != '-')
		return 0;
	flag = state->av[state->i_ac];
	while (*(++flag))
		if (*flag == 'r')
			state->flag_r = 1;
		else if (*flag == 'p' && state->flag_p == 0)
		 	state->flag_p = 1; //handle stdin
		else if (*flag == 'q')
			state->flag_q = 1;
		else if (*flag == 's')
			state->flag_s = 1;
		else
		{
			state->err = "Invalid Flag";
			exit(0);
			return 0;
		}
	return 1;
}

void parse_file(t_parser_state *state)
{
	state->i_ac++;
	printf("%s\n", state->dgst_func(""));
}
