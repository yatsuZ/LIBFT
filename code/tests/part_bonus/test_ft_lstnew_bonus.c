/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:18:59 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 17:43:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

static bool test_lstnew_case1(void)
{
	printf("--- lstnew (content NULL)\t: ");
	t_list *new_node = ft_lstnew(NULL);
	if (new_node != NULL && new_node->content == NULL && new_node->next == NULL)
	{
		free(new_node);
		printf("\t✅\n");
		return false;
	}
	else
	{
		if (new_node)
			free(new_node);
		printf("\t❌ (content or next incorrect)\n");
		return true;
	}
}

static bool test_lstnew_case2(void)
{
	printf("--- lstnew (valid content)\t: ");
	int data = 42;
	t_list *new_node = ft_lstnew(&data);
	if (new_node != NULL && new_node->content == &data && new_node->next == NULL)
	{
		free(new_node);
		printf("\t✅\n");
		return false;
	}
	else
	{
		if (new_node)
			free(new_node);
		printf("\t❌ (content or next incorrect)\n");
		return true;
	}
}

int test_ft_lstnew(void)
{
	int result = 0;

	result |= test_lstnew_case1();
	result |= test_lstnew_case2();

	return result;
}

