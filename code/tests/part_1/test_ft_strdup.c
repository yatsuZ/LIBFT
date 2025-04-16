/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:17:11 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 01:17:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static int compare_strdup(const char *s)
{
	char *std_ret = strdup(s);
	char *ft_ret = ft_strdup(s);
	int error = 0;

	if (std_ret == NULL && ft_ret != NULL)
	{
		printf("❌ FAIL: strdup returned NULL, ft_strdup did not (s=\"%s\")\n", s);
		error = 1;
	}
	else if (std_ret != NULL && ft_ret == NULL)
	{
		printf("❌ FAIL: ft_strdup returned NULL, strdup did not (s=\"%s\")\n", s);
		error = 1;
	}
	else if (std_ret != NULL && ft_ret != NULL)
	{
		if (strcmp(std_ret, ft_ret) != 0)
		{
			printf("❌ FAIL: strdup and ft_strdup returned different strings (s=\"%s\", std=\"%s\", ft=\"%s\")\n", s, std_ret, ft_ret);
			error = 1;
		}
		free(std_ret);
		free(ft_ret);
	}

	return error;
}

// TEST CASES

static int test_strdup_case1(void) { return compare_strdup("Hello"); }            // Basic string
static int test_strdup_case2(void) { return compare_strdup(""); }                 // Empty string
static int test_strdup_case3(void) { return compare_strdup("SingleChar"); }       // Single character string
static int test_strdup_case4(void) { return compare_strdup("With Spaces"); }      // String with spaces
static int test_strdup_case5(void) { return compare_strdup("LongStringgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"); } // Long string
static int test_strdup_case6(void) { return compare_strdup("String\0WithNull"); } // String with a null byte in the middle

int test_ft_strdup(void)
{
	printf("--- strdup\t: ");

	if (
		test_strdup_case1() ||
		test_strdup_case2() ||
		test_strdup_case3() ||
		test_strdup_case4() ||
		test_strdup_case5() ||
		test_strdup_case6()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}
