/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_digest.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:49:39 by seli              #+#    #+#             */
/*   Updated: 2019/10/29 22:32:04 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MESSAGE_DIGEST_H
# define FT_MESSAGE_DIGEST_H

# include <stdio.h>
# include <string.h>
# include "ft_struct.h"

char	*ft_md5(char* msg);
char	*ft_sha(char* msg);

t_dgst_t parse_dgst(t_parser_state* state, int ac, char* av[]);

#endif
