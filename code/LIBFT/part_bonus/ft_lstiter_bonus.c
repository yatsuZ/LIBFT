/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:50:44 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/18 00:53:39 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief applique une fonction a chaque mayon de la lst
/// @param lst a partir de cette tete
/// @param f fonstion qui doit etre appliquer
void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	f(lst->content);
	if (!lst->next)
		return ;
	ft_lstiter(lst->next, f);
}