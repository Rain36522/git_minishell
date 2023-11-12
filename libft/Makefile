# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pudry <pudry@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 11:40:33 by paul              #+#    #+#              #
#    Updated: 2023/11/12 17:27:17 by pudry            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#compilateur
CC = gcc
#flags du compilateur
CFLAGS = -Wall -Wextra -Werror
#name du fichier / dossier retourner
NAME = libft.a
#source : nom des fichiers
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
	

#Reprise des noms du fichier et remplacement du .c en .o
#OBJ = $(SRC:.c=.o)
OBJ = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o \
	ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o \
	ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o \
	ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o \
	ft_strchr.o ft_strdup.o ft_striteri.o ft_strjoin.o ft_strlcat.o \
	ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o \
	ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o

SRC_bonus = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

OBJ_bonus = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o \
			ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o \
			ft_lstmap.o

#cette ligne dit comment génerer le fichier name avec les objets
#c'est une fonction.

all : gen_obj $(NAME)


$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)

#fonction pour générer le fichier Libft.a

bonus : $(OBJ_bonus)
	@ar rcs $(NAME) $(OBJ_bonus)

#fonction nettoyage fichier objet
clean :
	@rm -f $(OBJ) $(OBJ_bonus)
#nettoyage fichier objet + delete libft.a
fclean : clean
	@rm -f $(NAME)
#delete all file et compile again
re : fclean all

gen_obj :
	@$(CC) $(CFLAGS) -c $(SRC)

gen_obj_bonus :
	@$(CC) $(CFLAGS) -c $(SRC_bonus)

#Ligne pour éviter que ces fonctions puissent être considéré comme fichier
.PHONY: clean fclean all re bonus
