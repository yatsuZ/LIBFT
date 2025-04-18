/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstlast_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:02:33 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 18:23:17 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static bool test_lstlast_case1(void)
{
	printf("--- lstlast (empty list)\t: ");
	t_list *head = NULL;
	t_list *last = ft_lstlast(head);
	if (last == NULL)
	{
		printf("\t✅ (returned NULL)\n");
		return false;
	}
	else
	{
		printf("\t❌ (returned non-NULL)\n");
		return true;
	}
}

static bool test_lstlast_case2(void)
{
	printf("--- lstlast (single element)\t: ");
	t_list *head = ft_lstnew(NULL);
	t_list *last = ft_lstlast(head);
	if (last == head)
	{
		free(head);
		printf("\t✅ (returned the head)\n");
		return false;
	}
	else
	{
		free(head);
		printf("\t❌ (did not return the head)\n");
		return true;
	}
}

static bool test_lstlast_case3(void)
{
	printf("--- lstlast (multiple elements)\t: ");
	t_list *head = ft_lstnew((void *)1);
	t_list *second = ft_lstnew((void *)2);
	t_list *third = ft_lstnew((void *)3);
	head->next = second;
	second->next = third;
	t_list *last = ft_lstlast(head);
	if (last == third)
	{
		free(head->next->next);
		free(head->next);
		free(head);
		printf("\t✅ (returned the last element)\n");
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
		printf("\t❌ (did not return the last element)\n");
		return true;
	}
}

static bool test_lstlast_case4(void)
{
	printf("--- lstlast (longer list)\t: ");
	t_list *head = ft_lstnew((void *)1);
	t_list *current = head;
	t_list *last_node = head;
	for (int i = 2; i <= 10; i++)
	{
		current->next = ft_lstnew((void *)(&i));
		current = current->next;
		last_node = current;
	}
	t_list *last = ft_lstlast(head);
	bool res;
	if (last == last_node && last->content == last_node->content)
	{
		printf("\t✅ (returned the last element of a longer list)\n");
		res = false;
	}
	else
	{
		printf("\t❌ (did not return the correct last element of a longer list)\n");
		res = true;
	}
	// Free the list
	current = head;
	t_list *next;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return (res);
}

int test_ft_lstlast(void)
{
	int result = 0;

	result |= test_lstlast_case1();
	result |= test_lstlast_case2();
	result |= test_lstlast_case3();
	result |= test_lstlast_case4();

	return result;
}
