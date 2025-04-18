/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstiter_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:54:38 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/18 01:54:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// Fonction de test simple pour modifier le contenu (ajouter 1)
static void add_one(void *content)
{
	if (content)
		(*(int *)content)++;
}

// Fonction de test pour vérifier le contenu
static bool check_content(t_list *lst, int expected[])
{
	int i = 0;
	while (lst)
	{
		if (!lst->content || *(int *)lst->content != expected[i])
			return (false);
		lst = lst->next;
		i++;
	}
	return (true);
}

static bool test_lstiter_case1(void)
{
	printf("--- lstiter (lst is NULL)\t: ");
	ft_lstiter(NULL, add_one);
	printf("\t✅ (no crash)\n");
	return (false);
}

static bool test_lstiter_case2(void)
{
	printf("--- lstiter (f is NULL)\t: ");
	t_list *head = ft_lstnew(malloc(sizeof(int)));
	if (head && head->content)
		*(int *)head->content = 10;
	ft_lstiter(head, NULL);
	if (head && *(int *)head->content == 10)
	{
		free(head->content);
		free(head);
		printf("\t✅ (no modification)\n");
		return (false);
	}
	else
	{
		if (head)
		{
			free(head->content);
			free(head);
		}
		printf("\t❌ (content was modified)\n");
		return (true);
	}
}

static bool test_lstiter_case3(void)
{
	printf("--- lstiter (empty list)\t: ");
	t_list *head = NULL;
	ft_lstiter(head, add_one);
	printf("\t✅ (no action)\n");
	return (false);
}

static bool test_lstiter_case4(void)
{
	printf("--- lstiter (single element)\t: ");
	t_list *head = ft_lstnew(malloc(sizeof(int)));
	if (head && head->content)
		*(int *)head->content = 5;
	ft_lstiter(head, add_one);
	bool result = (head && *(int *)head->content == 6);
	free(head->content);
	free(head);
	if (result)
		printf("\t✅ (content modified)\n");
	else
		printf("\t❌ (content not modified)\n");
	return (!result);
}

static bool test_lstiter_case5(void)
{
	printf("--- lstiter (multiple elements)\t: ");
	t_list *head = ft_lstnew(malloc(sizeof(int)));
	t_list *second = ft_lstnew(malloc(sizeof(int)));
	t_list *third = ft_lstnew(malloc(sizeof(int)));
	if (!head || !head->content || !second || !second->content || !third || !third->content)
	{
		if (head) { if (head->content) free(head->content); free(head); }
		if (second) { if (second->content) free(second->content); free(second); }
		if (third) { if (third->content) free(third->content); free(third); }
		return (true);
	}
	*(int *)head->content = 1;
	*(int *)second->content = 2;
	*(int *)third->content = 3;
	head->next = second;
	second->next = third;
	ft_lstiter(head, add_one);
	int expected[] = {2, 3, 4};
	bool result = check_content(head, expected);
	t_list *current = head;
	while (current)
	{
		t_list *next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	if (result)
		printf("\t✅ (contents modified)\n");
	else
		printf("\t❌ (contents not modified correctly)\n");
	return (!result);
}

int test_ft_lstiter(void)
{
	int result = 0;

	result |= test_lstiter_case1();
	result |= test_lstiter_case2();
	result |= test_lstiter_case3();
	result |= test_lstiter_case4();
	result |= test_lstiter_case5();

	return (result);
}