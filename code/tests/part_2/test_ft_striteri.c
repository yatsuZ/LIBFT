/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:24:29 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 16:26:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// Fonction de test pour appliquer à chaque caractère (exemple)
static void modify_string_example(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32; // Convertir en majuscule
	else if (*c >= 'A' && *c <= 'Z')
		*c += 32; // Convertir en minuscule
	else
		*c += i;   // Ajouter l'index
}

static bool compare_striteri(char *s, void (*f)(unsigned int, char *))
{
	char *s_copy_ft;
	char *s_copy_expected;
	bool error = false;
	size_t len = s ? strlen(s) : 0;

	if (s)
	{
		s_copy_ft = strdup(s);
		s_copy_expected = strdup(s);
		if (!s_copy_ft || !s_copy_expected)
		{
			perror("Failed to allocate memory for string copies");
			free(s_copy_ft);
			free(s_copy_expected);
			return true;
		}

		// Apply ft_striteri
		ft_striteri(s_copy_ft, f);

		// Apply the expected modification
		for (unsigned int i = 0; i < len; i++)
			f(i, &s_copy_expected[i]);

		if (strcmp(s_copy_expected, s_copy_ft) != 0)
		{
			printf("❌ FAIL: ft_striteri modified string incorrectly for s=\"%s\"\n", s);
			printf("   Expected: \"%s\", Actual: \"%s\"\n", s_copy_expected, s_copy_ft);
			error = true;
		}

		free(s_copy_ft);
		free(s_copy_expected);
	}
	else
	{
		// ft_striteri should not do anything if s is NULL
		ft_striteri(NULL, f);
	}

	return error;
}

// Autre fonction de test pour striteri
static void modify_add_index(unsigned int i, char *c)
{
	*c += i;
}

// Autre fonction de test qui ne modifie pas la chaîne
static void modify_identity(unsigned int i, char *c)
{
	(void)i;
	(void)c;
}

int test_ft_striteri(void)
{
	printf("--- striteri\t: ");

	if (
		compare_striteri("hello", modify_string_example) ||
		compare_striteri("WORLD", modify_string_example) ||
		compare_striteri("MixedCase123!", modify_string_example) ||
		compare_striteri("", modify_string_example) ||
		compare_striteri("a", modify_string_example) ||
		compare_striteri("abcdefg", modify_string_example) ||
		compare_striteri(NULL, modify_string_example) ||
		compare_striteri("abc", modify_add_index) ||
		compare_striteri("test", modify_identity)
	)
		return (1);

	printf("\t✅\n");
	return (0);
}
