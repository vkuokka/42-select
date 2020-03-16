/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:24:38 by vkuokka           #+#    #+#             */
/*   Updated: 2020/03/12 16:24:40 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_terminal *g_term;

static void	signal_resize(int signum)
{
	if (signum == SIGWINCH)
	{
		tputs(tgetstr("cl", NULL), 1, print_char);
		tputs(tgetstr("cd", NULL), 1, print_char);
		ioctl(2, TIOCSTI, "");
	}
}

static void	signal_suspend(int signum)
{
	if (signum == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		config_terminal(1, g_term);
		ioctl(2, TIOCSTI, "\x1a");
	}
}

static void	signal_continue(int signum)
{
	if (signum == SIGCONT)
	{
		config_terminal(0, g_term);
		ioctl(2, TIOCSTI, "");
	}
}

void		config_signal(t_terminal *term)
{
	g_term = term;
	signal(SIGWINCH, signal_resize);
	signal(SIGTSTP, signal_suspend);
	signal(SIGCONT, signal_continue);
}
