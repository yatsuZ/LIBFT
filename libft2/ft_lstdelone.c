/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:44:39 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/24 19:35:19 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
#include <stdio.h>
jarrive pas a faire marcher le testeur
void	d(void	*l)
{
	free(l);
}

int	main()
{
	t_list	*l;
	char	*bla = "abcde";

	l = ft_lstnew(&bla[0]);
	ft_lstadd_back(&l, ft_lstnew((&bla[1])));
	ft_lstadd_back(&l, ft_lstnew(&bla[2]));
	ft_lstadd_back(&l, ft_lstnew(&bla[3]));
	ft_lstadd_back(&l, ft_lstnew(&bla[5]));
	printf("\n\n");
	printf("l->content = %c\n", *((char *)l->content));
	printf("l->n->content = %c\n", *((char *)l->next->content));
	printf("l->n->n->content = %c\n", *((char *)l->next->next->content));
	printf("l->n->n->n->content = %c\n", 
	*((char *) l->next->next->next->content));
	printf("\ndelone :\n");

	ft_lstdelone(l->next->next->next, &d);
	
	printf("l->content = %c\n", *((char *)l->content));
	printf("l->n->content = %c\n", *((char *)l->next->content));
//	printf("l->n->n->content = %c\n", *((char *)l->next->next->content));
//	printf("l->n->n->n->content = %c\n", 
//	*((char *) l->next->next->next->content));
	if(!l->next->next->next->next)
	{
		printf("l->n->n->n->n->content = (null)\n");
		return (0);
	}
	return (1);
}*/
