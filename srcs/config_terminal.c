/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:31:55 by vkuokka           #+#    #+#             */
/*   Updated: 2020/03/12 16:53:50 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	init_raw(struct termios raw)
{
	char	*type;
	char	buffer[2048];
	int		success;

	type = getenv("TERM");
	if (!type)
	{
		ft_fprintf(2, "ft_select: TERM not set\n");
		return (1);
	}
	success = tgetent(buffer, type);
	if (success > 0)
	{
		tputs(tgetstr("ti", NULL), 1, print_char);
		tputs(tgetstr("vi", NULL), 1, print_char);
		raw.c_lflag &= ~(ECHO | ICANON);
		tcsetattr(SELECT_FD, TCSAFLUSH, &raw);
		return (0);
	}
	else if (success < 0)
		ft_fprintf(2, "ft_select: Could not access the termcap database\n");
	else if (success == 0)
		ft_fprintf(2, "ft_select: Terminal type %s is not defined\n", type);
	return (1);
}

static void	init_original(struct termios original)
{
	tputs(tgetstr("te", NULL), 1, print_char);
	tputs(tgetstr("ve", NULL), 1, print_char);
	tcsetattr(SELECT_FD, TCSAFLUSH, &original);
}

int			config_terminal(int reset, t_terminal *term)
{
	if (reset)
		init_original(term->original);
	else if (init_raw(term->raw))
		return (1);
	return (0);
}
