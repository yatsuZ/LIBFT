/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:24:01 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 01:17:59 by yzaoui           ###   ########.fr       */
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
	test_ft_isalpha();	// 1
	test_ft_isdigit();	// 2
	test_ft_isalnum();	// 3
	test_ft_isascii();	// 4
	test_ft_isprint();	// 5
	test_ft_strlen();	// 6
	test_ft_memset();	// 7
	test_ft_bzero();	// 8
	test_ft_memcpy();	// 9
	test_ft_memmove();	// 10
	// show_memcpy_vs_memmove();
	test_ft_strlcpy();	// 11
	test_ft_strlcat();	// 12
	test_ft_toupper();	// 13
	test_ft_tolower();	// 14
	test_ft_strchr();	// 15
	test_ft_strrchr();	// 16
	test_ft_strncmp();	// 17
	test_ft_memchr();	// 18
	test_ft_memcmp();	// 19
	test_ft_strnstr();	// 20
	test_ft_atoi();		// 21
	test_ft_calloc();	// 22
	test_ft_strdup();	//23
}

int	main(void)
{
	// (void) argc;
	// (void) argv;

	test_part1();
	return (0);
}