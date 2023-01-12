/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:15:10 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/23 18:38:39 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	if (!(lst->next))
		return (lst);
	return (ft_lstlast(lst->next));
}

/*
#include <stdio.h>

int	main()
{
	t_list	*l;
	char	*q = "abcdefghijklmnop";

	l = ft_lstnew(&q[0]);
	ft_lstadd_front(&l, ft_lstnew(&q[1]));
	ft_lstadd_front(&l, ft_lstnew(&q[2]));
	ft_lstadd_front(&l, ft_lstnew(&q[3]));
	printf("l[0] = %c\n", *((char *) l->content));
	printf("l[1] = %c\n", *((char *) l->next->content));
	printf("l[2] = %c\n", *((char *) l->next->next->content));
	printf("l[4] = %c\n", *((char *) l->next->next->next->content));
	printf("l[5] = (null)\n");
	printf("avant dernier = %c\n", *(char *)(ft_lstlast(l)->content));
	return (0);
}*/
