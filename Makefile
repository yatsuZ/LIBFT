# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 16:34:46 by yzaoui            #+#    #+#              #
#    Updated: 2025/05/08 17:15:10 by yzaoui           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft

LIBFT_DIR	= code/LIBFT
TESTS_DIR	= code/tests
PATH_EXEC = ./code/tests/libft_tester.out
.PHONY: all clean fclean re test

help:
	@echo "Usage : make [target]"
	@echo ""
	@echo "Targets disponibles :"
	@echo "  all     - Compile la libft"
	@echo "  test    - Compile la libft et les tests, puis exécute le binaire de test"
	@echo "  clean   - Supprime les fichiers objets (.o) dans libft et tests"
	@echo "  fclean  - Supprime les objets ET les exécutables dans libft et tests"
	@echo "  re      - Exécute 'fclean' puis 'all'"
	@echo "  help    - Affiche cette aide"

all:
	@$(MAKE) -C $(LIBFT_DIR)

test: all
	@$(MAKE) -C $(TESTS_DIR)
	$(PATH_EXEC)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(TESTS_DIR)

fclean:
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(TESTS_DIR)

re: fclean all
