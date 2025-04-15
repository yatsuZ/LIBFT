/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:16:35 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 22:00:42 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static int compare_strlcpy(const char *src, size_t size)
{
	size_t	len = BUFF_SIZE - 1;
	char std_dst[BUFF_SIZE];
	char ft_dst[BUFF_SIZE];

	memset(std_dst, 'X', len);
	memset(ft_dst, 'X', len);

	size_t std_ret = strlcpy(std_dst, src, size);
	size_t ft_ret = ft_strlcpy(ft_dst, src, size);

	if (std_ret != ft_ret || memcmp(std_dst, ft_dst, len) != 0)
	{
		printf("❌ FAIL:\n");
		printf("src       : \"%s\"\n", src ? src : "NULL");
		printf("size      : %zu\n", size);
		printf("std_ret   : %zu, ft_ret   : %zu\n", std_ret, ft_ret);
		printf("std_dst   : \"%s\"\n", std_dst);
		printf("ft_dst    : \"%s\"\n", ft_dst);
		return (1);
	}
	return (0);
}

static int	test_strlcpy_case1(void) { return compare_strlcpy("Hello", 0); }
static int	test_strlcpy_case2(void) { return compare_strlcpy("Hello", 3); }
static int	test_strlcpy_case3(void) { return compare_strlcpy("Hello", 6); }
static int	test_strlcpy_case4(void) { return compare_strlcpy("Hello", 100); }
static int	test_strlcpy_case5(void) { return compare_strlcpy("", 0); }
static int	test_strlcpy_case6(void) { return compare_strlcpy("", 5); }
static int	test_strlcpy_case7(void) { return compare_strlcpy("LongStringWithMoreThanTenCharacters", 10); }
static int	test_strlcpy_case8(void) { return compare_strlcpy("Short", 1); }
static int	test_strlcpy_case9(void) { return compare_strlcpy("A", 2); }

static int test_strlcpy_null_dst(void)
{
	const char *src = "CrashTest";
	char *dst = NULL;
	ft_strlcpy(dst, src, 5);
	return (0);
}

static int test_strlcpy_null_src(void)
{
	// Normalement, src ne doit jamais être NULL → comportement indéfini
	// Ce test est ici à titre informatif
	char dst[20];
	const char *src = NULL;

	ft_strlcpy(dst, src, 10);

	return (0);
}

int	test_ft_strlcpy(void)
{
	printf("--- strlcpy\t: ");

	if (
		test_strlcpy_case1() ||
		test_strlcpy_case2() ||
		test_strlcpy_case3() ||
		test_strlcpy_case4() ||
		test_strlcpy_case5() ||
		test_strlcpy_case6() ||
		test_strlcpy_case7() ||
		test_strlcpy_case8() ||
		test_strlcpy_case9() ||
		test_strlcpy_null_dst() ||
		test_strlcpy_null_src()) // Attention à l’exécution
		return (1);

	printf("\t✅\n");
	return (0);
}
