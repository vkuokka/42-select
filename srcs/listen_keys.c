/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:29:47 by vkuokka           #+#    #+#             */
/*   Updated: 2020/06/25 02:41:44 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "strings.h"
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
			write(1, " ", 1);
			printed = 1;
		}
	if (printed)
		write(1, "\n", 1);
}

static void	check_arrows(int sum, t_terminal *term)
{
	if (sum == RIGHT)
		term->cursor == term->length - 1 ? term->cursor = 0 \
		: term->cursor++;
	else if (sum == LEFT)
		term->cursor == 0 ? term->cursor = term->length - 1 \
		: term->cursor--;
}

static void	check_other(int sum, t_terminal *term)
{
	if (sum == ESC)
		program_exit(term, 0);
	else if (sum == SPACE)
	{
		term->select[term->cursor] = \
		(!term->select[term->cursor] ? 1 : 0);
		check_arrows(RIGHT, term);
	}
	else if (sum == ENTER)
	{
		tputs(tgetstr("te", NULL), 1, print_char);
		tputs(tgetstr("ve", NULL), 1, print_char);
		print_selected(term);
		program_exit(term, 0);
	}
	else if (sum == BACK || sum == DEL)
		if (delete_element(term))
			check_other(ESC, term);
}

void		listen_keys(t_terminal *term)
{
	char	key[KEY_SIZE + 1];
	ssize_t	bytes;
	size_t	i;
	int		sum;

	bytes = read(SELECT_FD, key, KEY_SIZE);
	key[bytes] = '\0';
	i = -1;
	sum = 0;
	while (key[++i])
		sum += key[i];
	check_arrows(sum, term);
	check_other(sum, term);
}
