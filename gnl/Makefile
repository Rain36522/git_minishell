# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pudry <pudry@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 17:17:07 by pudry             #+#    #+#              #
#    Updated: 2023/11/12 17:20:19 by pudry            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
CC = gcc
FLAGS = -Wall -Wextra -Werror


SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all : gen_obj
	@ar rcs $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

gen_obj :
	@$(CC) $(CFLAGS) -c $(SRC)



.PHONY : fclean re all clean