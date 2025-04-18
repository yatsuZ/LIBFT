/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstmap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:57:11 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/18 20:00:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// Fonction de mapping simple : doubler la valeur entière
static void *double_content(void *content)
{
	if (!content)
		return (NULL);
	int *val = malloc(sizeof(int));
	if (!val)
		return (NULL);
	*val = *(int *)content * 2;
	return (val);
}

// Fonction de suppression de contenu simple
static void del_content(void *content)
{
	if (content)
		free(content);
	content = NULL;
}

// Fonction utilitaire pour vérifier le contenu d'une liste
static bool check_mapped_content(t_list *lst, int expected[])
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

static bool test_lstmap_case1(void)
{
	printf("--- lstmap (lst is NULL)\t: ");
	t_list *new_list = ft_lstmap(NULL, double_content, del_content);
	if (new_list == NULL)
		printf("\t✅ (returned NULL)\n");
	else
	{
		ft_lstclear(&new_list, del_content);
		printf("\t❌ (did not return NULL)\n");
	}
	return (new_list != NULL);
}

static bool test_lstmap_case2(void)
{
	printf("--- lstmap (f is NULL)\t: ");
	t_list *head = ft_lstnew(malloc(sizeof(int)));
	if (head && head->content)
		*(int *)head->content = 5;
	t_list *new_list = ft_lstmap(head, NULL, del_content);
	ft_lstclear(&head, free);
	if (new_list == NULL)
		printf("\t✅ (returned NULL)\n");
	else
	{
		ft_lstclear(&new_list, del_content);
		printf("\t❌ (did not return NULL)\n");
	}
	return (new_list != NULL);
}

static bool test_lstmap_case3(void)
{
	printf("--- lstmap (empty list)\t: ");
	t_list *head = NULL;
	t_list *new_list = ft_lstmap(head, double_content, del_content);
	if (new_list == NULL)
		printf("\t✅ (returned NULL)\n");
	else
	{
		ft_lstclear(&new_list, del_content);
		printf("\t❌ (did not return NULL)\n");
	}
	return (new_list != NULL);
}

static bool test_lstmap_case4(void)
{
	printf("--- lstmap (single element)\t: ");
	t_list *head = ft_lstnew(malloc(sizeof(int)));
	if (!head || !head->content)
		return (true);
	*(int *)head->content = 10;
	t_list *new_list = ft_lstmap(head, double_content, del_content);
	ft_lstclear(&head, free);
	bool result = (new_list && *(int *)new_list->content == 20 && new_list->next == NULL);
	ft_lstclear(&new_list, del_content);
	if (result)
		printf("\t✅ (mapped single element)\n");
	else
		printf("\t❌ (did not map single element correctly)\n");
	return (!result);
}

static bool test_lstmap_case5(void)
{
	printf("--- lstmap (multiple elements)\t: ");
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
	t_list *new_list = ft_lstmap(head, double_content, del_content);
	ft_lstclear(&head, free);
	int expected[] = {2, 4, 6};
	bool result = check_mapped_content(new_list, expected);
	ft_lstclear(&new_list, del_content);
	if (result)
		printf("\t✅ (mapped multiple elements)\n");
	else
		printf("\t❌ (did not map multiple elements correctly)\n");
	return (!result);
}


/* Test non valide car fail_alloc_map ne libere pas de la memoire
// Test de l'échec d'allocation dans la fonction de mapping
*/
void *fail_alloc_map(void *content)
{
	(void)content;
	return (NULL);
}

// Fonction de suppression de contenu simple
void r(void *content)
{
	(void)content;
}

static bool test_lstmap_case6(void)
{
	printf("--- lstmap (map func returns NULL)\t: ");
	t_list *head = ft_lstnew(NULL);
	int	a = 7;
	if (head)
		head->content = &a;
	t_list *new_list = ft_lstmap(head, fail_alloc_map, r);
	head->content = NULL;
	free(head);
	if (new_list == NULL)
		printf("\t✅ (returned NULL on map failure)\n");
	else
	{
		ft_lstclear(&new_list, del_content);
		printf("\t❌ (did not return NULL on map failure)\n");
	}
	return (new_list != NULL);
}

// Test de l'échec d'allocation lors de la création d'un nouveau nœud
static void *alloc_once_fail(void *content)
{
	static int call_count = 0;
	if (call_count++ == 1)
		return (NULL);
	int *val = malloc(sizeof(int));
	if (val)
		*val = *(int *)content * 2;
	return (val);
}

static bool test_lstmap_case7(void)
{
	printf("--- lstmap (malloc fails during map)\t: ");
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
	t_list *new_list = ft_lstmap(head, alloc_once_fail, del_content);
	ft_lstclear(&head, free);
	if (new_list == NULL)
		printf("\t✅ (returned NULL on malloc failure)\n");
	else
	{
		ft_lstclear(&new_list, del_content);
		printf("\t❌ (did not return NULL on malloc failure)\n");
	}
	return (new_list != NULL);
}

int test_ft_lstmap(void)
{
	int result = 0;

	result |= test_lstmap_case1();
	result |= test_lstmap_case2();
	result |= test_lstmap_case3();
	result |= test_lstmap_case4();
	result |= test_lstmap_case5();
	result |= test_lstmap_case6();
	result |= test_lstmap_case7();

	return (result);
}