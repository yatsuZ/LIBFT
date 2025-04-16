/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:47:31 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 21:59:15 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static int compare_memchr(const void *s, int c, size_t n)
{
	void *std_ret = NULL;// memchr nont pas de securité
	if (s)
		std_ret = memchr(s, c, n);
	void *ft_ret = ft_memchr(s, c, n);

	if (std_ret != ft_ret)
	{
		printf("❌ FAIL:\n");
		printf("s       : %p\n", s);
		if (s)
			printf("s (str) : \"%.*s\"\n", (int)n, (const char *)s);
		printf("c       : '%c' (ASCII: %d)\n", c, c);
		printf("n       : %zu\n", n);
		printf("std_ret : %p\n", std_ret);
		printf("ft_ret  : %p\n", ft_ret);
		return (1);
	}
	return (0);
}

// TEST CASES

static int test_memchr_case1(void) { return compare_memchr("Hello", 'e', 5); }         // Character found in the middle
static int test_memchr_case2(void) { return compare_memchr("Hello", 'H', 5); }         // Character found at the beginning
static int test_memchr_case3(void) { return compare_memchr("Hello", 'o', 5); }         // Character found at the end
static int test_memchr_case4(void) { return compare_memchr("Hello", 'l', 2); }         // Character found within n bytes
static int test_memchr_case5(void) { return compare_memchr("Hello", 'x', 5); }         // Character not found
static int test_memchr_case6(void) { return compare_memchr("", 'a', 0); }              // Empty string, n = 0
static int test_memchr_case7(void) { return compare_memchr("abc\0def", '\0', 7); }     // Searching for null terminator
static int test_memchr_case8(void) { return compare_memchr("abc\0def", 'd', 7); }      // Character after null terminator
static int test_memchr_case9(void) { return compare_memchr("aaaaa", 'a', 5); }         // Multiple occurrences
static int test_memchr_case10(void) { return compare_memchr("test", 116, 4); }        // Searching for ASCII value
static int test_memchr_case11(void) { return compare_memchr(NULL, 'a', 5); }          // NULL pointer with n > 0
static int test_memchr_case12(void) { return compare_memchr(NULL, 'a', 0); }          // NULL pointer with n = 0
static int test_memchr_case13(void)
{
	char buffer[10] = "abcdefghi";
	return compare_memchr(buffer, 'g', 10);
}
static int test_memchr_case14(void)
{
	char buffer[10] = "abcdefghi";
	return compare_memchr(buffer + 2, 'e', 5);
}

int test_ft_memchr(void)
{
	printf("--- memchr\t: ");

	if (
		test_memchr_case1() ||
		test_memchr_case2() ||
		test_memchr_case3() ||
		test_memchr_case4() ||
		test_memchr_case5() ||
		test_memchr_case6() ||
		test_memchr_case7() ||
		test_memchr_case8() ||
		test_memchr_case9() ||
		test_memchr_case10() ||
		test_memchr_case11() ||
		test_memchr_case12() ||
		test_memchr_case13() ||
		test_memchr_case14()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}
