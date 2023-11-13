# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pudry <pudry@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 09:10:43 by pudry             #+#    #+#              #
#    Updated: 2023/10/23 17:39:45 by pudry            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = GCC
FLAGS = -Wall -Wextra -Werror
LIB = ./libft/libft.a

SRC = ft_printf.c ft_put.c ft_put2.c ft_util.c
OBJ = ft_printf.o ft_put.o ft_put2.o ft_util.o

$(NAME) : $(OBJ)
	make -C libft/
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $(OBJ)

all : gen_obj $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	make fclean -C libft/

re : fclean clean all

gen_obj :
	$(CC) $(FLAGS) -c $(SRC)

.PHONY : clean fclean re all
