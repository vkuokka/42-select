#include "ft_select.h"

int		print_char(int c)
{
	return (write(0, &c, 1));
}

void		print_selected(t_terminal *term)
{
	size_t	i;

	i = -1;
	while (++i < term->length)
		if (term->select[i])
			ft_fprintf(1, "%s ", term->args[i]);
}

size_t		find_longest(char **args)
{
	size_t	i;
	size_t	longest;
	size_t	len;

	 i = 0;
	 longest = ft_strlen(args[i]);
	 while(args[++i])
		 if ((len = ft_strlen(args[i])) > longest)
	 		longest = len;
	return (longest + 1);
}
