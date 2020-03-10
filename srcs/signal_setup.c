#include "ft_select.h"

static void	signal_resize(int signum)
{
	if (signum == SIGWINCH)
	{
		tputs(tgetstr("cl", NULL), 1, print_char);
		tputs(tgetstr("cd", NULL), 1, print_char);
		ioctl(2, TIOCSTI, "");
	}
}

void		signal_setup(void)
{
	signal(SIGWINCH, signal_resize);
}
