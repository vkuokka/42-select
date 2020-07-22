/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:28:03 by vkuokka           #+#    #+#             */
/*   Updated: 2020/07/22 10:59:14 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "memory.h"
#include "print.h"

static void		display_loop(t_terminal *term)
{
	while (1)
	{
		tputs(tgetstr("cl", NULL), 1, print_char);
		display_arguments(term);
		listen_keys(term);
	}
}

int				main(int argc, char **argv)
{
	t_terminal	*term;

	if (argc < 2)
	{
		ft_putendl_fd("ft_select: usage: ft_select arg [arg] ...", \
		STDERR_FILENO);
		exit(0);
	}
	config_termcaps();
	term = (t_terminal *)malloc(sizeof(t_terminal));
	!term ? program_exit(term, 0, 1) : 0;
	term->args = ++argv;
	term->length = --argc;
	term->max_len = max_length(term->args);
	term->select = (char *)malloc(sizeof(char) * argc);
	!term->select ? program_exit(term, 0, 1) : 0;
	ft_bzero(term->select, argc);
	term->cursor = 0;
	config_terminal(0, term);
	tputs(tgetstr("ti", NULL), 1, print_char);
	tputs(tgetstr("vi", NULL), 1, print_char);
	tputs(tgetstr("ho", NULL), 1, print_char);
	display_loop(term);
	return (0);
}
