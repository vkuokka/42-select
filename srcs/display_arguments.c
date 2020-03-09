#include "ft_select.h"

void		display_arguments(t_terminal *term)
{
	size_t	i;

	i = -1;
	while (term->args[++i])
	{
		if (term->cursor == i)
			tputs(tgetstr("us", NULL), 1, print_char);
		if (term->select[i])
			tputs(tgetstr("so", NULL), 1, print_char);
		ft_fprintf(2, "%s", term->args[i]);
		tputs(tgetstr("ue", NULL), 1, print_char);
		tputs(tgetstr("se", NULL), 1, print_char);
		if (term->args[i + 1])
			write(2, " ", 1);
	}
}
