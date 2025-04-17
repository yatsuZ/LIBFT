/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:57:47 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 15:58:25 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// Fonction de test pour appliquer à chaque caractère (exemple)
static char map_function_example(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32); // Convertir en majuscule
	else if (c >= 'A' && c <= 'Z')
		return (c + 32); // Convertir en minuscule
	else
		return (c + i);   // Ajouter l'index
}

static bool compare_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char *expected = NULL;
	char *actual = ft_strmapi(s, f);
	bool error = false;
	size_t len = s ? strlen(s) : 0;

	if (s)
	{
		expected = malloc(len + 1);
		if (!expected)
		{
			perror("Failed to allocate memory for expected strmapi result");
			free(actual);
			return true;
		}
		for (unsigned int i = 0; i < len; i++)
			expected[i] = f(i, s[i]);
		expected[len] = '\0';
	}
	else
	{
		if (actual != NULL)
		{
			printf("❌ FAIL: ft_strmapi returned non-NULL for NULL s\n");
			error = true;
			free(actual);
		}
		return error;
	}

	if (actual == NULL)
	{
		printf("❌ FAIL: ft_strmapi returned NULL for s=\"%s\"\n", s);
		error = true;
	}
	else if (strcmp(expected, actual) != 0)
	{
		printf("❌ FAIL: ft_strmapi returned incorrect string for s=\"%s\", expected=\"%s\", actual=\"%s\"\n", s, expected, actual);
		error = true;
	}

	free(expected);
	free(actual);
	return error;
}

// TEST CASES

static int test_strmapi_case1(void) { return compare_strmapi("hello", map_function_example); }
static int test_strmapi_case2(void) { return compare_strmapi("WORLD", map_function_example); }
static int test_strmapi_case3(void) { return compare_strmapi("MixedCase123!", map_function_example); }
static int test_strmapi_case4(void) { return compare_strmapi("", map_function_example); }
static int test_strmapi_case5(void) { return compare_strmapi("a", map_function_example); }
static int test_strmapi_case6(void) { return compare_strmapi("abcdefg", map_function_example); }
static int test_strmapi_case7(void) { return compare_strmapi(NULL, map_function_example); }

// Autre fonction de test pour strmapi
static char map_add_index(unsigned int i, char c)
{
	return (c + i);
}

static int test_strmapi_case8(void) { return compare_strmapi("abc", map_add_index); }

// Autre fonction de test qui ne modifie pas la chaîne
static char map_identity(unsigned int i, char c)
{
	(void)i;
	return (c);
}

static int test_strmapi_case9(void) { return compare_strmapi("test", map_identity); }

int test_ft_strmapi(void)
{
	printf("--- strmapi\t: ");

	if (
		test_strmapi_case1() ||
		test_strmapi_case2() ||
		test_strmapi_case3() ||
		test_strmapi_case4() ||
		test_strmapi_case5() ||
		test_strmapi_case6() ||
		test_strmapi_case7() ||
		test_strmapi_case8() ||
		test_strmapi_case9()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}
