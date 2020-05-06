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
		ioctl(SELECT_FD, TIOCGWINSZ, &g_term->size);
		tputs(tgetstr("cl", NULL), 1, print_char);
		ioctl(SELECT_FD, TIOCSTI, "");
	}
}

static void	signal_suspend(int signum)
{
	if (signum == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		config_terminal(1, g_term);
		ioctl(SELECT_FD, TIOCSTI, "\x1a");
	}
}

static void	signal_continue(int signum)
{
	if (signum == SIGCONT)
	{
		config_terminal(0, g_term);
		ioctl(SELECT_FD, TIOCSTI, "");
	}
}

static void	signal_kill(int signum)
{
	if (signum)
		program_exit(g_term, 0);
}

void		config_signal(t_terminal *term)
{
	g_term = term;
	signal(SIGWINCH, signal_resize);
	signal(SIGTSTP, signal_suspend);
	signal(SIGCONT, signal_continue);
	signal(SIGINT, signal_kill);
	signal(SIGSTOP, signal_kill);
	signal(SIGKILL, signal_kill);
	signal(SIGQUIT, signal_kill);
	signal(SIGABRT, signal_kill);
}
