/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:16:46 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 21:18:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static int compare_strncmp(const char *s1, const char *s2, size_t n)
{
	int std_ret = strncmp(s1, s2, n);
	int ft_ret = ft_strncmp(s1, s2, n);

	if ((std_ret > 0 && ft_ret <= 0) || (std_ret <= 0 && ft_ret > 0))
	{
		printf("❌ FAIL:\n");
		printf("s1      : \"%s\"\n", s1);
		printf("s2      : \"%s\"\n", s2);
		printf("n       : %zu\n", n);
		printf("std_ret : %d\n", std_ret);
		printf("ft_ret  : %d\n", ft_ret);
		return (1);
	}
	return (0);
}

// TEST CASES
	
static int test_strncmp_case1(void) { return compare_strncmp("test", "test", 4); }				// Identiques
static int test_strncmp_case2(void) { return compare_strncmp("test", "tesu", 4); }				// Différence au milieu
static int test_strncmp_case3(void) { return compare_strncmp("test", "tea", 4); }				// s1 plus long
static int test_strncmp_case4(void) { return compare_strncmp("tea", "test", 4); }				// s2 plus long
static int test_strncmp_case5(void) { return compare_strncmp("abc", "abd", 3); }				// Différence à la fin de la comparaison
static int test_strncmp_case6(void) { return compare_strncmp("abc", "abc", 0); }				// n = 0
static int test_strncmp_case7(void) { return compare_strncmp("", "abc", 3); }					// s1 vide
static int test_strncmp_case8(void) { return compare_strncmp("abc", "", 3); }					// s2 vide
static int test_strncmp_case9(void) { return compare_strncmp("", "", 3); }						// s1 et s2 vides
static int test_strncmp_case10(void) { return compare_strncmp("test\200", "test\0", 5); }		// Comparaison avec \\200 et \\0
static int test_strncmp_case11(void) { return compare_strncmp("test\0abc", "test\0def", 8);}	// Comparaison au-delà du \\0
static int test_strncmp_case12(void) { return compare_strncmp("abc", "ab", 2); }				// s1 plus long, n < len(s1)
static int test_strncmp_case13(void) { return compare_strncmp("ab", "abc", 2); }				// s2 plus long, n < len(s2)

int test_ft_strncmp(void)
{
	printf("--- strncmp\t: ");

	if (
		test_strncmp_case1() ||
		test_strncmp_case2() ||
		test_strncmp_case3() ||
		test_strncmp_case4() ||
		test_strncmp_case5() ||
		test_strncmp_case6() ||
		test_strncmp_case7() ||
		test_strncmp_case8() ||
		test_strncmp_case9() ||
		test_strncmp_case10() ||
		test_strncmp_case11() ||
		test_strncmp_case12() ||
		test_strncmp_case13()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}
