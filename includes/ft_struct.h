/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:02:13 by seli              #+#    #+#             */
/*   Updated: 2019/10/29 15:12:02 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

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

#endif
