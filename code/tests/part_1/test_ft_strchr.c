/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:53:34 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 00:53:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"


static int compare_strchr(const char *str, int c)
{
	char *std_ret = strchr(str, c);
	char *ft_ret = ft_strchr(str, c);

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

static  int test_strchr_case1(void) { return compare_strchr("Hello", 'e'); }			// Caractère trouvé en milieu
static  int test_strchr_case2(void) { return compare_strchr("Hello", 'H'); }			// Caractère trouvé au début
static  int test_strchr_case3(void) { return compare_strchr("Hello", 'o'); }			// Caractère trouvé à la fin
static  int test_strchr_case4(void) { return compare_strchr("Hello", 'z'); }			// Caractère non trouvé
static  int test_strchr_case5(void) { return compare_strchr("", 'a'); }					// Chaîne vide
static  int test_strchr_case6(void) { return compare_strchr("Hello", '\0'); }			// Recherche du '\0'
static  int test_strchr_case7(void) { return compare_strchr("Hello World!", ' '); }		// Recherche d'un espace
static  int test_strchr_case8(void) { return compare_strchr("abc\001def", '\001'); }	// Caractère non imprimable
static  int test_strchr_case9(void) { return compare_strchr("a", 'a'); }				// Test avec une chaîne de longueur 1
static  int test_strchr_case10(void) { return compare_strchr("hello", 'h'); }			// Caractère trouvé au début

int test_ft_strchr(void)
{
	printf("--- strchr\t: ");

	if (
		test_strchr_case1() ||
		test_strchr_case2() ||
		test_strchr_case3() ||
		test_strchr_case4() ||
		test_strchr_case5() ||
		test_strchr_case6() ||
		test_strchr_case7() ||
		test_strchr_case8() ||
		test_strchr_case9() ||
		test_strchr_case10()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}
