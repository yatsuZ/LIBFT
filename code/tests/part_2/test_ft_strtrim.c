/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:50:10 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 13:11:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static bool is_in_set(char c, const char *set)
{
	if (!set)
		return false;
	while (*set)
	{
		if (*set == c)
			return true;
		set++;
	}
	return false;
}

static char *simulate_strtrim(const char *s, const char *set)
{
	if (!s)
		return NULL;
	if (!set)
		return strdup(s);

	size_t start = 0;
	while (s[start] && is_in_set(s[start], set))
		start++;

	size_t end = strlen(s);
	while (end > start && is_in_set(s[end - 1], set))
		end--;

	size_t len = end - start;
	char *result = malloc(len + 1);
	if (result)
	{
		strncpy(result, s + start, len);
		result[len] = '\0';
	}
	return result;
}

static int compare_strtrim(const char *s, const char *set)
{
	char *expected = simulate_strtrim(s, set);
	char *actual = ft_strtrim(s, set);
	int error = 0;

	if (expected == NULL && actual != NULL)
	{
		printf("❌ FAIL: Simulated strtrim returned NULL, ft_strtrim did not (s=\"%s\", set=\"%s\")\n", s, set);
		error = 1;
	}
	else if (expected != NULL && actual == NULL)
	{
		printf("❌ FAIL: ft_strtrim returned NULL, simulated strtrim did not (s=\"%s\", set=\"%s\")\n", s, set);
		error = 1;
	}
	else if (expected != NULL && actual != NULL)
	{
		if (strcmp(expected, actual) != 0)
		{
			printf("❌ FAIL: ft_strtrim returned incorrect string for s=\"%s\", set=\"%s\", expected=\"%s\", actual=\"%s\"\n", s, set, expected, actual);
			error = 1;
		}
		free(actual);
		free(expected);
	}
	else if (expected == NULL && actual == NULL)
	{
		// Both returned NULL, considered a pass
	}
	else
	{
		printf("❌ FAIL: Unexpected comparison result for s=\"%s\", set=\"%s\"\n", s, set);
		error = 1;
	}

	return error;
}

// TEST CASES

static int test_strtrim_case1(void) { return compare_strtrim("   Hello World   ", " "); }
static int test_strtrim_case2(void) { return compare_strtrim("---Hello---", "-"); }
static int test_strtrim_case3(void) { return compare_strtrim("aabbaabbaaTestabbaa", "ab"); }
static int test_strtrim_case4(void) { return compare_strtrim("Test", " "); }
static int test_strtrim_case5(void) { return compare_strtrim("   ", " "); }
static int test_strtrim_case6(void) { return compare_strtrim("", " "); }
static int test_strtrim_case7(void) { return compare_strtrim("Hello", ""); }
static int test_strtrim_case8(void) { return compare_strtrim(" \t\n Hello \t\n ", " \t\n"); }
static int test_strtrim_case9(void) { return compare_strtrim("12345Test54321", "12345"); }
static int test_strtrim_case10(void) { return compare_strtrim("Test12345", "12345"); }
static int test_strtrim_case11(void) { return compare_strtrim(NULL, " "); }
static int test_strtrim_case12(void) { return compare_strtrim("Hello", NULL); }
static int test_strtrim_case13(void) { return compare_strtrim(NULL, NULL); }
static int test_strtrim_case14(void) { return compare_strtrim("z", "abcdefghijklmnopqrstuvwxyz"); }
static int test_strtrim_case15(void) { return compare_strtrim("abcdefghijklmnopqrstuvwxyz", "z"); }

int test_ft_strtrim(void)
{
	printf("--- strtrim\t: ");

	if (
		test_strtrim_case1() ||
		test_strtrim_case2() ||
		test_strtrim_case3() ||
		test_strtrim_case4() ||
		test_strtrim_case5() ||
		test_strtrim_case6() ||
		test_strtrim_case7() ||
		test_strtrim_case8() ||
		test_strtrim_case9() ||
		test_strtrim_case10() ||
		test_strtrim_case11() ||
		test_strtrim_case12() ||
		test_strtrim_case13() ||
		test_strtrim_case14() ||
		test_strtrim_case15()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}
