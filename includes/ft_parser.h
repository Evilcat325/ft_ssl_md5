/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:10:40 by seli              #+#    #+#             */
/*   Updated: 2019/10/29 19:47:17 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_struct.h"
# include "libft.h"

void	flag_s_handler(t_parser_state *state);
void	flag_p_handler(t_parser_state *state);
int		parse_option(t_parser_state *state);
void	parse_file(t_parser_state *state);
char	*file_to_str(int fd);

#endif
