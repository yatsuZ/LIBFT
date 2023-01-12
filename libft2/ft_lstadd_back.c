/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:41:08 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/23 20:54:25 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!(*lst))
	{
		*lst = new;
	}
	else
		ft_lstlast(*lst)->next = new;
}

/*
#include <stdio.h>

int	main()
{
	t_list	*l;
	char	*q = "abcdefghijklmnop";

	l = ft_lstnew(&q[0]);
	ft_lstadd_back(&l, ft_lstnew(&q[1]));
	ft_lstadd_back(&l, ft_lstnew(&q[2]));
	ft_lstadd_back(&l, ft_lstnew(&q[3]));
	printf("l[0] = %c\n", *((char *) l->content));
	printf("l[1] = %c\n", *((char *) l->next->content));
	printf("l[2] = %c\n", *((char *) l->next->next->content));
	printf("l[4] = %c\n", *((char *) l->next->next->next->content));
	printf("l[5] = (null)\n");
	printf("avant dernier = %c\n", *(char *)(ft_lstlast(l)->content));
	return (0);
}*/
