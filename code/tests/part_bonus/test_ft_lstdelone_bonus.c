/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:44:36 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/18 16:52:31 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// Fonction de suppression de contenu simple
static void del_content(void *content)
{
	free(content);
}

static bool test_lstdelone_case1(void)
{
	printf("--- lstdelone (node is NULL)\t: ");
	ft_lstdelone(NULL, del_content);
	printf("\t✅ (no crash)\n");
	return (false);
}

static bool test_lstdelone_case2(void)
{
	printf("--- lstdelone (del is NULL)\t: ");
	int *data = malloc(sizeof(int));
	if (!data)
		return (true);
	*data = 42;
	t_list *node = ft_lstnew(data);
	ft_lstdelone(node, NULL);
	// Vérifier si la mémoire du nœud est libérée, mais pas le contenu
	// (ce qui est le comportement attendu si del est NULL)
	// On ne peut pas vérifier directement si le free du nœud a réussi
	// sans segfault, mais le test ne doit pas crasher.
	printf("\t✅ (no crash)\n");
	free(data);
	if (node)
	{
		node->content = NULL;
		free(node);
	}
	return (false);
}

static bool test_lstdelone_case3(void)
{
	printf("--- lstdelone (valid node, valid del)\t: ");
	int *data = malloc(sizeof(int));
	if (!data)
		return (true);
	*data = 123;
	t_list *node = ft_lstnew(data);
	ft_lstdelone(node, del_content);
	// Après l'appel, 'node' lui-même est libéré, et la mémoire de son contenu aussi.
	// Tenter d'accéder à 'node' après ft_lstdelone provoque un comportement indéfini.
	// Le succès est que le programme ne crashe pas ici.
	printf("\t✅ (no crash)\n");
	return (false);
}

int test_ft_lstdelone(void)
{
	int result = 0;

	result |= test_lstdelone_case1();
	result |= test_lstdelone_case2();
	result |= test_lstdelone_case3();

	return (result);
}
