# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pudry <pudry@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 09:01:54 by pudry             #+#    #+#              #
#    Updated: 2023/11/21 17:14:04 by pudry            ###   ########.fr        #
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
BRWN = \\033[0;33m

COMPIL_1 = "           |   |  ${GREEN}C:\\> Compilation 1 \ 10                ${WHITE}|    |"
COMPIL_2 = "           |   |  ${GREEN}C:\\> Compilation 2 \ 10                ${WHITE}|    |"
COMPIL_3 = "           |   |  ${GREEN}C:\\> Compilation 3 \ 10                ${WHITE}|    |"
COMPIL_4 = "           |   |  ${GREEN}C:\\> Compilation 4 \ 10                ${WHITE}|    |"
COMPIL_5 = "           |   |  ${GREEN}C:\\> Compilation 5 \ 10                ${WHITE}|    |"
COMPIL_6 = "           |   |  ${GREEN}C:\\> Compilation 6 \ 10                ${WHITE}|    |"
COMPIL_7 = "           |   |  ${GREEN}C:\\> Compilation 7 \ 10                ${WHITE}|    |"
COMPIL_8 = "           |   |  ${GREEN}C:\\> Compilation 8 \ 10                ${WHITE}|    |"
COMPIL_9 = "           |   |  ${GREEN}C:\\> Compilation 9 \ 10                ${WHITE}|    |"
COMPIL_10 = "           |   |  ${GREEN}C:\\> ${RED}Segmentation fault                ${WHITE}|    |"


SRC_BUILT = builtin/cwd.c builtin/username.c

SRC_UTILS = main.c utils/check_up_down_key.c utils/ft_utils.c

SRC_ERROR = error/ft_error.c error/ft_error_msg.c

SRC_CMD = get_cmd/get_cmd.c get_cmd/get_cmd2.c get_cmd/get_cmd3.c \
	get_cmd/from_quotes_to_wrds.c get_cmd/ft_split_minishell.c get_cmd/ft_split_minishell_part_2.c



all : header compil
	@echo $(COMPIL_2)
	@echo $(COMPIL_3)
	@make -s -C ft_printf/
	@echo $(COMPIL_4)
	@echo $(COMPIL_5)
	@echo $(COMPIL_6)
	@echo $(COMPIL_7)
	@$(CC) $(FLAGS) $(SRC_UTILS) $(SRC_BUILT) $(SRC_CMD) $(SRC_ERROR) $(LIBFTPRINTF) -o $(NAME)
	@echo $(COMPIL_8)
	@echo $(COMPIL_9)
	@echo $(COMPIL_10)
	@make go_down
	./$(NAME)

leaks : header
	@make -s -C ft_printf/
	@$(CC) $(FLAGS) $(SRC_UTILS) $(SRC_BUILT) $(SRC_CMD) $(SRC_ERROR) $(LIBFTPRINTF) -o $(NAME)
	clear
	leaks --atExit -- ./$(NAME)

clean :
	@rm -f $(OBJ_UTILS) $(OBJ_BUILT) $(OBJ_CMD) $(OBJ_ERROR)
	@make clean -s -C ft_printf/

fclean : clean
	@rm -f $(NAME)
	@make fclean -s -C ft_printf/

re : fclean all



push : fclean
	git add .
	git add *
	git commit -m "Auto push"
	git push

sep :
	@echo "<============================================================================================================>"

header :
	@clear
	@echo "${GREEN}"
	@echo "++----------------------------------------------------------------------------------++"
	@echo "||                                                                                  ||"
	@echo "||    ███    ███  ██  ███    ██  ██  ███████  ██   ██  ███████  ██       ██         ||"
	@echo "||    ████  ████  ██  ████   ██  ██  ██       ██   ██  ██       ██       ██         ||"
	@echo "||    ██ ████ ██  ██  ██ ██  ██  ██  ███████  ███████  █████    ██       ██         ||"
	@echo "||    ██  ██  ██  ██  ██  ██ ██  ██       ██  ██   ██  ██       ██       ██         ||"
	@echo "||    ██      ██  ██  ██   ████  ██  ███████  ██   ██  ███████  ███████  ███████    ||"
	@echo "||                                                                                  ||"
	@echo "++----------------------------------------------------------------------------------++"
	@echo "${WHITE}"
	
compil:
	@echo "             ________________________________________________"
	@echo "            /                                                \\"
	@echo "           |    _________________________________________     |"
	@echo "           |   |                                         |    |"
	@echo $(COMPIL_1)
	@echo "           |   |                                         |    |"
	@echo "           |   |                                         |    |"
	@echo "           |   |                                         |    |"
	@echo "           |   |                                         |    |"
	@echo "           |   |                                         |    |"
	@echo "           |   |                                         |    |"
	@echo "           |   |                                         |    |"
	@echo "           |   |                                         |    |"
	@echo "           |   |                                         |    |"
	@echo "           |   |                                         |    |"
	@echo "           |   |_________________________________________|    |"
	@echo "           |                                                  |"
	@echo "            \\_________________________________________________/"
	@echo "                   \\___________________________________/"
	@echo "                ___________________________________________"
	@echo "             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- \`-_"
	@echo "          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.\`-_"
	@echo "       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\`__\`. .-.-.-.\`-_"
	@echo "    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.\`-_"
	@echo " _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.\`-_"
	@echo ":-------------------------------------------------------------------------:"
	@echo "\`---._.-------------------------------------------------------------._.---'"
	@echo ""
	@make go_back

go_back:
	@echo "\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F"

go_down:
	@echo "\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E"




.PHONY : fclean re all header clean cnt check leak
