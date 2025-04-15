/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:41:13 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 16:44:04 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// Fonction de comparaison basique
static int	compar_ft_et_bzero(const void *s1, const void *s2, size_t n)
{
	return memcmp(s1, s2, n);
}

static int	test_1(void)
{
	const char *original_strings[] =
	{
		"",									// Chaîne vide
		"Hello",							// Chaîne normale
		"Hello, world!",					// Chaîne avec ponctuation
		"\t\n\r\f\v",						// Caractères d'échappement
		"1234567890",						// Chiffres
		"abcdefghijklmnopqrstuvwxyz",		// Alphabet
		"Avec caractères spéciaux: éàçù",	// UTF-8
		NULL								// Fin du tableau
	};
	int i = 0;
	while (original_strings[i] != NULL)
	{
		size_t len = strlen(original_strings[i]);
		char *str1 = strdup(original_strings[i]);
		char *str2 = strdup(original_strings[i]);

		if (!str1 || !str2)
		{
			perror("strdup");
			return 1;
		}

		size_t n = len > 0 ? len - 1 : 0; // on garde le \0 final

		// Appels à bzero et ft_bzero
		bzero(str1, n);
		ft_bzero(str2, n);

		// printf("Test %d : ", i);
		if (compar_ft_et_bzero(str1, str2, len) != 0)
		{
			printf("❌ Error |");
			printf("Original : %s\t", original_strings[i]);
			printf("bzero   : %s\t", str1);
			printf("ft_bzero: %s\n", str2);
			return (free(str1), free(str2), 1);
		}

		free(str1);
		free(str2);
		i++;
	}
	return (0);
}

static int	test_2(void)
{
	char * s = "0123456789 10111213141516171819 2021";
	size_t len = strlen(s);
	char *str1 = strdup(s);
	char *str2 = strdup(s);

	if (!str1 || !str2)
	{
		perror("strdup");
		return 1;
	}

	// Appels à bzero et ft_bzero
	bzero(str1, 20);
	ft_bzero(str2, 20);

	// printf("Test %d : ", i);
	if (compar_ft_et_bzero(str1, str2, len) != 0)
	{
		printf("❌ Error |");
		printf("Original : %s\t", s);
		printf("bzero   : %s\t", str1);
		printf("ft_bzero: %s\n", str2);
		return (free(str1), free(str2), 1);
	}
	free(str1);
	free(str2);
	return (0);
}

int	test_ft_bzero(void)
{
	printf("--- bzero\t: ");

	if (test_1() || test_2())
		return (1);
	printf("\t✅\n");
	return 0;
}
