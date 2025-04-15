/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 02:54:48 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 03:04:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// comparer avec la vrai fonction 
// Je dois tester strlen avec differnete chaien de caractere differente
// certain cas ne son pas similaire !!
int	test_ft_strlen(void)
{
	int i;

	i = 0;
	printf("--- strlen\t: ");
	
	char const *test_strings[] =
	{
		"",									// Chaîne vide
		"Hello",							// Chaîne normale
		"Hello, world!",					// Chaîne avec espaces et ponctuation
		"\t\n\r\f\v",						// Caractères d'échappement
		"1234567890",						// Chaîne de chiffres
		"abcdefghijklmnopqrstuvwxyz",		// Chaîne longue
		"Avec caractères spéciaux: éàçù",	// Caractères spéciaux
		NULL								// Terminateur du tableau
	};

	while (test_strings[i] != NULL)
	{
		if (strlen(test_strings[i]) != ft_strlen(test_strings[i]))
		{
			printf("Error avec \"%s\" | strlen = %ld | ft_strlen = %ld\n", test_strings[i], strlen(test_strings[i]), ft_strlen(test_strings[i]));
			return 1; // Retourne 1 en cas d'erreur
		}
		i++;
	}

	return (printf("\t✅\n"), 0);
}