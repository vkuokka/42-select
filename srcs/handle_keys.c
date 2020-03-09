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
		free(term->select);
		free(term);
		exit(0);
	}
	else if (sum == SPACE)
	{
		if (!term->select[term->cursor])
			term->select[term->cursor] = 1;
		else
			term->select[term->cursor] = 0;
		check_arrows(RIGHT, term);
	}
	else if (sum == ENTER)
	{
		print_selected(term);
		check_other(ESC, term);
	}
	/*else if (sum == BACK || sum == DEL)
		if (delete_element(sum, term))
			check_other(ESC, term);*/
}

void		listen_keys(t_terminal *term)
{
	char	key[KEY_SIZE + 1];
	ssize_t	bytes;
	size_t	i;
	int	sum;

	bytes = read(2, key, KEY_SIZE);
	key[bytes] = '\0';
	i = -1;
	sum = 0;
	while (key[++i])
		sum += key[i];
	check_arrows(sum, term);
	check_other(sum, term);
}
