/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:54:06 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/18 19:58:57 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief crée une nouvelle lst mais dont on as apliquer la fonction `f`
/// et on dois tout libéré en cas de pépin
/// @param lst la lst qu'on prend en exemple
/// @param f la fonction qu'on aplique pour changere le contenue
/// @param del la fonction qui suprime les elements en cas de bleme
/// @return la nouvelle list ou NULL en cas de probléme
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;

	if (!lst || !f || !del)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (!res)
		return (res = NULL, NULL);
	else if (res && !res->content)
		return (ft_lstdelone(res, del), res = NULL, NULL);
	if (!lst->next)
		return (res);
	res->next = ft_lstmap(lst->next, f, del);
	if (!res->next)
		return (ft_lstdelone(res, del), res = NULL, NULL);
	return (res);
}