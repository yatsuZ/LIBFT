# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/13 12:17:34 by yzaoui            #+#    #+#              #
#    Updated: 2025/04/15 16:24:26 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# pour dire que la cible ne sagit pas de nom fichier
.PHONY: all re clean fclean bonus

############### OBJ du projet LIBFT

PART_1_PATH = part_1/
PART_1_SRC =	ft_isalpha.c	\
				ft_isdigit.c	\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_strlen.c		\
				ft_memset.c		\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_memmove.c	\
				ft_strlcpy.c	\
				ft_strlcat.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strncmp.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_strnstr.c	\
				ft_atoi.c		\
				ft_calloc.c		\
				ft_strdup.c

PART_2_PATH = part_2/
PART_2_SRC = ft_substr.c		\
			 ft_strjoin.c		\
			 ft_strtrim.c		\
			 ft_split.c			\
			 ft_itoa.c			\
			 ft_strmapi.c		\
			 ft_striteri.c		\
			 ft_putchar_fd.c	\
			 ft_putstr_fd.c		\
			 ft_putendl_fd.c	\
			 ft_putnbr_fd.c

PART_BONUS_PATH = part_bonus/
PART_BONUS_SRC = 	ft_lstnew_bonus.c	\
					ft_lstadd_front_bonus.c	\
					ft_lstsize_bonus.c	\
					ft_lstlast_bonus.c	\
					ft_lstadd_back_bonus.c	\
					ft_lstdelone_bonus.c	\
					ft_lstclear_bonus.c	\
					ft_lstiter_bonus.c	\
					ft_lstmap_bonus.c

LIBFT_SRC =	${addprefix ${PART_1_PATH}, ${PART_1_SRC}}	\
			${addprefix ${PART_2_PATH}, ${PART_2_SRC}}	\

LIBFT_SRC_BONUS = ${LIBFT_SRC}	\
			${addprefix ${PART_BONUS_PATH}, ${PART_BONUS_SRC}}

OBJ_PATH = obj/

PROG_OBJ = ${addprefix ${OBJ_PATH}, ${LIBFT_SRC:.c=.o}}

PROG_OBJ_BONUS = ${addprefix ${OBJ_PATH}, ${LIBFT_SRC_BONUS:.c=.o}}

############### ligne de commande

RM = rm -rf
CC = cc
C_FLAGS = -Wall -Wextra -Werror # -g3
AR = ar -rc

PROGRAM_NAME = libft.a

############### COMMANDE OBLIGATOIRE

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(PROG_OBJ)
	$(AR) $(PROGRAM_NAME) $(PROG_OBJ)

bonus: $(PROG_OBJ_BONUS)
	$(AR) $(PROGRAM_NAME) $(PROG_OBJ_BONUS)

$(OBJ_PATH)%.o: %.c
	mkdir -p $(@D)
	$(CC) -c -o $@ $< $(C_FLAGS)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(PROGRAM_NAME)

re: fclean all