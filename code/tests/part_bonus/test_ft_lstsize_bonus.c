/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstsize_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:58:18 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 17:58:32 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static bool test_lstsize_case1(void)
{
	printf("--- lstsize (empty list)\t: ");
	t_list *head = NULL;
	int size = ft_lstsize(head);
	if (size == 0)
	{
		printf("\t✅ (size is 0)\n");
		return false;
	}
	else
	{
		printf("\t❌ (size is %d, expected 0)\n", size);
		return true;
	}
}

static bool test_lstsize_case2(void)
{
	printf("--- lstsize (single element)\t: ");
	t_list *head = ft_lstnew(NULL);
	int size = ft_lstsize(head);
	free(head);
	if (size == 1)
	{
		printf("\t✅ (size is 1)\n");
		return false;
	}
	else
	{
		printf("\t❌ (size is %d, expected 1)\n", size);
		return true;
	}
}

static bool test_lstsize_case3(void)
{
	printf("--- lstsize (multiple elements)\t: ");
	t_list *head = ft_lstnew(NULL);
	t_list *second = ft_lstnew(NULL);
	t_list *third = ft_lstnew(NULL);
	head->next = second;
	second->next = third;
	int size = ft_lstsize(head);
	free(head->next->next);
	free(head->next);
	free(head);
	if (size == 3)
	{
		printf("\t✅ (size is 3)\n");
		return false;
	}
	else
	{
		printf("\t❌ (size is %d, expected 3)\n", size);
		return true;
	}
}

static bool test_lstsize_case4(void)
{
	printf("--- lstsize (longer list)\t: ");
	t_list *head = ft_lstnew(NULL);
	t_list *current = head;
	for (int i = 0; i < 9; i++)
	{
		current->next = ft_lstnew(NULL);
		current = current->next;
	}
	int size = ft_lstsize(head);
	// Free the list
	current = head;
	t_list *next;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	if (size == 10)
	{
		printf("\t✅ (size is 10)\n");
		return false;
	}
	else
	{
		printf("\t❌ (size is %d, expected 10)\n", size);
		return true;
	}
}

int test_ft_lstsize(void)
{
	int result = 0;

	result |= test_lstsize_case1();
	result |= test_lstsize_case2();
	result |= test_lstsize_case3();
	result |= test_lstsize_case4();

	return result;
}
