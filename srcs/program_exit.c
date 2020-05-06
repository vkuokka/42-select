#include "ft_select.h"

void	program_exit(t_terminal *term, int num)
{
	num == 1 ? ft_putendl_fd("ft_select: Could not allocate memory.", 2) : 0;
	num == 2 ? ft_putendl_fd("ft_select: TERM not set.", 2) : 0;
	num == 3 ? ft_putendl_fd("ft_select: Could not access the termcap database.", 2) : 0;
	num == 4 ? ft_putendl_fd("ft_select: Terminal type is not defined.", 2) : 0;
	term ? config_terminal(1, term) : 0;
	if (term)
	{
		term->select ? free(term->select) : 0;
		free(term);
	}
	exit(num);
}
