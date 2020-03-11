#ifndef FT_SELECT_H

#define FT_SELECT_H

# include "ft_printf.h"
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include <signal.h>

# define KEY_SIZE 4
# define ENTER 10
# define ESC 27
# define SPACE 32
# define BACK 127
# define UP 183
# define DOWN 184
# define RIGHT 185
# define LEFT 186
# define DEL 295

typedef struct		s_terminal
{
	struct termios	original;
	struct termios	raw;
	struct winsize	size;
	char		**args;
	size_t		length;
	size_t		max_len;
	char		*select;
	size_t		cursor;
}			t_terminal;

void			config_terminal(int reset, t_terminal *term);
void			signal_setup(void);
void			display_arguments(t_terminal *term);
void			listen_keys(t_terminal *term);
int			print_char(int c);
size_t			find_longest(char **args);
int			delete_element(t_terminal *term);
void			print_selected(t_terminal *term);

#endif
