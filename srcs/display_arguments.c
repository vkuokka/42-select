/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:53:44 by vkuokka           #+#    #+#             */
/*   Updated: 2020/07/21 16:33:03 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "memory.h"
#include "strings.h"
#include "print.h"

static void		print_argument(t_terminal *term, size_t i)
{
	char		*pad;
	size_t		len;

	if (term->cursor == i)
		tputs(tgetstr("us", NULL), 1, print_char);
	if (term->select[i])
		tputs(tgetstr("so", NULL), 1, print_char);
	ft_putstr_fd(term->args[i], SELECT_FD);
	tputs(tgetstr("ue", NULL), 1, print_char);
	tputs(tgetstr("se", NULL), 1, print_char);
	len = term->max_len - ft_strlen(term->args[i]);
	pad = (char *)malloc(sizeof(char) * len);
	!pad ? program_exit(term, 0, 1) : 0;
	ft_memset(pad, 32, len);
	write(SELECT_FD, pad, len);
	free(pad);
}

static size_t	check_size(t_terminal *term)
{
	size_t		line_max;

	line_max = term->size.ws_col / term->max_len;
	if (line_max * term->size.ws_row < term->length)
	{
		ft_putstr_fd("Unable to show all elements.", SELECT_FD);
		return (0);
	}
	return (line_max);
}

void			display_arguments(t_terminal *term)
{
	size_t		i;
	size_t		line_max;
	size_t		printed;

	i = 0;
	line_max = check_size(term);
	if (!line_max)
		return ;
	printed = 0;
	while (term->args[i])
	{
		if (printed >= line_max)
		{
			write(SELECT_FD, "\n", 1);
			printed = 0;
			continue ;
		}
		print_argument(term, i);
		i++;
		printed++;
	}
}
