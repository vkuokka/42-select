#include "ft_select.h"

static void	config_raw(struct termios raw)
{
	raw.c_iflag &= ~(IXON | ICRNL);
	raw.c_oflag &= ~(OPOST);
	raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

static void	check_params(int argc)
{
	if (argc < 2)
	{
		ft_printf("usage: ft_select [file ...]\n");
		exit (0);
	}
}

int		main(int argc, char **argv)
{
	struct termios original;
	struct termios raw;
	char c;

	(void)argv;
	check_params(argc);
	tcgetattr(STDIN_FILENO, &original);
	raw = original;
	config_raw(raw);
	while (1)
		if (read(STDIN_FILENO, &c, 1) == 1 && c == ESC)
		{
			tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
			break ;
		}
}
