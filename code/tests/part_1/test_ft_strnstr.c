/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:42:22 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 23:58:19 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static char *copy_strnstr(const char *haystack, const char *needle, size_t len) {
	size_t needle_len = strlen(needle);
	if (needle_len == 0) return (char *)haystack;

	for (size_t i = 0; i + needle_len <= len && haystack[i]; i++) {
		if (strncmp(&haystack[i], needle, needle_len) == 0) {
			return (char *)&haystack[i];
		}
	}
	return NULL;
}


static int compare_strnstr(const char *haystack, const char *needle, size_t len)
{
	// char *std_ret = strnstr(haystack, needle, len);
	char *std_ret = copy_strnstr(haystack, needle, len);
	char *ft_ret = ft_strnstr(haystack, needle, len);

	if (std_ret != ft_ret)
	{
		printf("❌ FAIL:\n");
		printf("haystack : \"%s\"\n", haystack);
		printf("needle   : \"%s\"\n", needle);
		printf("len      : %zu\n", len);
		printf("std_ret  : \"%s\"\n", std_ret ? std_ret : "NULL");
		printf("ft_ret   : \"%s\"\n", ft_ret ? ft_ret : "NULL");
		return (1);
	}
	return (0);
}

// TEST CASES

static int test_strnstr_case1(void) { return compare_strnstr("hello world", "world", 11); }		// Needle found at the end
static int test_strnstr_case2(void) { return compare_strnstr("hello world", "hello", 11); }		// Needle found at the beginning
static int test_strnstr_case3(void) { return compare_strnstr("hello world", "o w", 11); }		// Needle found in the middle
static int test_strnstr_case4(void) { return compare_strnstr("hello world", "orldx", 11); }		// Needle not found
static int test_strnstr_case5(void) { return compare_strnstr("hello world", "", 11); }			// Empty needle
static int test_strnstr_case6(void) { return compare_strnstr("", "world", 11); }				// Empty haystack
static int test_strnstr_case7(void) { return compare_strnstr("hello", "lo", 3); }				// len smaller than needle
static int test_strnstr_case8(void) { return compare_strnstr("hello", "lo", 5); }				// len larger than or equal to needle
static int test_strnstr_case9(void) { return compare_strnstr("aaaaaaaaa", "aa", 5); }			// Multiple occurrences
static int test_strnstr_case10(void) { return compare_strnstr("test\0string", "string", 11); }	// Needle after null terminator
static int test_strnstr_case11(void) { return compare_strnstr("test\0string", "\0str", 5); }	// Needle starts with null terminator
static int test_strnstr_case12(void) { return compare_strnstr("longlongstring", "long", 4); }	// Needle at the beginning, len exact
static int test_strnstr_case13(void) { return compare_strnstr("longlongstring", "long", 5); }	// Needle at the beginning, len longer
static int test_strnstr_case14(void) { return compare_strnstr("longlongstring", "str", 12); }	// Needle in the middle
static int test_strnstr_case15(void) { return compare_strnstr("longlongstring", "ring", 12); }	// Needle at the end
static int test_strnstr_case16(void) { return compare_strnstr("abc", "abcd", 3); }				// Needle longer than remaining haystack
static int test_strnstr_case17(void) { return compare_strnstr("abc", "abcd", 4); }				// Needle longer than haystack

int test_ft_strnstr(void)
{
	printf("--- strnstr\t: ");

	if (
		test_strnstr_case1() ||
		test_strnstr_case2() ||
		test_strnstr_case3() ||
		test_strnstr_case4() ||
		test_strnstr_case5() ||
		test_strnstr_case6() ||
		test_strnstr_case7() ||
		test_strnstr_case8() ||
		test_strnstr_case9() ||
		test_strnstr_case10() ||
		test_strnstr_case11() ||
		test_strnstr_case12() ||
		test_strnstr_case13() ||
		test_strnstr_case14() ||
		test_strnstr_case15() ||
		test_strnstr_case16() ||
		test_strnstr_case17()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}
