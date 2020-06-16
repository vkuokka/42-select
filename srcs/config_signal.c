/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:24:38 by vkuokka           #+#    #+#             */
/*   Updated: 2020/06/16 18:16:02 by vkuokka          ###   ########.fr       */
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
		config_terminal(1, g_term);
		tputs(tgetstr("te", NULL), 1, print_char);
		tputs(tgetstr("ve", NULL), 1, print_char);
		signal(SIGTSTP, SIG_DFL);
		ioctl(1, TIOCSTI, "\x1a");
	}
}

static void	signal_continue(int signum)
{
	if (signum == SIGCONT)
	{
		config_terminal(0, g_term);
		tputs(tgetstr("ti", NULL), 1, print_char);
		tputs(tgetstr("vi", NULL), 1, print_char);
		tputs(tgetstr("ho", NULL), 1, print_char);
		ioctl(1, TIOCSTI, "");
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
