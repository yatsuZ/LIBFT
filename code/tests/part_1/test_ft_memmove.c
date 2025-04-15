/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:06:30 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 20:43:51 by yzaoui           ###   ########.fr       */
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
	memmove(dest1, src, 0);
	ft_memmove(dest2, src, 0);

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

	memmove(dest1, src, 0);
	ft_memmove(dest2, src, 0);

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
	
	memmove(dest1, src, 1);
	ft_memmove(dest2, src, 1);
	
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
	memmove(dest1, src, 13);
	ft_memmove(dest2, src, 13);

	if (memcmp(dest1, dest2, 13) != 0)
	{
		printf("Test 4 échoué : La copie d'une taille plus grande n'a pas été gérée correctement.\n");
		return (1);
	}
	return (0);
}

// Test avec des zones mémoire qui se chevauchent (comportement indéfini pour memmove)
static int test_5(void)
{
	char src1[] = "Hello, World!";
	char *dest1 = src1 + 7;

	char src2[] = "Hello, World!";
	char *dest2 = src2 + 7;

	// Copie avec la vraie memmove (comportement indéfini pour memmove avec chevauchement)
	// La vraie memmove peut échouer ici, donc ce n'est pas nécessairement un test que la vraie fonction passera
	memmove(dest1, src1, 6); // Copie "Hello" dans "World!"

	// Copie avec ft_memmove (peut être défini correctement)
	ft_memmove(dest2, src2, 6); // Copie "Hello" dans "World!"

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

// Test reverse : on copie vers l’arrière (overlap vers la droite)
static int	test_6(void)
{
	char s[] = {67, 68, 67, 68, 69, 0, 45};
	char expected[] = {67, 67, 68, 68, 69, 0, 45};     // s+1 = s, donc s[1] = s[0], s[2] = s[1]
	if (ft_memmove(s + 1, s, 2) != s + 1 || memcmp(s, expected, 7) != 0)
	{
		printf("❌ test 4 (overlap reverse)\n");
		return (1);
	}
	return (0);
}
int test_ft_memmove(void)
{
	printf("--- memmove\t: ");

	if (test_1() || test_2() || test_3() || test_4() || test_5() || test_6())
		return (1);

	printf("\t✅\n");
	return (0);
}
