/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:59:51 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 22:04:46 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static int compare_strlcat(const char *src, const char *dst_init, size_t size)
{
	char std_dst[BUFF_SIZE];
	char ft_dst[BUFF_SIZE];

	memset(std_dst, 'X', BUFF_SIZE);
	memset(ft_dst, 'X', BUFF_SIZE);

	strcpy(std_dst, dst_init);
	strcpy(ft_dst, dst_init);

	size_t std_ret = strlcat(std_dst, src, size);
	size_t ft_ret = ft_strlcat(ft_dst, src, size);

	if (std_ret != ft_ret || memcmp(std_dst, ft_dst, BUFF_SIZE) != 0)
	{
		printf("❌ FAIL:\n");
		printf("src       : \"%s\"\n", src);
		printf("dst_init  : \"%s\"\n", dst_init);
		printf("size      : %zu\n", size);
		printf("std_ret   : %zu, ft_ret   : %zu\n", std_ret, ft_ret);
		printf("std_dst   : \"%s\"\n", std_dst);
		printf("ft_dst    : \"%s\"\n", ft_dst);
		return (1);
	}
	return (0);
}

// TEST CASES
static int test_strlcat_case1(void) { return compare_strlcat("World", "Hello", 0); }
static int test_strlcat_case1_5(void) { return compare_strlcat("World", "Hello", 1); }
static int test_strlcat_case2(void) { return compare_strlcat("World", "", 10); }
static int test_strlcat_case3(void) { return compare_strlcat("", "Hello", 10); }
static int test_strlcat_case4(void) { return compare_strlcat("12345", "ABCDE", 11); }
static int test_strlcat_case5(void) { return compare_strlcat("12345", "ABCDE", 8); }
static int test_strlcat_case6(void) { return compare_strlcat("1234567890", "ABC", 5); }
static int test_strlcat_case7(void) { return compare_strlcat("Data", "DataAlreadyLong", 5); }
static int test_strlcat_case8(void) { return compare_strlcat("test", "", 0); }
static int test_strlcat_case9(void) { return compare_strlcat("Extra", "Buff", 9); }

static int test_strlcat_null_src(void)
{
	char dst[20] = "Test";
	const char *src = NULL;

	ft_strlcat(dst, src, 10);

	(void)dst;
	(void)src;
	return (0);
}

static int test_strlcat_null_dst(void)
{
	const char *src = "Crash";
	char *dst = NULL;

	ft_strlcat(dst, src, 5);

	(void)src;
	return (0);
}

int test_ft_strlcat(void)
{
	printf("--- strlcat\t: ");

	if (
		test_strlcat_case1() ||
		test_strlcat_case1_5() ||
		test_strlcat_case2() ||
		test_strlcat_case3() ||
		test_strlcat_case4() ||
		test_strlcat_case5() ||
		test_strlcat_case6() ||
		test_strlcat_case7() ||
		test_strlcat_case8() ||
		test_strlcat_case9() ||
		test_strlcat_null_src() ||
		test_strlcat_null_dst()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}
