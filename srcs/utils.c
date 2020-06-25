/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:15:15 by vkuokka           #+#    #+#             */
/*   Updated: 2020/06/25 02:42:05 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "strings.h"
#include "print.h"

int			print_char(int c)
{
	return (write(0, &c, 1));
}

size_t		max_length(char **args)
{
	size_t	i;
	size_t	max;
	size_t	len;

	i = 0;
	max = ft_strlen(args[i]);
	while (args[++i])
	{
		len = ft_strlen(args[i]);
		if (len > max)
			max = len;
	}
	return (max + 1);
}
