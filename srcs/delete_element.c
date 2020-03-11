#include "ft_select.h"

int		delete_element(t_terminal *term)
{
	size_t	i;

	term->args[term->cursor] = NULL;
	term->select[term->cursor] = 0;
	i = term->cursor;
	while (i++ < term->length)
	{
		term->args[i - 1] = term->args[i];
		term->select[i - 1] = term->select[i];
	}
	term->length--;
	if (term->cursor >= term->length)
		term->cursor--;
	if (!term->length)
		return (1);
	term->max_len = find_longest(term->args);
	return (0);
}
