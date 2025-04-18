/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_front_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:33:09 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 17:52:57 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static bool test_lstadd_front_case1(void)
{
	printf("--- lstadd_front (lst is NULL)\t: ");
	t_list *new_node = ft_lstnew(NULL);
	ft_lstadd_front(NULL, new_node);
	// Selon la description, le comportement est indéfini.
	// Nous allons vérifier qu'il n'y a pas de crash immédiat (ce qui n'est pas une garantie).
	free(new_node);
	printf("\t✅ (no immediate crash)\n");
	return false;
}

static bool test_lstadd_front_case2(void)
{
	printf("--- lstadd_front (new is NULL)\t: ");
	t_list *head = ft_lstnew(NULL);
	t_list *original_head = head;
	ft_lstadd_front(&head, NULL);
	if (head == original_head)
	{
		free(head);
		printf("\t✅ (list not modified)\n");
		return false;
	}
	else
	{
		free(head);
		printf("\t❌ (list was modified)\n");
		return true;
	}
}

static bool test_lstadd_front_case3(void)
{
	printf("--- lstadd_front (empty list)\t: ");
	t_list *head = NULL;
	int data = 42;
	t_list *new_node = ft_lstnew(&data);
	ft_lstadd_front(&head, new_node);
	if (head == new_node && head->content == &data && head->next == NULL)
	{
		free(head);
		printf("\t✅ (added to empty list)\n");
		return false;
	}
	else
	{
		if (head)
			free(head);
		free(new_node);
		printf("\t❌ (did not add correctly to empty list)\n");
		return true;
	}
}

static bool test_lstadd_front_case4(void)
{
	printf("--- lstadd_front (non-empty list)\t: ");
	t_list *head = ft_lstnew((void *)1);
	t_list *second = ft_lstnew((void *)2);
	head->next = second;
	int new_data = 3;
	t_list *new_node = ft_lstnew(&new_data);
	ft_lstadd_front(&head, new_node);
	if (head == new_node && head->content == &new_data && head->next->content == (void *)1)
	{
		free(head->next->next);
		free(head->next);
		free(head);
		printf("\t✅ (added to front of non-empty list)\n");
		return false;
	}
	else
	{
		// Clean up memory in case of failure
		if (head && head->next && head->next->next)
			free(head->next->next);
		if (head && head->next)
			free(head->next);
		if (head)
			free(head);
		if (new_node)
			free(new_node);
		printf("\t❌ (did not add correctly to front of non-empty list)\n");
		return true;
	}
}

static bool test_lstadd_front_case5(void)
{
	printf("--- lstadd_front (multiple adds)\t: ");
	t_list *head = NULL;
	int data1 = 1, data2 = 2, data3 = 3;
	t_list *node1 = ft_lstnew(&data1);
	t_list *node2 = ft_lstnew(&data2);
	t_list *node3 = ft_lstnew(&data3);

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);

	if (head == node3 && head->content == &data3 &&
		head->next == node2 && head->next->content == &data2 &&
		head->next->next == node1 && head->next->next->content == &data1 &&
		head->next->next->next == NULL)
	{
		free(head->next->next);
		free(head->next);
		free(head);
		printf("\t✅ (multiple adds to front)\n");
		return false;
	}
	else
	{
		// Clean up memory in case of failure
		if (head && head->next && head->next->next && head->next->next->next)
			free(head->next->next->next);
		if (head && head->next && head->next->next)
			free(head->next->next);
		if (head && head->next)
			free(head->next);
		if (head)
			free(head);
		printf("\t❌ (multiple adds failed)\n");
		return true;
	}
}

int test_ft_lstadd_front(void)
{
	int result = 0;

	result |= test_lstadd_front_case1();
	result |= test_lstadd_front_case2();
	result |= test_lstadd_front_case3();
	result |= test_lstadd_front_case4();
	result |= test_lstadd_front_case5();

	return result;
}
