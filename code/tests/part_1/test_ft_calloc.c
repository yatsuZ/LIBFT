/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:48:42 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 01:16:59 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static int compare_calloc(size_t count, size_t size)
{
	void *std_ret = calloc(count, size);
	void *ft_ret = ft_calloc(count, size);
	int error = 0;

	if (std_ret == NULL && ft_ret != NULL)
	{
		printf("❌ FAIL: calloc returned NULL, ft_calloc did not (count=%zu, size=%zu, errno=%d)\n", count, size, errno);
		error = 1;
	}
	else if (std_ret != NULL && ft_ret == NULL)
	{
		printf("❌ FAIL: ft_calloc returned NULL, calloc did not (count=%zu, size=%zu, errno=%d)\n", count, size, errno);
		error = 1;
	}
	else if (std_ret != NULL && ft_ret != NULL)
	{
		// Check if the allocated memory is zeroed
		for (size_t i = 0; i < count * size; i++)
		{
			if (((unsigned char *)std_ret)[i] != 0)
			{
				printf("❌ FAIL: calloc memory not zeroed at index %zu (count=%zu, size=%zu)\n", i, count, size);
				error = 1;
				break;
			}
			if (((unsigned char *)ft_ret)[i] != 0)
			{
				printf("❌ FAIL: ft_calloc memory not zeroed at index %zu (count=%zu, size=%zu)\n", i, count, size);
				error = 1;
				break;
			}
		}
		if (error == 0 && memcmp(std_ret, ft_ret, count * size) != 0)
		{
			printf("❌ FAIL: Memory allocated by calloc and ft_calloc differs (count=%zu, size=%zu)\n", count, size);
			error = 1;
		}
	}
	if (std_ret)
		free(std_ret);
	if (ft_ret)
		free(ft_ret);
	return error;
}

// TEST CASES

static int test_calloc_case1(void) { return compare_calloc(5, sizeof(int)); }		// Allocate space for 5 integers
static int test_calloc_case2(void) { return compare_calloc(10, 1); }				// Allocate 10 bytes
static int test_calloc_case3(void) { return compare_calloc(1, 100); }				// Allocate 100 bytes
static int test_calloc_case4(void) { return compare_calloc(0, 10); }				// Allocate 0 elements
static int test_calloc_case5(void) { return compare_calloc(10, 0); }				// Allocate elements of size 0
// static int test_calloc_case6(void) { return compare_calloc(INT_MAX, 1); }			// Large count
// static int test_calloc_case7(void) { return compare_calloc(1, INT_MAX); }			// Large size
// static int test_calloc_case8(void) { return compare_calloc(INT_MAX / 2, 2); }		// Large but within potential limit
// static int test_calloc_case9(void) { return compare_calloc(2, INT_MAX / 2); }		// Large but within potential limit
static int test_calloc_case10(void) { return compare_calloc(0, 0); }				// Allocate 0 elements of size 0

int test_ft_calloc(void)
{
	printf("--- calloc\t: ");

	if (
		test_calloc_case1() ||
		test_calloc_case2() ||
		test_calloc_case3() ||
		test_calloc_case4() ||
		test_calloc_case5() ||
		// test_calloc_case6() ||
		// test_calloc_case7() ||
		// test_calloc_case8() ||
		// test_calloc_case9() ||
		test_calloc_case10()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}
