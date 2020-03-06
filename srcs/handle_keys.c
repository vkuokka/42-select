#include "ft_select.h"

static void	check_arrows(int sum, t_terminal *term)
{
	if (sum == RIGHT)
	{
		if (term->cursor == term->length - 1)
			term->cursor = 0;
		else
			term->cursor++;
	}
	else if (sum == LEFT)
	{
		if (term->cursor == 0)
			term->cursor = term->length - 1;
		else
			term->cursor--;
	}
}

static void	check_other(int sum, t_terminal *term)
{
	if (sum == ESC)
	{
		config_terminal(1, term);
		free(term);
		tputs(tgetstr("cr", NULL), 1, print_char);
		exit(0);
	}
	else if (sum == SPACE)
		return ;
	else if (sum == RET || sum == DEL)
		return ;
}

void		listen_keys(t_terminal *term)
{
	char	key[KEY_SIZE + 1];
	ssize_t	bytes;
	size_t	i;
	int	sum;

	bytes = read(1, key, KEY_SIZE);
	key[bytes] = '\0';
	i = -1;
	sum = 0;
	while (key[++i])
		sum += key[i];
	check_arrows(sum, term);
	check_other(sum, term);
}
