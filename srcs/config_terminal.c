/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:10:04 by vkuokka           #+#    #+#             */
/*   Updated: 2020/07/22 16:27:14 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <unistd.h>

/*
** Chooses action according to reset value. If reset value
** is positive, It gathers information about the window size
** for term struct and turns off ICANON and ECHO. If it is zero
** the function Configurates the terminal as it was
** before the program started.
*/

void		config_terminal(int reset, t_terminal *term)
{
	if (reset)
		tcsetattr(STDIN_FILENO, TCSANOW, &term->original);
	else
	{
		if (tcgetattr(0, &term->original) == -1)
			program_exit(term, 0, 1);
		term->raw = term->original;
		ioctl(STDIN_FILENO, TIOCGWINSZ, &term->size);
		term->raw.c_lflag &= ~(ICANON | ECHO);
		if (tcsetattr(STDIN_FILENO, TCSANOW, &term->raw) == -1)
			program_exit(term, 0, 1);
		config_signal(term);
	}
}
