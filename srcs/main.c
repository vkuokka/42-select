#include "ft_select.h"

static void		check_params(int argc)
{
	if (argc < 2)
	{
		ft_printf("usage: ft_select [file ...]\n");
		exit (0);
	}
}
static void		display_loop(t_terminal *term)
{
	while (1)
	{
		tputs(tgetstr("cr", NULL), 1, print_char);
		ft_arriter(term->args, ft_putstr);
		listen_keys(term);
	}
}

int			main(int argc, char **argv)
{
	t_terminal	*term;

	(void)argv;
	check_params(argc);
	term = malloc(sizeof(t_terminal));
	if (!term)
		exit(1);
	tcgetattr(1, &term->original);
	term->raw = term->original;
	term->args = ++argv;
	config_terminal(0, term);
	display_loop(term);
}
