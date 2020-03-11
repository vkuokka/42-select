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
		ft_fprintf(2, "%*-s", term->max_len - ft_strlen(term->args[i]), "");
}

static size_t	check_space(t_terminal *term)
{
	size_t	line;

	line = term->size.ws_col / term->max_len;
	if (line * term->size.ws_row < term->length)
	{
		ft_fprintf(2, "Unable to show all elements");
		return (0);
	}
	return (line);
}

void		display_arguments(t_terminal *term)
{
	size_t	i;
	size_t	line;
	size_t	printed;

	i = 0;
	line = check_space(term);
	if (!line)
		return ;
	printed = 0;
	while (term->args[i])
	{
		if (printed >= line)
		{
			write(2, "\n", 1);
			printed = 0;
			continue ;
		}
		print_argument(term, i);
		i++;
		printed++;
	}
}
