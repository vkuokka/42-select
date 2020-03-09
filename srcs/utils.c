#include "ft_select.h"

int		print_char(int c)
{
	return (write(0, &c, 1));
}

void		print_selected(t_terminal *term)
{
	size_t	i;

	i = 0;
	while (i < term->length)
	{
		if (term->select[i])
			ft_fprintf(1, "%s ", term->args[i]);
		i++;
	}
}
