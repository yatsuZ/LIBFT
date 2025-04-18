/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstclear_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:47:36 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/18 01:49:57 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// Fonction de suppression de contenu simple
static void del_content(void *content)
{
	free(content);
}

static bool test_lstclear_case1(void)
{
	printf("--- lstclear (lst is NULL)\t: ");
	ft_lstclear(NULL, del_content);
	printf("\t✅ (no crash)\n");
	return (false);
}

static bool test_lstclear_case2(void)
{
	printf("--- lstclear (del is NULL)\t: ");
	t_list *head = ft_lstnew(malloc(sizeof(int)));
	if (!head || !head->content)
		return (true);
	*(int *)head->content = 50;
	ft_lstadd_back(&head, ft_lstnew(malloc(sizeof(int))));
	if (!head->next || !head->next->content)
	{
		free(head->content);
		free(head);
		return (true);
	}
	*(int *)head->next->content = 100;
	ft_lstclear(&head, NULL);
	// Après l'appel, toute la liste doit être libérée, mais pas le contenu
	// (car del est NULL). On ne peut pas vérifier directement sans crash.
	printf("\t✅ (no crash)\n");
	ft_lstclear(&head, del_content);
	return (false);
}

static bool test_lstclear_case3(void)
{
	printf("--- lstclear (empty list)\t: ");
	t_list *head = NULL;
	ft_lstclear(&head, del_content);
	printf("\t✅ (no action)\n");
	return (false);
}

static bool test_lstclear_case4(void)
{
	printf("--- lstclear (single element)\t: ");
	t_list *head = ft_lstnew(malloc(sizeof(int)));
	if (!head || !head->content)
		return (true);
	*(int *)head->content = 20;
	ft_lstclear(&head, del_content);
	// Après l'appel, la liste et son contenu doivent être libérés.
	printf("\t✅ (no crash)\n");
	return (false);
}

static bool test_lstclear_case5(void)
{
	printf("--- lstclear (multiple elements)\t: ");
	t_list *head = ft_lstnew(malloc(sizeof(int)));
	t_list *second = ft_lstnew(malloc(sizeof(int)));
	t_list *third = ft_lstnew(malloc(sizeof(int)));
	if (!head || !head->content || !second || !second->content || !third || !third->content)
	{
		// Nettoyage en cas d'échec d'allocation
		if (head && head->content) free(head->content);
		if (second && second->content) free(second->content);
		if (third && third->content) free(third->content);
		if (head && head->next) free(head->next);
		if (second && second->next) free(second->next);
		if (head) free(head);
		if (second) free(second);
		if (third) free(third);
		return (true);
	}
	*(int *)head->content = 1;
	*(int *)second->content = 2;
	*(int *)third->content = 3;
	head->next = second;
	second->next = third;
	ft_lstclear(&head, del_content);
	// Après l'appel, toute la liste et son contenu doivent être libérés.
	printf("\t✅ (no crash)\n");
	return (false);
}

int test_ft_lstclear(void)
{
	int result = 0;

	result |= test_lstclear_case1();
	result |= test_lstclear_case2();
	result |= test_lstclear_case3();
	result |= test_lstclear_case4();
	result |= test_lstclear_case5();

	return (result);
}
