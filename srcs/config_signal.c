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

static void	signal_resize(int signum)
{
	if (signum == SIGWINCH)
	{
		tputs(tgetstr("cl", NULL), 1, print_char);
		tputs(tgetstr("cd", NULL), 1, print_char);
		ioctl(2, TIOCSTI, "");
	}
}

void		config_signal(void)
{
	signal(SIGWINCH, signal_resize);
}
