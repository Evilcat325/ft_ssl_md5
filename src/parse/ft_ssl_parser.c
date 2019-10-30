/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:43:40 by seli              #+#    #+#             */
/*   Updated: 2019/10/29 22:58:11 by seli             ###   ########.fr       */
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

char *file_to_str(int fd)
{
	char *str;
	char buf[BUF_SIZE + 1];
	int ret;

	str = ft_strnew(0);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = 0;
		str = ft_strjoin_free(str, buf, TRUE, FALSE);
	}
	return str;
}

void parse_file(t_parser_state *state)
{
	int fd;
	char *msg, *dgst;

	if ((fd = open(state->av[state->i_ac], O_RDONLY)) < 0)
		return (void)printf("Failling to open %s\n", state->av[state->i_ac++]);
	if (!(msg = file_to_str(fd)))
		return (void)printf("Failling to read %s\n", state->av[state->i_ac++]);
	state->i_ac++;
	dgst = state->dgst_func(msg);
	printf("%s\n", dgst);
	// free(dgst);
}
