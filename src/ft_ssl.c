#include <stdio.h>
#include <string.h>
#include "ft_ssl.h"

char *ft_md5(char* msg)
{
	(void)msg;
	return "md54567890123456";
}

char *ft_sha1(char *msg)
{
	(void)msg;
	return "sha1567890123456";
}

t_dgst parse_dgst(t_parser_state* state, int ac, char* av[])
{
	if (state->i_ac >= ac)
		return NULL;
	else if (strcmp(av[state->i_ac], "md5") == 0 && state->i_ac++)
		return ft_md5;
	else if (strcmp(av[state->i_ac], "sha1") == 0 && state->i_ac++)
		return ft_sha1;
	else
		return NULL;
}

int parse_option(t_parser_state *state)
{
	int		i;
	char	*flag;

	if (state->i_ac >= state->ac || state->av[state->i_ac][0] != '-')
		return 0;
	flag = &state->av[state->i_ac];
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
			return 0;
		}
	return 1;
}

int parse_file(t_parser_state *state)
{

}

void print_hash(t_parser_state *state, char *hash)
{
}

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

int main(int ac, char** av)
{
	t_parser_state state;
	state.i_ac = 0;
	state.ac = ac;
	state.av = av;

	if (!(state.dgst_func = parse_dgst(&state, ac, av)))
	{
		exit("Invliad dgst\n");
		return 0;
	}
	while (parse_option(&state))
	{
		if (state.flag_s)
			flag_s_handler(&state);
		if (state.flag_p == 1)
			flag_p_handler(&state);
	}
	while (++(state.i_ac) < state.ac)
		parse_file(&state);
	return 0;
}
