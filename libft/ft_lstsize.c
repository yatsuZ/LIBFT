/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:01:20 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/23 18:10:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	if (!lst)
		return (0);
	return (1 + ft_lstsize(lst->next));
}

/*
#include <stdio.h>
int	main()
{
	t_list	*l;
	char	s = 'e';
	char	b = 'b';
	l = ft_lstnew(&s);
	ft_lstadd_front(&l, ft_lstnew(&b));
	printf("l = %c\n", *((char *)(l->content)));
	printf("size = %d\n", ft_lstsize(l));
	return (0);
}*/
