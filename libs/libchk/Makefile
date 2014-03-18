# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/07 10:47:45 by cdauphin          #+#    #+#              #
#    Updated: 2014/01/07 10:47:45 by cdauphin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libchk.a

SRC_DIR = srcs

CC=gcc
AC=ar rc
RL=ranlib
FLAGS=-Wall -Wextra -Werror -c
OBJ= $(SRC:.c=.o)

SRC = x_read.c \
	x_open.c \
	x_close.c \
	x_dup2.c \
	x_tputs.c \
	x_tcsetattr.c \
	x_malloc.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Création de la libftx..."
	@$(AC) $@ $^
	@$(RL) $(NAME)

.PHONY: clean fclean all

%.o: %.c
	@$(CC) $(FLAGS) $^

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

recl: fclean all
	@rm -f $(OBJ)
