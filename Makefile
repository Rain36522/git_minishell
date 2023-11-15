# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pudry <pudry@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 09:01:54 by pudry             #+#    #+#              #
#    Updated: 2023/11/15 15:40:36 by pudry            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror -lreadline
LIBFTPRINTF = ft_printf/libftprintf.a

BLUE = \\033[1;34m
WHITE = \\033[0;37m
YELLOW = \\033[0;33m
RED = \\033[1;31m
GREEN = \\033[1;32m
BRWN = \\033[0; 33m

SRC_BUILT = builtin/cwd.c builtin/username.c
SRC_UTILS = test.c utils/check_up_down_key.c utils/ft_utils.c utils/ft_error.c
SRC_CMD = get_cmd/get_cmd.c get_cmd/get_cmd2.c get_cmd/get_cmd3.c get_cmd/get_cmd4.c


OBJ_UTILS = $(SRC_UTILS:.c=.o)
OBJ_BUILT = $(SRC_BUILT:.c=.o)
OBJ_CMD = $(SRC_CMD:.c=.o)

all : header $(OBJ_UTILS) $(OBJ_BUILT) $(OBJ_CMD)
	@make -C ft_printf/
	@$(CC) $(FLAGS) $(OBJ_UTILS) $(OBJ_BUILT) $(OBJ_CMD) $(LIBFTPRINTF) -o $(NAME)
	./$(NAME)

%.o%.c :
	$(CC) $(FLAGS) -c -o $@ $^

clean :
	@rm -f $(OBJ_UTILS) $(OBJ_BUILT) $(OBJ_CMD)
	@make clean -C ft_printf/

fclean : clean
	@rm -f $(NAME)
	@make fclean -C ft_printf/

re : fclean all



push : fclean
	git add .
	git add *
	git commit -m "Auto push"
	git push

header :
	@echo "${GREEN}"
	@echo "		   __________"
	@echo "		 . ---------- ."
	@echo "		 | .--------. |"
	@echo "		 | | ${RED} ERROR ${GREEN}| |       __________       ___"
	@echo "		 | | ${RED} 402${GREEN}   | |      /__________\\    {~${RED}.${GREEN}_${RED}.${GREEN}~}"  
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
