/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_digest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:55:46 by seli              #+#    #+#             */
/*   Updated: 2019/10/29 15:56:50 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_message_digest.h"

t_dgst_t parse_dgst(t_parser_state* state, int ac, char* av[])
{
	if (state->i_ac >= ac)
		return NULL;
	else if (strcmp(av[state->i_ac], "md5") == 0 && state->i_ac++)
		return ft_md5;
	else if (strcmp(av[state->i_ac], "sha") == 0 && state->i_ac++)
		return ft_sha;
	else
		return NULL;
}
