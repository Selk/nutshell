# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/27 14:43:50 by cdauphin          #+#    #+#              #
#    Updated: 2013/12/27 14:43:50 by cdauphin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nutsh

SRC_DIR = srcs/
FTPRINTF_DIR = libs/printf
INC_DIR = includes/

CC=gcc
FLAGS=-Wall -Wextra -Werror -g -I $(INC_DIR)
LIB=-L /usr/lib -ltermcap -L ./$(FTPRINTF_DIR) -lftprintf
OBJ= $(SRC:.c=.o)

D		=	\033[0m
R		=	\033[1;31m
G		=	\033[1;32m
Y		=	\033[1;33m
B		=	\033[1;34m

SRC = \
	builtins.c \
	built_cd.c \
	built_env.c \
	check_built.c \
	\
	lexer.c \
	parser.c \
	parse_op.c \
	\
	main.c \
	init.c \
	tree_use.c \
	ft_process.c \
	op_exec.c \
	op_red.c \
	free.c \
	\
	get_next_line.c \
	ft_strsplit.c \
	ft_strdup.c \
	ft_bzero.c \
	ft_strcpy.c \
	ft_strcmp.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_strlen.c \
	ft_arraylen.c \
	ft_strstr.c \
	ft_strnew.c \
	ft_strjoin.c \
	ft_strcat.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putstr_fd.c \
	ft_isalnum.c \
	ft_strisalnum.c


all: $(NAME)

$(NAME): $(OBJ)
	@Make -C $(FTPRINTF_DIR) fclean
	@Make -C $(FTPRINTF_DIR)
	@echo "Création du binaire..."
	@$(CC) -g $(FLAGS) -o $@ $^ $(LIB)
	@echo "$(D)authors : cdauphin, gsaunier, jhyun, msevery, sdomingu"
	@echo ""
	@echo "Welcome to..."
	@echo " $(B)__    _ $(R)_ $(Y)_____________ $(G)_         $(R)_  "
	@echo "$(B)|  \  | $(R)| $(Y)|_____   _____$(G)| |       $(R)| | "
	@echo "$(B)| \ \ | $(R)| |   | $(Y)| |$(B)___ $(G) | |__     $(R)| | "
	@echo "$(B)| |\ \| $(R)| |   | $(Y)| $(B)/ __| $(G)|  _ \    $(R)|_| "
	@echo "$(B)| | \   $(R)| |___| $(Y)| $(B)\__ \ $(G)| | | |    $(R)_  "
	@echo "$(B)|_|  \__$(R)|_______$(Y)|_$(B)|___/ $(G)|_| |_|   $(R)|_| "
	@echo "$(D)"
%.o: $(SRC_DIR)%.c
	@$(CC) -g $(FLAGS) -c $^

.PHONY: clean fclean all

clean:
	@rm -f $(OBJ)
	@Make -C $(FTPRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@Make -C $(FTPRINTF_DIR) fclean

re: fclean all
