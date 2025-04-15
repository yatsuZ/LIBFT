/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:19:00 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 00:54:55 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"


static int compare_strrchr(const char *str, int c)
{
	char *std_ret = strrchr(str, c);
	char *ft_ret = ft_strrchr(str, c);

	if (std_ret != ft_ret)
	{
		printf("❌ FAIL:\n");
		printf("str       : \"%s\"\n", str);
		printf("c         : '%c' (ASCII: %d)\n", c, c);
		printf("std_ret   : \"%s\"\n", std_ret ? std_ret : "NULL");
		printf("ft_ret    : \"%s\"\n", ft_ret ? ft_ret : "NULL");
		return (1);
	}
	return (0);
}

// TEST CASES

static  int test_strrchr_case1(void) { return compare_strrchr("Hello", 'e'); }			// Caractère trouvé en milieu
static  int test_strrchr_case2(void) { return compare_strrchr("Hello", 'H'); }			// Caractère trouvé au début
static  int test_strrchr_case3(void) { return compare_strrchr("Hello", 'o'); }			// Caractère trouvé à la fin
static  int test_strrchr_case4(void) { return compare_strrchr("Hello", 'l'); }			// Caractère non trouvé
static  int test_strrchr_case5(void) { return compare_strrchr("", 'a'); }				// Chaîne vide
static  int test_strrchr_case6(void) { return compare_strrchr("Hello", '\0'); }			// Recherche du '\0'
static  int test_strrchr_case7(void) { return compare_strrchr("Hello World!", 'o'); }	// Recherche d'un espace
static  int test_strrchr_case8(void) { return compare_strrchr("abc\001def", '\001'); }	// Caractère non imprimable
static  int test_strrchr_case9(void) { return compare_strrchr("a", 'a'); }				// Test avec une chaîne de longueur 1
static  int test_strrchr_case10(void) { return compare_strrchr("hello", 'h'); }			// Caractère trouvé au début

int test_ft_strrchr(void)
{
	printf("--- strrchr\t: ");

	if (
		test_strrchr_case1() ||
		test_strrchr_case2() ||
		test_strrchr_case3() ||
		test_strrchr_case4() ||
		test_strrchr_case5() ||
		test_strrchr_case6() ||
		test_strrchr_case7() ||
		test_strrchr_case8() ||
		test_strrchr_case9() ||
		test_strrchr_case10()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}
