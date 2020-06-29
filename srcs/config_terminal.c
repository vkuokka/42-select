/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:10:04 by vkuokka           #+#    #+#             */
/*   Updated: 2020/06/25 02:30:43 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
		tcsetattr(1, TCSAFLUSH, &term->original);
	else
	{
		tcgetattr(1, &term->original);
		term->raw = term->original;
		ioctl(1, TIOCGWINSZ, &term->size);
		term->raw.c_lflag &= ~(ICANON | ECHO);
		tcsetattr(1, TCSAFLUSH, &term->raw);
		config_signal(term);
	}
}
