/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:51:37 by vkuokka           #+#    #+#             */
/*   Updated: 2020/07/21 16:33:29 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# define FT_SELECT_H

# include <stdlib.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include <signal.h>

# define SELECT_FD 2
# define KEY_SIZE 4

# define ENTER 10
# define ESC 27
# define SPACE 32
# define BACK 127
# define RIGHT 185
# define LEFT 186
# define DEL 295

typedef struct		s_terminal
{
	struct termios	original;
	struct termios	raw;
	struct winsize	size;
	char			**args;
	size_t			length;
	size_t			max_len;
	char			*select;
	size_t			cursor;
}					t_terminal;

void				program_exit(t_terminal *term, int print, int num);
void				config_terminal(int reset, t_terminal *term);
void				config_signal(t_terminal *term);
void				display_arguments(t_terminal *term);
void				listen_keys(t_terminal *term);
int					print_char(int c);
size_t				max_length(char **args);
int					delete_element(t_terminal *term);
void				config_termcaps(void);

#endif
