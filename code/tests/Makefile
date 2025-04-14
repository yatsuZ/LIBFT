# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/13 11:23:49 by yzaoui            #+#    #+#              #
#    Updated: 2025/04/14 15:16:21 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# pour dire que la cible ne sagit pas de nom fichier
.PHONY: all re clean fclean bonus val

############### OBJ du projet LIBFT

VAL_CMD = valgrind --tool=memcheck \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--track-fds=yes \
		--read-var-info=yes \
		# --log-file=valgrind.log

PART_1_PATH = part_1/
PART_1_SRC =	test_ft_isalpha.c	\
				test_ft_isdigit.c	\
				test_ft_isalnum.c	\
				test_ft_isascii.c	\
				test_ft_isprint.c	\
				test_ft_strlen.c	\
				test_ft_memset.c	\
				test_ft_bzero.c		\
				test_ft_memcpy.c	\
				test_ft_memmove.c	\
				test_ft_strlcpy.c	\
				test_ft_strlcat.c	\
				test_ft_toupper.c	\
				test_ft_tolower.c	\
				test_ft_strchr.c	\
				test_ft_strrchr.c	\
				test_ft_strncmp.c	\
				test_ft_memchr.c	\
				test_ft_memcmp.c	\
				test_ft_strnstr.c	\
				test_ft_atoi.c		\
				test_ft_calloc.c	\
				test_ft_strdup.c

PART_2_PATH = part_2/
PART_2_SRC = test_ft_substr.c		\
			 test_ft_strjoin.c		\
			 test_ft_strtrim.c		\
			 test_ft_split.c		\
			 test_ft_itoa.c			\
			 test_ft_strmapi.c		\
			 test_ft_striteri.c		\
			 test_ft_putchar_fd.c	\
			 test_ft_putstr_fd.c	\
			 test_ft_putendl_fd.c	\
			 test_ft_putnbr_fd.c

PART_BONUS_PATH = part_bonus/
PART_BONUS_SRC = 	test_ft_lstnew_bonus.c			\
					test_ft_lstadd_front_bonus.c	\
					test_ft_lstsize_bonus.c			\
					test_ft_lstlast_bonus.c			\
					test_ft_lstadd_back_bonus.c		\
					test_ft_lstdelone_bonus.c		\
					test_ft_lstclear_bonus.c		\
					test_ft_lstiter_bonus.c			\
					test_ft_lstmap_bonus.c

LIBFT_SRC =	main.c										\
			${addprefix ${PART_1_PATH}, ${PART_1_SRC}}	\
			${addprefix ${PART_2_PATH}, ${PART_2_SRC}}	\

LIBFT_SRC_BONUS = ${addprefix ${PART_BONUS_PATH}, ${PART_BONUS_SRC}}

OBJ_PATH = obj/

PROG_OBJ = ${addprefix ${OBJ_PATH}, ${LIBFT_SRC:.c=.o}}

PROG_OBJ_BONUS = ${addprefix ${OBJ_PATH}, ${LIBFT_SRC_BONUS:.c=.o}}

############### ligne de commande

RM = rm -rf
CC = cc
C_FLAGS = -Wall -Wextra -Werror -g3

PROGRAM_NAME = libft_tester.out

LIBFT_PATH = ./../LIBFT # donner le chemin de votre libft

ARCHIVE_CMD = -L$(LIBFT_PATH) -lft -I$(LIBFT_PATH)

MAKE_LIBFT = make -s -C $(LIBFT_PATH)

############### COMMANDE OBLIGATOIRE

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(PROG_OBJ)
	$(MAKE_LIBFT)
	$(CC) $(C_FLAGS) $(PROG_OBJ) -o $(PROGRAM_NAME) $(ARCHIVE_CMD)

bonus: $(PROGRAM_NAME) $(PROG_OBJ_BONUS)
	$(CC) $(C_FLAGS) $(PROG_OBJ) $(PROG_OBJ_BONUS) -o $(PROGRAM_NAME) $(ARCHIVE_CMD)

$(OBJ_PATH)%.o: %.c
	mkdir -p $(@D)
	$(CC) -c -o $@ $< $(C_FLAGS)

clean:
	$(MAKE_LIBFT) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	$(MAKE_LIBFT) fclean
	rm -f $(PROGRAM_NAME)

val: bonus
	${VAL_CMD} ./${PROGRAM_NAME}

re: fclean all