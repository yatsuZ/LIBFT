/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:15:14 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 22:17:10 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static int compare_memcmp(const void *s1, const void *s2, size_t n)
{
	int std_ret = memcmp(s1, s2, n);
	int ft_ret = ft_memcmp(s1, s2, n);

	if ((std_ret > 0 && ft_ret <= 0) || (std_ret <= 0 && ft_ret > 0))
	{
		printf("❌ FAIL:\n");
		printf("s1      : %p\n", s1);
		if (s1)
			printf("s1 (hex): ");
		for (size_t i = 0; s1 && i < n; i++)
			printf("%02x ", ((unsigned char *)s1)[i]);
		if (s1)
			printf("\n");
		printf("s2      : %p\n", s2);
		if (s2)
			printf("s2 (hex): ");
		for (size_t i = 0; s2 && i < n; i++)
			printf("%02x ", ((unsigned char *)s2)[i]);
		if (s2)
			printf("\n");
		printf("n       : %zu\n", n);
		printf("std_ret : %d\n", std_ret);
		printf("ft_ret  : %d\n", ft_ret);
		return (1);
	}
	return (0);
}

// TEST CASES

static int test_memcmp_case1(void) { return compare_memcmp("test", "test", 4); }			// Identical strings
static int test_memcmp_case2(void) { return compare_memcmp("test", "tesu", 4); }			// Different character in the middle
static int test_memcmp_case3(void) { return compare_memcmp("test", "tea", 4); }				// First string longer
static int test_memcmp_case4(void) { return compare_memcmp("tea", "test", 4); }				// Second string longer
static int test_memcmp_case5(void) { return compare_memcmp("abc", "abd", 3); }				// Different at the last compared byte
static int test_memcmp_case6(void) { return compare_memcmp("abc", "abc", 0); }				// n = 0
static int test_memcmp_case7(void) { return compare_memcmp("", "abc", 3); }					// First string empty
static int test_memcmp_case8(void) { return compare_memcmp("abc", "", 3); }					// Second string empty
static int test_memcmp_case9(void) { return compare_memcmp("", "", 3); }					// Both strings empty
static int test_memcmp_case10(void) { return compare_memcmp("test\200", "test\0", 5); }		// Comparing with different ASCII values
static int test_memcmp_case11(void) { return compare_memcmp("test\0abc", "test\0def", 8);}	// Comparing beyond null terminator
static int test_memcmp_case12(void) { return compare_memcmp("abc", "ab", 2); }				// First longer, n < length
static int test_memcmp_case13(void) { return compare_memcmp("ab", "abc", 2); }				// Second longer, n < length
static int test_memcmp_case14(void)
{
	unsigned char buf1[] = {0, 1, 2, 3, 4};
	unsigned char buf2[] = {0, 1, 2, 3, 5};
	return compare_memcmp(buf1, buf2, 5);
}
static int test_memcmp_case15(void)
{
	unsigned char buf1[] = {0, 1, 2, 3, 4};
	unsigned char buf2[] = {0, 1, 2, 3, 4};
	return compare_memcmp(buf1, buf2, 5);
}
static int test_memcmp_case16(void)
{
	unsigned char buf1[] = {0, 1, 2};
	unsigned char buf2[] = {0, 1, 2, 3};
	return compare_memcmp(buf1, buf2, 3);
}

int test_ft_memcmp(void)
{
	printf("--- memcmp\t: ");

	if (
		test_memcmp_case1() ||
		test_memcmp_case2() ||
		test_memcmp_case3() ||
		test_memcmp_case4() ||
		test_memcmp_case5() ||
		test_memcmp_case6() ||
		test_memcmp_case7() ||
		test_memcmp_case8() ||
		test_memcmp_case9() ||
		test_memcmp_case10() ||
		test_memcmp_case11() ||
		test_memcmp_case12() ||
		test_memcmp_case13() ||
		test_memcmp_case14() ||
		test_memcmp_case15() ||
		test_memcmp_case16()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}