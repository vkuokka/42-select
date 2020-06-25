# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 12:10:34 by vkuokka           #+#    #+#              #
#    Updated: 2020/06/25 03:05:49 by vkuokka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRCS = srcs/main.c \
	srcs/program_exit.c \
	srcs/config_termcaps.c \
	srcs/config_terminal.c \
	srcs/config_signal.c \
	srcs/listen_keys.c \
	srcs/delete_element.c \
	srcs/display_arguments.c \
	srcs/utils.c \

INCL = includes/

LIB = ft
LIBFOL = libft/
LIBINCL = libft/includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	-@git clone https://github.com/vkuokka/42-libft.git libft
	@echo "Building library..."
	@make -C libft/
	@echo "Compiling program..."
	@gcc $(FLAGS) -I $(INCL) -I $(LIBINCL) $(SRCS) -L$(LIBFOL) -l$(LIB) -ltermcap -o $(NAME)
	@echo "Done"
clean:
	@make -C libft/ clean

fclean: clean
	@make -C libft/ fclean
	@echo "Removing binary..."
	@rm -f $(NAME)
	@echo "Done"

re: fclean all
