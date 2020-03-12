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

static int		check_params(int argc)
{
	if (argc < 2)
	{
		ft_fprintf(2, "usage: ft_select [file ...]\n");
		return (1);
	}
	return (0);
}

static void		display_loop(t_terminal *term)
{
	while (1)
	{
		tputs(tgetstr("cl", NULL), 1, print_char);
		tputs(tgetstr("cd", NULL), 1, print_char);
		ioctl(2, TIOCGWINSZ, &term->size);
		config_signal();
		display_arguments(term);
		listen_keys(term);
	}
}

int				main(int argc, char **argv)
{
	t_terminal	*term;

	if (check_params(argc))
		return (0);
	term = (t_terminal *)malloc(sizeof(t_terminal));
	if (!term)
		return (1);
	tcgetattr(2, &term->original);
	term->raw = term->original;
	term->args = ++argv;
	term->length = --argc;
	term->max_len = max_length(term->args);
	term->select = (char *)malloc(sizeof(char) * argc);
	if (!term->select || config_terminal(0, term))
	{
		free(term->select);
		free(term);
		return (1);
	}
	ft_bzero(term->select, argc);
	term->cursor = 0;
	display_loop(term);
}
