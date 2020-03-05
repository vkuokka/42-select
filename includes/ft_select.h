#ifndef FT_SELECT_H

#define FT_SELECT_H

# include "ft_printf.h"
# include <termios.h>
# include <term.h>

# define ESC 27

typedef struct		s_terminal
{
	struct termios	original;
	struct termios	raw;
}			t_terminal;

void			config_terminal(int reset, t_terminal *term);
int			print_char(int c);

#endif
