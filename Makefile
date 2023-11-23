# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pudry <pudry@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 09:01:54 by pudry             #+#    #+#              #
#    Updated: 2023/11/23 14:07:38 by pudry            ###   ########.fr        #
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
PINK = \\033[1;35m


TEXT_1   = "           |   |  ${GREEN}C:\\> Compilation minishell             ${WHITE}|    |"
COMPIL_1 = "           |   |  ${GREEN}C:\\>${BLUE} 10%  |██                  |100%   ${WHITE}|    |\033[F"
COMPIL_2 = "           |   |  ${GREEN}C:\\>${BLUE} 20%  |████                |100%   ${WHITE}|    |\033[F"
COMPIL_3 = "           |   |  ${GREEN}C:\\>${BLUE} 30%  |██████              |100%   ${WHITE}|    |\033[F"
COMPIL_4 = "           |   |  ${GREEN}C:\\>${BLUE} 40%  |████████            |100%   ${WHITE}|    |\033[F"
COMPIL_5 = "           |   |  ${GREEN}C:\\>${BLUE} 50%  |██████████          |100%   ${WHITE}|    |\033[F"
COMPIL_6 = "           |   |  ${GREEN}C:\\>${BLUE} 60%  |████████████        |100%   ${WHITE}|    |\033[F"
COMPIL_7 = "           |   |  ${GREEN}C:\\>${BLUE} 70%  |██████████████      |100%   ${WHITE}|    |\033[F"
COMPIL_8 = "           |   |  ${GREEN}C:\\>${BLUE} 80%  |████████████████    |100%   ${WHITE}|    |\033[F"
COMPIL_9 = "           |   |  ${GREEN}C:\\>${BLUE} 90%  |██████████████████  |100%   ${WHITE}|    |\033[F"
COMPIL_10 = "           |   |  ${GREEN}C:\\>${BLUE} 100% |████████████████████|100%   ${WHITE}|    |"
TEXT_2   = "           |   |  ${GREEN}C:\\> Compilation SUCCESS               ${WHITE}|    |"
TEXT_3   = "           |   |  ${GREEN}C:\\> Starting minishell in 3 seconds   ${WHITE}|    |\033[F"
TEXT_4   = "           |   |  ${GREEN}C:\\> Starting minishell in 2 seconds   ${WHITE}|    |\033[F"
TEXT_5   = "           |   |  ${GREEN}C:\\> Starting minishell in 1 seconds   ${WHITE}|    |\033[F"
TEXT_6   = "           |   |  ${GREEN}C:\\> Starting minishell in 0 seconds   ${WHITE}|    |"

SRC_BUILT = builtin/cwd.c builtin/username.c

SRC_UTILS = main.c utils/check_up_down_key.c utils/ft_utils.c utils/ft_utils2.c

SRC_ERROR = error/ft_error.c error/ft_error_msg.c

SRC_CMD_2 = check_syntax.c double_input_redir2.c from_quotes_to_wrds.c ft_split_minishell_part_2.c write_cmd_in_file.c \
			double_input_redir.c file_to_array.c ft_split_minishell.c get_cmd.c
SRC_CMD = $(addprefix get_cmd/,$(SRC_CMD_2))

SRC_GNL = gnl/get_next_line_utils.c gnl/get_next_line.c


all : header
	@make -s -C ft_printf/
	@$(CC) $(FLAGS) $(SRC_UTILS) $(SRC_BUILT) $(SRC_CMD) $(SRC_ERROR) $(SRC_GNL) $(LIBFTPRINTF) -o $(NAME)
	./$(NAME)


# all : header compil
# 	@make -s -C ft_printf/
# 	@sleep 0.5
# 	@echo $(COMPIL_2)
# 	@sleep 0.2
# 	@echo $(COMPIL_3)
# 	@sleep 0.2
# 	@echo $(COMPIL_4)
# 	@sleep 0.2
# 	@echo $(COMPIL_5)
# 	@echo $(COMPIL_6)
# 	@sleep 0.2
# 	@echo $(COMPIL_7)
# 	@$(CC) $(FLAGS) $(SRC_UTILS) $(SRC_BUILT) $(SRC_CMD) $(SRC_ERROR) $(SRC_GNL) $(LIBFTPRINTF) -o $(NAME)
# 	@echo $(COMPIL_8)
# 	@sleep 0.2
# 	@echo $(COMPIL_9)
# 	@sleep 1.2
# 	@echo $(COMPIL_10)
# 	@echo $(TEXT_2)
# 	@echo $(TEXT_3)
# 	@sleep 1.0
# 	@echo $(TEXT_4)
# 	@sleep 1.0
# 	@echo $(TEXT_5)
# 	@sleep 1.0
# 	@echo $(TEXT_6)
# 	@sleep 0.3
# 	@make go_down
# 	./$(NAME)

leaks : header
	@make -s -C ft_printf/
	@$(CC) $(FLAGS) $(SRC_UTILS) $(SRC_BUILT) $(SRC_CMD) $(SRC_ERROR) $(SRC_GNL) $(LIBFTPRINTF) -o $(NAME)
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

header :
	@clear
	@echo "${BLUE}"
	@echo "++----------------------------------------------------------------------------------++"
	@echo "||                                                                                  ||"
	@echo "||    ███    ███  ██  ███    ██  ██  ███████  ██   ██  ███████  ██       ██         ||"
	@echo "||    ████  ████  ██  ████   ██  ██  ██       ██   ██  ██       ██       ██         ||"
	@echo "||    ██ ████ ██  ██  ██ ██  ██  ██  ███████  ███████  █████    ██       ██         ||"
	@echo "||    ██  ██  ██  ██  ██  ██ ██  ██       ██  ██   ██  ██       ██       ██         ||"
	@echo "||    ██      ██  ██  ██   ████  ██  ███████  ██   ██  ███████  ███████  ███████    ||"
	@echo "||                                                                                  ||"
	@echo "++----------------------------------------------------------------------------------++"
	@echo "${GREEN}"
	@echo ""
	@echo '   ____          _ _                                       ____             _ '
	@echo '  / ___|___  ___(_) | ___                                 |  _ \ __ _ _   _| |'
	@echo ' | |   / _ \/ __| | |/ _ \                                | |_) / _` | | | | |'
	@echo ' | |__|  __/ (__| | |  __/                                |  __/ (_| | |_| | |'
	@echo '  \____\___|\___|_|_|\___|                                |_|   \__,_|\__,_|_|'
	@echo "${WHITE}"
	
compil:
	@echo "             ________________________________________________"
	@echo "            /                                                \\"
	@echo "           |    _________________________________________     |"
	@echo "           |   |                                         |    |"
	@echo $(TEXT_1)
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
	@echo "\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F"

go_down:
	@echo "\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E"




.PHONY : fclean re all header clean cnt check leak


