/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:16:34 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/21 18:00:28 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = ft_calloc(1, sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

/*
#include<stdio.h>
int	main()
{
	int		value;
	int		newvalue;
	t_list	*t;

	value = 8;
	t = ft_lstnew(&value);
	t->next = ft_calloc(1, sizeof(t_list));
	newvalue = 12;
	t->next->content = &newvalue;
	t->next->next = NULL;
	printf("t.content = %d\n", *((int *)t->content));
	printf("t.content.content =  = %d\n", *((int *)t->next->content));
	return (0);
}*/
