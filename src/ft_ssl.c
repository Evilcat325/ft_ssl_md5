#include "ft_ssl.h"

int main(int ac, char** av)
{
	t_parser_state state;

	state.i_ac = 1;
	state.ac = ac;
	state.av = av;
	if (ac == 1)
	{
		printf("usage: ft_ssl command [command opts] [command args]\n");
		return 0;
	}
	else if (!(state.dgst_func = parse_dgst(&state, ac, av)))
	{
		printf("ft_ssl: Error: '%s' is an invalid command.\n", av[1]);
		printf("\nStandard commands:\n");
		printf("\nMessage Digest commands:\nmd5\nsha\n");
		printf("\nCipher commands:\n");
		return 0;
	}
	if (ac == 2)
	{
		state.flag_q = 1;
		flag_p_handler(&state);
	}
	while (parse_option(&state))
	{
		if (state.flag_s)
			flag_s_handler(&state);
		if (state.flag_p == 1)
			flag_p_handler(&state);
	}
	while (state.i_ac < state.ac)
		parse_file(&state);
	return 0;
}
