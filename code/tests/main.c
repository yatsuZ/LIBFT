/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:24:01 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 00:53:10 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft_tester.h"

void show_memcpy_vs_memmove(void)
{
	char *str1 = strdup("1234567890");
	char *str2 = strdup("1234567890");

	printf("Avant copie (chevauchement):\n");
	printf("str1 (ft_memcpy) : %s\n", str1);
	printf("str2 (ft_memmove): %s\n", str2);

	// Utilisation de memcpy : comportement indéfini si chevauchement
	ft_memcpy((str1) + 2, str1, 8);  // Copie les 8 premiers caractères à partir de str1[2]

	// Utilisation de memmove : gère correctement le chevauchement
	ft_memmove((str2) + 2, str2, 8);

	printf("\nAprès copie:\n");
	printf("str1 (ft_memcpy) : %s\n", str1);
	printf("str2 (ft_memmove): %s\n", str2);
	free(str1);
	free(str2);
}


static void	test_part1(void)
{
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memmove();
	// show_memcpy_vs_memmove();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strchr();
	test_ft_strrchr();
}

int	main(void)
{
	// (void) argc;
	// (void) argv;

	test_part1();
	return (0);
}