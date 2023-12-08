# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pudry <pudry@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 09:01:54 by pudry             #+#    #+#              #
#    Updated: 2023/12/08 11:02:27 by pudry            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
FLAGS = -lreadline -L$(HOME)/.brew/opt/readline/lib -Wall -Wextra -Werror -fsanitize=address
LIBFTPRINTF = ft_printf/libftprintf.a 

BLUE = \\033[1;34m
WHITE = \\033[0;37m
YELLOW = \\033[0;33m
RED = \\033[1;31m
GREEN = \\033[1;32m
BRWN = \\033[0;33m
PINK = \\033[1;35m


TEXT_1   = "			              |   |  ${GREEN}C:\\> Compilation minishell             ${WHITE}|    |"
COMPIL_1 = "			              |   |  ${GREEN}C:\\>${BLUE} 10%  |██                  |100%   ${WHITE}|    |\033[F"
COMPIL_2 = "			              |   |  ${GREEN}C:\\>${BLUE} 20%  |████                |100%   ${WHITE}|    |\033[F"
COMPIL_3 = "			              |   |  ${GREEN}C:\\>${BLUE} 30%  |██████              |100%   ${WHITE}|    |\033[F"
COMPIL_4 = "			              |   |  ${GREEN}C:\\>${BLUE} 40%  |████████            |100%   ${WHITE}|    |\033[F"
COMPIL_5 = "			              |   |  ${GREEN}C:\\>${BLUE} 50%  |██████████          |100%   ${WHITE}|    |\033[F"
COMPIL_6 = "			              |   |  ${GREEN}C:\\>${BLUE} 60%  |████████████        |100%   ${WHITE}|    |\033[F"
COMPIL_7 = "			              |   |  ${GREEN}C:\\>${BLUE} 70%  |██████████████      |100%   ${WHITE}|    |\033[F"
COMPIL_8 = "			              |   |  ${GREEN}C:\\>${BLUE} 80%  |████████████████    |100%   ${WHITE}|    |\033[F"
COMPIL_9 = "			              |   |  ${GREEN}C:\\>${BLUE} 90%  |██████████████████  |100%   ${WHITE}|    |\033[F"
COMPIL_10 = "			              |   |  ${GREEN}C:\\>${BLUE} 100% |████████████████████|100%   ${WHITE}|    |"
TEXT_2   = "			              |   |  ${GREEN}C:\\> Compilation SUCCESS               ${WHITE}|    |"
TEXT_3   = "			              |   |  ${GREEN}C:\\> Starting minishell in 3 seconds   ${WHITE}|    |\033[F"
TEXT_4   = "			              |   |  ${GREEN}C:\\> Starting minishell in 2 seconds   ${WHITE}|    |\033[F"
TEXT_5   = "			              |   |  ${GREEN}C:\\> Starting minishell in 1 seconds   ${WHITE}|    |\033[F"
TEXT_6   = "			              |   |  ${RED}C:\\> Segmentation fault                ${WHITE}|    |\033[F"
EMPTY   = " 			              |   |  ${WHITE}                                       ${WHITE}|    |\033[F"
REBOOT   = "			              |   |  ${RED}C:\\> REBOOT                            ${WHITE}|    |\033[F"
TEXT_7   = "			              |   |  ${GREEN}C:\\> Starting minishell                ${WHITE}|    |"
TEXT_8   = "			              |   |  ${GREEN}C:\\> Starting minishell \033[1mSUCCESS\033[0m        ${WHITE}|    |\033[F"

SRC_BUILT_2 = cd_cmd.c cwd.c env_cmd.c exit_cmd_2.c export_cmd2.c username.c check_quotes.c echo_cmd.c exit_cmd.c export_cmd.c \
				unset_cmd.c ft_utils_builtin.c
SRC_BUILT = $(addprefix builtin/,$(SRC_BUILT_2))

SRC_UTILS = main.c utils/ft_utils.c utils/ft_utils2.c utils/ft_utils3.c utils/ft_utils4.c utils/signaux.c

SRC_ERROR = error/ft_error.c error/ft_error_msg.c

SRC_CMD_2 = check_syntax.c double_input_redir2.c from_quotes_to_wrds.c ft_split_minishell_part_2.c write_cmd_in_file.c \
			double_input_redir.c file_to_array.c ft_split_minishell.c get_cmd.c ft_strdup_remov.c input_error.c \
			replace_dollar.c replace_dollar_2.c replace_dollar_3.c file_to_array2.c
SRC_CMD = $(addprefix get_cmd/,$(SRC_CMD_2))

SRC_GNL = gnl/get_next_line_utils.c gnl/get_next_line.c

SRC_MUL_PIPE_2 = child_process.c execute_cmd.c handle_error.c pipex.c ft_make_redir.c single_cmd.c single_cmd2.c builtin_checker.c
SRC_MUL_PIPE = $(addprefix execution/,$(SRC_MUL_PIPE_2))

all : header
	@make -s -C ft_printf/
	@$(CC) $(FLAGS) $(SRC_UTILS) $(SRC_BUILT) $(SRC_CMD) $(SRC_ERROR) $(SRC_GNL) $(SRC_MUL_PIPE) $(LIBFTPRINTF) -o $(NAME)
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
# 	@sleep 1.0
# 	@echo $(EMPTY)
# 	@sleep 0.4
# 	@echo $(REBOOT)
# 	@sleep 0.4
# 	@echo $(EMPTY)
# 	@sleep 0.4
# 	@echo $(REBOOT)
# 	@sleep 0.4
# 	@echo $(EMPTY)
# 	@sleep 0.4
# 	@echo $(REBOOT)
# 	@sleep 0.4
# 	@echo $(EMPTY)
# 	@sleep 0.4
# 	@echo $(REBOOT)
# 	@echo $(EMPTY)
# 	@echo "\033[F\033[F"
# 	@echo $(EMPTY)
# 	@echo "\033[F\033[F"
# 	@echo $(EMPTY)
# 	@echo "\033[F\033[F"
# 	@echo $(EMPTY)
# 	@sleep 2.0
# 	@echo $(TEXT_1)
# 	@echo $(COMPIL_1)
# 	@echo "\033[F"
# 	@sleep 1.0
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
# 	@sleep 0.7
# 	@echo $(EMPTY)
# 	@echo "\033[F\033[F"
# 	@echo $(EMPTY)
# 	@echo "\033[F\033[F"
# 	@echo $(EMPTY)
# 	@echo "\033[F\033[F"
# 	@echo $(EMPTY)
# 	@sleep 0.5
# 	@echo $(TEXT_8)
# 	@make go_down

norm :
	norminette $(SRC_CMD) $(SRC_ERROR) $(SRC_MUL_PIPE) $(SRC_UTILS) $(SRC_BUILT)

lldb : header
	@make -s -C ft_printf/
	@$(CC) $(FLAGS) $(SRC_UTILS) $(SRC_BUILT) $(SRC_CMD) $(SRC_ERROR) $(SRC_GNL) $(SRC_MUL_PIPE) $(LIBFTPRINTF) -o $(NAME) -g
	lldb ./$(NAME)

array :
	@gcc -lreadline array_maker/make_array.c -o make_array
	@./make_array
	@rm make_array
	
leaks : header
	@make -s -C ft_printf/
	@$(CC) $(FLAGS) $(SRC_UTILS) $(SRC_BUILT) $(SRC_CMD) $(SRC_ERROR) $(SRC_GNL) $(SRC_MUL_PIPE) $(LIBFTPRINTF) -o $(NAME)
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
	@echo "			      ███    ███  ██  ███    ██  ██  ███████  ██   ██  ███████  ██       ██           "
	@echo "			      ████  ████  ██  ████   ██  ██  ██       ██   ██  ██       ██       ██           "
	@echo "			      ██ ████ ██  ██  ██ ██  ██  ██  ███████  ███████  █████    ██       ██           "
	@echo "			      ██  ██  ██  ██  ██  ██ ██  ██       ██  ██   ██  ██       ██       ██           "
	@echo "			      ██      ██  ██  ██   ████  ██  ███████  ██   ██  ███████  ███████  ███████      "
	@echo "${GREEN}"
	@echo ""
	@echo '			      ____          _ _                                       ____             _ '
	@echo '			     / ___|___  ___(_) | ___                                 |  _ \ __ _ _   _| |'
	@echo '			    | |   / _ \/ __| | |/ _ \                                | |_) / _` | | | | |'
	@echo '			    | |__|  __/ (__| | |  __/                                |  __/ (_| | |_| | |'
	@echo '			     \____\___|\___|_|_|\___|                                |_|   \__,_|\__,_|_|'
	@echo ""
	@echo ""
	@echo "    ███████╗ ██████╗ ██████╗  ██████╗███████╗    ███████╗████████╗    ██╗  ██╗ ██████╗ ███╗   ██╗███╗   ██╗███████╗██╗   ██╗██████╗ "
	@echo "    ██╔════╝██╔═══██╗██╔══██╗██╔════╝██╔════╝    ██╔════╝╚══██╔══╝    ██║  ██║██╔═══██╗████╗  ██║████╗  ██║██╔════╝██║   ██║██╔══██╗"
	@echo "    █████╗  ██║   ██║██████╔╝██║     █████╗      █████╗     ██║       ███████║██║   ██║██╔██╗ ██║██╔██╗ ██║█████╗  ██║   ██║██████╔╝"
	@echo "    ██╔══╝  ██║   ██║██╔══██╗██║     ██╔══╝      ██╔══╝     ██║       ██╔══██║██║   ██║██║╚██╗██║██║╚██╗██║██╔══╝  ██║   ██║██╔══██╗"
	@echo "    ██║     ╚██████╔╝██║  ██║╚██████╗███████╗    ███████╗   ██║       ██║  ██║╚██████╔╝██║ ╚████║██║ ╚████║███████╗╚██████╔╝██║  ██║"
	@echo "    ╚═╝      ╚═════╝ ╚═╝  ╚═╝ ╚═════╝╚══════╝    ╚══════╝   ╚═╝       ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝"
	@echo "${WHITE}"

	
compil:
	@echo "			                ________________________________________________"
	@echo "			               /                                                \\"
	@echo "			              |    _________________________________________     |"
	@echo "			              |   |                                         |    |"
	@echo $(TEXT_1)
	@echo $(COMPIL_1)
	@echo "			              |   |                                         |    |"
	@echo "			              |   |                                         |    |"
	@echo "			              |   |                                         |    |"
	@echo "			              |   |                                         |    |"
	@echo "			              |   |                                         |    |"
	@echo "			              |   |                                         |    |"
	@echo "			              |   |                                         |    |"
	@echo "			              |   |                                         |    |"
	@echo "			              |   |                                         |    |"
	@echo "			              |   |_________________________________________|    |"
	@echo "			              |                                                  |"
	@echo "			               \\_________________________________________________/"
	@echo "			                      \\___________________________________/"
	@echo "			                   ___________________________________________"
	@echo "			                _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- \`-_"
	@echo "			             _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.\`-_"
	@echo "			          _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\`__\`. .-.-.-.\`-_"
	@echo "			       _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.\`-_"
	@echo "			    _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.\`-_"
	@echo "			   :-------------------------------------------------------------------------:"
	@echo "			   \`---._.-------------------------------------------------------------._.---'"
	@echo ""
	@make go_back

go_back:
	@echo "\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F\033[F"

go_down:
	@echo "\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E\033[E"




.PHONY : fclean re all header clean cnt check leak


