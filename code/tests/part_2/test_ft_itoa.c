/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:53:12 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 15:53:23 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static bool compare_itoa(int n)
{
	char *std_ret_buf = NULL;
	char *ft_ret = ft_itoa(n);
	bool error = false;

	// Simulate standard itoa (not standard C, so we'll use sprintf)
	int len = snprintf(NULL, 0, "%d", n);
	std_ret_buf = malloc(len + 1);
	if (std_ret_buf == NULL)
	{
		perror("Failed to allocate memory for standard itoa result");
		free(ft_ret);
		return true;
	}
	sprintf(std_ret_buf, "%d", n);

	if (ft_ret == NULL)
	{
		printf("❌ FAIL: ft_itoa returned NULL for n=%d\n", n);
		error = true;
	}
	else if (strcmp(std_ret_buf, ft_ret) != 0)
	{
		printf("❌ FAIL: ft_itoa returned incorrect string for n=%d, expected=\"%s\", actual=\"%s\"\n", n, std_ret_buf, ft_ret);
		error = true;
	}

	free(std_ret_buf);
	free(ft_ret);
	return error;
}

// TEST CASES

static int test_itoa_case1(void) { return compare_itoa(0); }
static int test_itoa_case2(void) { return compare_itoa(123); }
static int test_itoa_case3(void) { return compare_itoa(-456); }
static int test_itoa_case4(void) { return compare_itoa(INT_MAX); }
static int test_itoa_case5(void) { return compare_itoa(INT_MIN); }
static int test_itoa_case6(void) { return compare_itoa(9); }
static int test_itoa_case7(void) { return compare_itoa(-9); }
static int test_itoa_case8(void) { return compare_itoa(10); }
static int test_itoa_case9(void) { return compare_itoa(-10); }
static int test_itoa_case10(void) { return compare_itoa(99); }
static int test_itoa_case11(void) { return compare_itoa(-99); }
static int test_itoa_case12(void) { return compare_itoa(100); }
static int test_itoa_case13(void) { return compare_itoa(-100); }
static int test_itoa_case14(void) { return compare_itoa(99999); }
static int test_itoa_case15(void) { return compare_itoa(-99999); }

int test_ft_itoa(void)
{
	printf("--- itoa\t: ");

	if (
		test_itoa_case1() ||
		test_itoa_case2() ||
		test_itoa_case3() ||
		test_itoa_case4() ||
		test_itoa_case5() ||
		test_itoa_case6() ||
		test_itoa_case7() ||
		test_itoa_case8() ||
		test_itoa_case9() ||
		test_itoa_case10() ||
		test_itoa_case11() ||
		test_itoa_case12() ||
		test_itoa_case13() ||
		test_itoa_case14() ||
		test_itoa_case15()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}