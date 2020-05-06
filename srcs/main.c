/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:28:03 by vkuokka           #+#    #+#             */
/*   Updated: 2020/03/12 16:57:01 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		display_loop(t_terminal *term)
{
	while (1)
	{
		tputs(tgetstr("cl", NULL), 1, print_char);
		ioctl(SELECT_FD, TIOCGWINSZ, &term->size);
		config_signal(term);
		display_arguments(term);
		listen_keys(term);
	}
}

int				main(int argc, char **argv)
{
	t_terminal	*term;

	if (argc < 2)
	{
		ft_putendl_fd("usage: ft_select [file ...]", 2);
		exit(0);
	}
	term = (t_terminal *)malloc(sizeof(t_terminal));
	!term ? program_exit(NULL, 1) : 0;
	tcgetattr(SELECT_FD, &term->original);
	term->raw = term->original;
	term->args = ++argv;
	term->length = --argc;
	term->max_len = max_length(term->args);
	term->select = (char *)malloc(sizeof(char) * argc);
	!term->select ? program_exit(term, 1) : 0;
	config_terminal(0, term);
	ft_bzero(term->select, argc);
	term->cursor = 0;
	display_loop(term);
}
