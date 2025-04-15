/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:57:10 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 19:13:49 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// Test avec une zone mémoire NULL
static int test_1(void)
{
	char *src = NULL;
	char dest1[10];
	char dest2[10];

	bzero(dest1, 10);
	bzero(dest2, 10);
	memcpy(dest1, src, 0);
	ft_memcpy(dest2, src, 0);

	// Vérification : les deux doivent être identiques, puisque aucune donnée n'a été copiée
	if (memcmp(dest1, dest2, 10) != 0)
	{
		printf("Test 1 échoué : La copie avec NULL n'a pas été gérée correctement.\n");
		return (1);
	}
	return (0);
}

// Test avec une zone mémoire de taille 0
static int test_2(void)
{
	char src[] = "Hello";
	char dest1[10];
	char dest2[10];

	bzero(dest1, 10);
	bzero(dest2, 10);

	memcpy(dest1, src, 0);
	ft_memcpy(dest2, src, 0);

	if (memcmp(dest1, dest2, 10) != 0)
	{
		printf("Test 2 échoué : La copie de taille 0 n'a pas été gérée correctement.\n");
		return (1);
	}
	return (0);
}

// Test avec une petite taille (1 byte)
static int test_3(void)
{
	char src[] = "Hello";
	char dest1[10];
	char dest2[10];

	bzero(dest1, 10);
	bzero(dest2, 10);
	
	memcpy(dest1, src, 1);
	ft_memcpy(dest2, src, 1);
	
	if (memcmp(dest1, dest2, 10) != 0)
	{
		printf("Test 3 échoué : La copie d'un seul octet n'a pas été gérée correctement.\n");
		return (1);
	}
	return (0);
}

// Test avec une taille plus grande
static int test_4(void)
{
	char src[] = "Hello, World!";
	char dest1[20];
	char dest2[20];

	bzero(dest1, 20);
	bzero(dest2, 20);
	memcpy(dest1, src, 13);
	ft_memcpy(dest2, src, 13);

	if (memcmp(dest1, dest2, 13) != 0)
	{
		printf("Test 4 échoué : La copie d'une taille plus grande n'a pas été gérée correctement.\n");
		return (1);
	}
	return (0);
}

// Test avec des zones mémoire qui se chevauchent (comportement indéfini pour memcpy)
static int test_5(void)
{
	char src1[] = "Hello, World!";
	char *dest1 = src1 + 7;

	char src2[] = "Hello, World!";
	char *dest2 = src2 + 7;

	// Copie avec la vraie memcpy (comportement indéfini pour memcpy avec chevauchement)
	// La vraie memcpy peut échouer ici, donc ce n'est pas nécessairement un test que la vraie fonction passera
	memcpy(dest1, src1, 6); // Copie "Hello" dans "World!"

	// Copie avec ft_memcpy (peut être défini correctement)
	ft_memcpy(dest2, src2, 6); // Copie "Hello" dans "World!"

	// Vérification : le résultat devrait être que le début de la chaîne "World!" devient "Hello"
	if (memcmp(src1, src2, 13) != 0)
	{
		printf("dest1 = \"%s\" | dest2 = \"%s\" | ", src1, src2);
		printf("Test 5 échoué : La copie avec chevauchement n'a pas été gérée correctement.\n");
		return (1);
	}
	// printf("dest1 = \"%s\" | dest2 = \"%s\" | ", src1, src2);
	return (0);
}


int test_ft_memcpy(void)
{
	printf("--- memcpy\t: ");

	if (test_1() || test_2() || test_3() || test_4() || test_5())
		return (1);

	printf("\t✅\n");
	return (0);
}
