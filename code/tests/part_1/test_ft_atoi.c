/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:28:38 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 00:30:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static int compare_atoi(const char *str)
{
	int std_ret = atoi(str);
	int ft_ret = ft_atoi(str);

	if (std_ret != ft_ret)
	{
		printf("❌ FAIL:\n");
		printf("str     : \"%s\"\n", str);
		printf("atoi    : %d\n", std_ret);
		printf("ft_atoi : %d\n", ft_ret);
		return (1);
	}
	return (0);
}

// TEST CASES

static int test_atoi_case1(void) { return compare_atoi("123"); }			// Positive number
static int test_atoi_case2(void) { return compare_atoi("-456"); }			// Negative number
static int test_atoi_case3(void) { return compare_atoi("+789"); }			// Positive number with '+' sign
static int test_atoi_case4(void) { return compare_atoi("0"); }				// Zero
static int test_atoi_case5(void) { return compare_atoi("   123"); }			// Leading spaces
static int test_atoi_case6(void) { return compare_atoi("\t-456"); }			// Leading tab
static int test_atoi_case7(void) { return compare_atoi("  \n +789"); }		// Leading spaces and newline
static int test_atoi_case8(void) { return compare_atoi("abc123"); }			// Non-numeric characters at the beginning
static int test_atoi_case9(void) { return compare_atoi("123abc"); }			// Non-numeric characters at the end
static int test_atoi_case10(void) { return compare_atoi("  -00042"); }		// Leading spaces and zeros
static int test_atoi_case11(void) { return compare_atoi("2147483647"); }	// INT_MAX
static int test_atoi_case12(void) { return compare_atoi("-2147483648"); }	// INT_MIN
static int test_atoi_case13(void) { return compare_atoi("2147483648"); }	// Overflow (should behave consistently)
static int test_atoi_case14(void) { return compare_atoi("-2147483649"); }	// Underflow (should behave consistently)
static int test_atoi_case15(void) { return compare_atoi(""); }				// Empty string
static int test_atoi_case16(void) { return compare_atoi(" ");}				// String with only spaces
static int test_atoi_case17(void) { return compare_atoi("++123"); }			// Multiple positive signs
static int test_atoi_case18(void) { return compare_atoi("--456"); }			// Multiple negative signs
static int test_atoi_case19(void) { return compare_atoi("+-789"); }			// Mixed signs
static int test_atoi_case20(void) { return compare_atoi("-+123"); }			// Mixed signs
static int test_atoi_case21(void) { return compare_atoi("\f123"); }			// Leading form feed
static int test_atoi_case22(void) { return compare_atoi("\r-456"); }		// Leading carriage return
static int test_atoi_case23(void) { return compare_atoi("\v+789"); }		// Leading vertical tab

int test_ft_atoi(void)
{
	printf("--- atoi\t: ");

	if (
		test_atoi_case1() ||
		test_atoi_case2() ||
		test_atoi_case3() ||
		test_atoi_case4() ||
		test_atoi_case5() ||
		test_atoi_case6() ||
		test_atoi_case7() ||
		test_atoi_case8() ||
		test_atoi_case9() ||
		test_atoi_case10() ||
		test_atoi_case11() ||
		test_atoi_case12() ||
		test_atoi_case13() ||
		test_atoi_case14() ||
		test_atoi_case15() ||
		test_atoi_case16() ||
		test_atoi_case17() ||
		test_atoi_case18() ||
		test_atoi_case19() ||
		test_atoi_case20() ||
		test_atoi_case21() ||
		test_atoi_case22() ||
		test_atoi_case23()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}