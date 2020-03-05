#include "ft_select.h"

static void		check_params(int argc)
{
	if (argc < 2)
	{
		ft_printf("usage: ft_select [file ...]\n");
		exit (0);
	}
}
static void		display_loop(t_terminal *term, char **argv)
{
	char		c;

	if (!term)
		return ;
	while (1)
	{
		ft_putstr(argv[1]);
		tputs(tgetstr("cr", NULL), 1, print_char);
		if (read(1, &c, 1) == 1 && c == 'q')
			break ;
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
	config_terminal(0, term);
	display_loop(term, argv);
	config_terminal(1, term);
}
