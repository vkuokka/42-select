/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:29:47 by vkuokka           #+#    #+#             */
/*   Updated: 2020/03/12 17:02:23 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_selected(t_terminal *term)
{
	int	printed;
	size_t	i;

	printed = 0;
	i = -1;
	while (++i < term->length)
		if (term->select[i])
		{
			write(1, term->args[i], ft_strlen(term->args[i]));
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
	{
		config_terminal(1, term);
		free(term->select);
		free(term);
		exit(0);
	}
	else if (sum == SPACE)
	{
		term->select[term->cursor] = \
		(!term->select[term->cursor] ? 1 : 0);
		check_arrows(RIGHT, term);
	}
	else if (sum == ENTER)
	{
		config_terminal(1, term);
		print_selected(term);
		free(term->select);
		free(term);
		exit(0);
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

	bytes = read(2, key, KEY_SIZE);
	key[bytes] = '\0';
	i = -1;
	sum = 0;
	while (key[++i])
		sum += key[i];
	check_arrows(sum, term);
	check_other(sum, term);
}
