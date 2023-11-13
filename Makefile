# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pudry <pudry@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 09:01:54 by pudry             #+#    #+#              #
#    Updated: 2023/11/13 12:39:18 by pudry            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFTPRINTF = ft_printf/libftprintf.a
GNL = gnl/gnl.a

BLUE = \\033[1;34m
WHITE = \\033[0;37m
YELLOW = \\033[0;33m
RED = \\033[1;31m
GREEN = \\033[1;32m
BRWN = \\033[0; 33m

SRC_BUILT = builtin/cwd.c builtin/username.c
SRC_UTILS = test.c


OBJ_UTILS = $(SRC_UTILS:.c=.o)
OBJ_BUILT = $(SRC_BUILT:.c=.o)

all : header $(OBJ_UTILS) $(OBJ_BUILT)
	@make -C ft_printf/
	@make -C gnl/
	@$(CC) $(FLAGS) $(OBJ_UTILS) $(OBJ_BUILT) $(LIBFTPRINTF) $(GNL) -o $(NAME)
	./$(NAME)

%.o%.c :
	@$(CC) $(CFLAGS) -c -o $@ $^

clean :
	@rm -f $(OBJ_UTILS) $(OBJ_BUILT)
	@make clean -C gnl/
	@make clean -C ft_printf/

fclean : clean
	@rm -f $(NAME)
	@make fclean -C gnl/
	@make fclean -C ft_printf/

re : fclean all



push : fclean
	git add *
	git commit -m "Auto push"
	git push

header :
	@echo "${GREEN}"
	@echo "		   __________"
	@echo "		 . ---------- ."
	@echo "		 | .--------. |"
	@echo "		 | | ${BLUE}COMPILE${GREEN}| |       __________       ___"
	@echo "		 | | ${BLUE}FILE${GREEN}   | |      /__________\\    {~${RED}.${GREEN}_${RED}.${GREEN}~}"  
	@echo "	.--------|  --------  |------|    --=-- |-----( Y )---."
	@echo "	|         ----,-.-----       |o ======  |    ()~*~()  | "
	@echo "	|       ______|_|_______     |__________|    (_)-(_)  | "
	@echo "	|      /  %%%%%%%%%%%%  \\                             | "
	@echo "	|     /  %%%%%%%%%%%%%%  \\                            | "
	@echo "	|     ^^^^^^^^^^^^^^^^^^^^                            | "
	@echo "	+-----------------------------------------------------+"
	@echo "	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ "
	@echo "${BLUE}"
	@echo "\n<------------COMPILING OBJECT------------>\n"
	@echo "${WHITE}"



.PHONY : fclean re all header clean cnt check leak