#include "ft_select.h"

static void	print_argument(t_terminal *term, size_t i)
{
		if (term->cursor == i)
			tputs(tgetstr("us", NULL), 1, print_char);
		if (term->select[i])
			tputs(tgetstr("so", NULL), 1, print_char);
		ft_fprintf(2, "%s", term->args[i]);
		tputs(tgetstr("ue", NULL), 1, print_char);
		tputs(tgetstr("se", NULL), 1, print_char);
}

void		display_arguments(t_terminal *term)
{
	size_t	i;
	size_t	printed;

	i = 0;
	printed = 0;
	while (term->args[i])
	{
		printed += ft_strlen(term->args[i]);
		if (printed + 1 > term->size.ws_col)
		{
			write(2, "\n", 1);
			printed = 0;
			continue ;
		}
		print_argument(term, i);
		if (term->args[i + 1])
		{
			write(2, " ", 1);
			printed++;
		}
		i++;
	}
}
