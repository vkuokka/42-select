/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 09:27:02 by vkuokka           #+#    #+#             */
/*   Updated: 2020/07/22 16:22:15 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "print.h"

static void	print_selected(t_terminal *term)
{
	int		printed;
	size_t	i;

	printed = 0;
	i = -1;
	while (++i < term->length)
		if (term->select[i])
		{
			ft_putstr(term->args[i]);
			ft_putchar(' ');
			printed = 1;
		}
	if (printed)
		ft_putchar('\n');
}

void		program_exit(t_terminal *term, int print, int num)
{
	term ? config_terminal(1, term) : 0;
	tputs(tgetstr("te", NULL), 1, print_char);
	tputs(tgetstr("ve", NULL), 1, print_char);
	if (term)
	{
		print ? print_selected(term) : 0;
		term->select ? free(term->select) : 0;
		free(term);
	}
	exit(num);
}
