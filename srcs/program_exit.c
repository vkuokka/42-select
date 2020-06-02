/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 09:27:02 by vkuokka           #+#    #+#             */
/*   Updated: 2020/06/02 20:39:36 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** Exit codes:
** 0 = No errors.
** 1 = Could not allocate memory.
** 2 = TERM not set.
** 3 = Could not access the termcap database.
** 4 = Terminal type is not defined.
*/

void	program_exit(t_terminal *term, int num)
{
	term ? config_terminal(1, term) : 0;
	if (term)
	{
		term->select ? free(term->select) : 0;
		free(term);
	}
	exit(num);
}
