/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:15:59 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 12:16:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static int compare_strjoin(const char *s1, const char *s2)
{
	char *expected = NULL;
	char *actual = ft_strjoin(s1, s2);
	int error = 0;

	if (s1 == NULL && s2 == NULL)
	{
		if (actual != NULL)
		{
			printf("❌ FAIL: ft_strjoin returned non-NULL for NULL s1 and NULL s2\n");
			error = 1;
		}
		return error;
	}

	size_t len1 = s1 ? strlen(s1) : 0;
	size_t len2 = s2 ? strlen(s2) : 0;

	expected = malloc(len1 + len2 + 1);
	if (expected == NULL)
	{
		perror("Failed to allocate memory for expected string");
		free(actual);
		return 1;
	}
	strcpy(expected, s1 ? s1 : "");
	strcat(expected, s2 ? s2 : "");

	if (actual == NULL)
	{
		printf("❌ FAIL: ft_strjoin returned NULL for s1=\"%s\", s2=\"%s\"\n", s1, s2);
		error = 1;
	}
	else if (strcmp(expected, actual) != 0)
	{
		printf("❌ FAIL: ft_strjoin returned incorrect string for s1=\"%s\", s2=\"%s\", expected=\"%s\", actual=\"%s\"\n", s1, s2, expected, actual);
		error = 1;
	}

	free(expected);
	free(actual);
	return error;
}

// TEST CASES

static int test_strjoin_case1(void) { return compare_strjoin("Hello", "World"); }
static int test_strjoin_case2(void) { return compare_strjoin("Hello", ""); }
static int test_strjoin_case3(void) { return compare_strjoin("", "World"); }
static int test_strjoin_case4(void) { return compare_strjoin("", ""); }
static int test_strjoin_case5(void) { return compare_strjoin("Long string part 1", " and even longer part 2"); }
static int test_strjoin_case6(void) { return compare_strjoin("With a null\0 inside", " the second part"); }
static int test_strjoin_case7(void) { return compare_strjoin(NULL, "World"); }
static int test_strjoin_case8(void) { return compare_strjoin("Hello", NULL); }
static int test_strjoin_case9(void) { return compare_strjoin(NULL, NULL); }

int test_ft_strjoin(void)
{
	printf("--- strjoin\t: ");

	if (
		test_strjoin_case1() ||
		test_strjoin_case2() ||
		test_strjoin_case3() ||
		test_strjoin_case4() ||
		test_strjoin_case5() ||
		test_strjoin_case6() ||
		test_strjoin_case7() ||
		test_strjoin_case8() ||
		test_strjoin_case9()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}
