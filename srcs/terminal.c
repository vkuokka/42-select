#include "ft_select.h"

static void	init_raw(struct termios raw)
{
	char	*type;
	char	buffer[2048];
	int	success;

	type = getenv("TERM");
	if (!type)
	{
		ft_fprintf(2, "ft_select: TERM not set\n");
		exit(0);
	}
	success = tgetent(buffer, type);
	if (success > 0)
	{
		tputs(tgetstr("vi", NULL), 1, print_char);
		raw.c_lflag &= ~(ECHO | ICANON);
		tcsetattr(1, TCSAFLUSH, &raw);
		return ;
	}
	else if (success < 0)
		ft_fprintf(2, "ft_select: Could not access the termcap database\n");
	else if (success == 0)
		ft_fprintf(2, "ft_select: Terminal type %s is not defined", type);
	exit (0);
}

static void	init_original(struct termios original)
{
	tputs(tgetstr("ve", NULL), 1, print_char);
	tcsetattr(1, TCSAFLUSH, &original);
}

void		config_terminal(int reset, t_terminal *term)
{
	if (reset)
		init_original(term->original);
	else
		init_raw(term->raw);
}
