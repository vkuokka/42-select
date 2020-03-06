#include "ft_select.h"

void		display_arguments(t_terminal *term)
{
	size_t	i;

	i = -1;
	while (term->args[++i])
	{
		if (term->select == i)
			tputs(tgetstr("us", NULL), 1, print_char);
		ft_putstr(term->args[i]);
		tputs(tgetstr("me", NULL), 1, print_char);
		if (term->args[i + 1])
			write(1, " ", 1);
	}
}
