/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:15:28 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 15:12:24 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static size_t	ft_nomber_of_word(const char *s, char c)
{
	size_t	nbw;
	size_t	i;
	int		boolean;

	boolean = 1;
	i = 0;
	nbw = 0;
	while (s[i])
	{
		if (s[i] == c)
			boolean = 1;
		else
		{
			if (boolean)
				nbw++;
			boolean = 0;
		}
		i++;
	}
	return (nbw);
}

static char	**ft_cutsplit(size_t i, size_t nbw, const char *s, char c)
{
	size_t	j;
	char	**tab;

	tab = ft_calloc(nbw, sizeof(char *));
	j = 1;
	nbw = 0;
	while (s[i] && tab)
	{
		if (s[i] == c)
			j = 1;
		else
		{
			if (j)
			{
				j = i;
				while (s[i] && s[i] != c)
					i++;
				tab[nbw] = ft_substr(s, j, i-- - j);
				nbw++;
			}
			j = 0;
		}
		i++;
	}
	return (tab);
}

static int	ft_secure(size_t j, const char *s, char c, size_t i)
{
	char	*sec;
	int	t =0;

	while (s[i])
	{
		if (s[i] == c)
			j = 1;
		else
		{
			if (j)
			{
				j = i;
				t++;
				while (s[i] && s[i] != 0)
					i++;
				sec = ft_substr(s, j, i-- - j);
				if (!sec)
					return (0);
				free(sec);
			}
			j = 0;
		}
		i++;
	}
	return (1);
}

static char	**ft_split_old(const char *s, char c)
{
	size_t	nbw;
	char	**tab;

	if (!s)
		return (NULL);
	nbw = ft_nomber_of_word(s, c);
	if (ft_secure(1, s, c, 0) == 0)
		return (NULL);
	tab = ft_cutsplit(0, 1 + nbw, s, c);
	if (!tab)
		return (NULL);
	tab[nbw] = NULL;
	return (tab);
}

static int compare_split(const char *s, char c)
{
	char **expected = ft_split_old(s, c);
	char **actual = ft_split(s, c);
	int error = 0;
	int i = 0;

	if (!s)
	{
		if (actual != NULL)
		{
			printf("❌ FAIL: ft_split returned non-NULL for NULL s\n");
			error = 1;
			// Free actual if needed
			size_t j = 0;
			while (actual[j])
			{
				free(expected[j++]);
				free(actual[j++]);
			}
			free(expected);
			free(actual);
		}
		return error;
	}

	if (!expected && !actual)
		return (0);
	// Compare expected and actual
	i = 0;
	while (expected[i] ||  actual[i])
	{
		if ((expected[i] == NULL && actual[i] != NULL) || (expected[i] != NULL && actual[i] == NULL) || (expected[i] && actual[i] && strcmp(expected[i], actual[i]) != 0))
		{
			printf("❌ FAIL: ft_split returned incorrect result for s=\"%s\", c='%c'\n", s, c);
			printf("   Expected[%d]: \"%s\", Actual[%d]: \"%s\"\n", i, expected[i] ? expected[i] : "NULL", i, actual[i] ? actual[i] : "NULL");
			error = 1;
			break;
		}
		i++;
	}

	// Free allocated memory
	i = 0;
	while (expected[i])
		free(expected[i++]);
	free(expected);

	i = 0;
	while (actual && actual[i])
		free(actual[i++]);
	free(actual);

	return error;
}

// TEST CASES

static int test_split_case1(void) { return compare_split("Hello World", ' '); }
static int test_split_case2(void) { return compare_split("Hello,,World", ','); }
static int test_split_case3(void) { return compare_split("Hello", ' '); }
static int test_split_case4(void) { return compare_split("", ' '); }
static int test_split_case5(void) { return compare_split("   split   me   ", ' '); }
static int test_split_case6(void) { return compare_split("split", '\0'); }
static int test_split_case7(void) { return compare_split(",,Hello,World,", ','); }
static int test_split_case8(void) { return compare_split("Hello World Test", 0); }
static int test_split_case9(void) { return compare_split(NULL, ' '); }
static int test_split_case10(void) { return compare_split("aaaaa", 'a'); }
static int test_split_case11(void) { return compare_split("a", 'a'); }
static int test_split_case12(void) { return compare_split("a b c", ' '); }

int test_ft_split(void)
{
	printf("--- split\t: ");

	if (
		test_split_case1() ||
		test_split_case2() ||
		test_split_case3() ||
		test_split_case4() ||
		test_split_case5() ||
		test_split_case6() ||
		test_split_case7() ||
		test_split_case8() ||
		test_split_case9() ||
		test_split_case10() ||
		test_split_case11() ||
		test_split_case12()
	)
		return (1);

	printf("\t✅\n");
	return (0);
}
