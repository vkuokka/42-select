#include "ft_select.h"

static void	init_exit(t_terminal *term)
{
	free(term->select);
	free(term);
	exit(1);
}

static int	init_raw(struct termios raw)
{
	char	*type;
	char	buffer[2048];
	int	success;

	type = getenv("TERM");
	if (!type)
	{
		ft_fprintf(2, "ft_select: TERM not set\n");
		return (1);
	}
	success = tgetent(buffer, type);
	if (success > 0)
	{
		tputs(tgetstr("ti", NULL), 1, print_char);
		tputs(tgetstr("vi", NULL), 1, print_char);
		raw.c_lflag &= ~(ECHO | ICANON);
		tcsetattr(2, TCSAFLUSH, &raw);
		return (0);
	}
	else if (success < 0)
		ft_fprintf(2, "ft_select: Could not access the termcap database\n");
	else if (success == 0)
		ft_fprintf(2, "ft_select: Terminal type %s is not defined", type);
	return (1);
}

static void	init_original(struct termios original)
{
	tputs(tgetstr("te", NULL), 1, print_char);
	tputs(tgetstr("ve", NULL), 1, print_char);
	tcsetattr(2, TCSAFLUSH, &original);
}

void		config_terminal(int reset, t_terminal *term)
{
	if (reset)
		init_original(term->original);
	else
		if (init_raw(term->raw))
			init_exit(term);
}
