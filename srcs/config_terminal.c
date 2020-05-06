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

static void	init_shell(t_terminal *term)
{
	char	*type;
	char	buffer[2048];
	int		success;

	type = getenv("TERM");
	!type ? program_exit(term, 2) : 0;
	success = tgetent(buffer, type);
	if (success > 0)
	{
		tputs(tgetstr("ti", NULL), 1, print_char);
		tputs(tgetstr("ho", NULL), 1, print_char);
		tputs(tgetstr("vi", NULL), 1, print_char);
		term->raw.c_lflag &= ~(ICANON | ECHO);
		tcsetattr(SELECT_FD, TCSAFLUSH, &term->raw);
	}
	else if (success < 0)
		program_exit(term, 3);
	else if (success == 0)
		program_exit(term, 4);
}

static void	init_original(struct termios original)
{
	tputs(tgetstr("te", NULL), 1, print_char);
	tputs(tgetstr("ve", NULL), 1, print_char);
	tcsetattr(SELECT_FD, TCSAFLUSH, &original);
}

void		config_terminal(int reset, t_terminal *term)
{
	if (reset)
		init_original(term->original);
	else
		init_shell(term);
}
