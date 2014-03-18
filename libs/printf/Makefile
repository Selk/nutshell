# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 14:55:24 by cdauphin          #+#    #+#              #
#    Updated: 2013/12/16 14:55:24 by cdauphin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDES=./
CC=cc
AC=ar rc
RL=ranlib
FLAGS=-Wall -Wextra -Werror -c
OBJ= $(SRC:.c=.o)

SRC = ft_puthexa.c \
	ft_putaddr.c \
	ft_putoctal.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putsize_t.c \
	ft_printf.c \
	ft_print.c \
	ft_print_nb.c \
	ft_split.c \
	ft_putstr.c

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRC)
	@echo "Création de la libftprintf..."
	@$(AC) $(NAME) $(OBJ)
	@$(RL) $(NAME)

.PHONY: clean fclean all

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

recl: fclean all
	@rm -f $(OBJ)

