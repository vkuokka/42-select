/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 09:27:02 by vkuokka           #+#    #+#             */
/*   Updated: 2020/06/16 18:09:57 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	program_exit(t_terminal *term, int num)
{
	term ? config_terminal(1, term) : 0;
	tputs(tgetstr("te", NULL), 1, print_char);
	tputs(tgetstr("ve", NULL), 1, print_char);
	if (term)
	{
		term->select ? free(term->select) : 0;
		free(term);
	}
	exit(num);
}
