/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:33:23 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 11:34:34 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static int compare_substr(const char *s, unsigned int start, size_t len)
{
	char *std_ret = NULL;
	char *ft_ret = ft_substr(s, start, len);
	int error = 0;
	size_t s_len = s ? strlen(s) : 0;
	size_t std_len = 0;

	// Simulate standard substr behavior for comparison
	if (s == NULL || start >= s_len || len == 0)
	{
		std_ret = strdup("");
	}
	else
	{
		std_len = (len > s_len - start) ? (s_len - start) : len;
		std_ret = malloc(std_len + 1);
		if (std_ret)
		{
			strncpy(std_ret, s + start, std_len);
			std_ret[std_len] = '\0';
		}
	}

	if (std_ret == NULL && ft_ret != NULL)
	{
		printf("❌ FAIL: Simulated substr returned NULL, ft_substr did not (s=\"%s\", start=%u, len=%zu)\n", s, start, len);
		error = 1;
	}
	else if (std_ret != NULL && ft_ret == NULL)
	{
		printf("❌ FAIL: ft_substr returned NULL, simulated substr did not (s=\"%s\", start=%u, len=%zu)\n", s, start, len);
		error = 1;
	}
	else if (std_ret != NULL && ft_ret != NULL)
	{
		if (strcmp(std_ret, ft_ret) != 0)
		{
			printf("❌ FAIL: Simulated substr and ft_substr returned different strings (s=\"%s\", start=%u, len=%zu, std=\"%s\", ft=\"%s\")\n", s, start, len, std_ret, ft_ret);
			error = 1;
		}
		free(std_ret);
		free(ft_ret);
	}
	else if (std_ret == NULL && ft_ret == NULL)
	{
		// Both returned NULL, considered a pass for this case
	}
	else
	{
		// Should not happen based on the conditions above, but for completeness
		printf("❌ FAIL: Unexpected comparison result (s=\"%s\", start=%u, len=%zu)\n", s, start, len);
		error = 1;
	}

	return error;
}

// TEST CASES

static int test_substr_case1(void) { return compare_substr("Hello World", 6, 5); }	// Substring in the middle
static int test_substr_case2(void) { return compare_substr("Hello World", 0, 5); }	// Substring from the beginning
static int test_substr_case3(void) { return compare_substr("Hello World", 6, 10); }	// len exceeds remaining string
static int test_substr_case4(void) { return compare_substr("Hello World", 10, 5); }	// start near the end
static int test_substr_case5(void) { return compare_substr("Hello World", 11, 5); }	// start at the end
static int test_substr_case6(void) { return compare_substr("Hello World", 0, 0); }	// len is 0
static int test_substr_case7(void) { return compare_substr("Hello World", 15, 5); }	// start out of bounds
static int test_substr_case8(void) { return compare_substr("", 0, 5); }				// Empty string
static int test_substr_case9(void) { return compare_substr("abc", 1, 1); }			// Single character substring
static int test_substr_case10(void) { return compare_substr("abc", 0, 3); }			// Entire string
static int test_substr_case11(void) { return compare_substr("abc", 0, INT_MAX); }	// len is INT_MAX
static int test_substr_case12(void) { return compare_substr("abc", 2, INT_MAX); }	// start near end, len is INT_MAX
static int test_substr_case13(void) { return compare_substr(NULL, 0, 5); }			// s is NULL

int test_ft_substr(void)
{
	printf("--- substr\t: ");

	if (
		test_substr_case1() ||
		test_substr_case2() ||
		test_substr_case3() ||
		test_substr_case4() ||
		test_substr_case5() ||
		test_substr_case6() ||
		test_substr_case7() ||
		test_substr_case8() ||
		test_substr_case9() ||
		test_substr_case10() ||
		test_substr_case11() ||
		test_substr_case12() ||
		test_substr_case13()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}
