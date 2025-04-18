/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:31:35 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/18 00:48:34 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief elle libere tout les mayon et suprime leur contenue en gros c'est un
/// free t_list
/// @param lst tete a partir d'ou on doit clear
/// @param del fonction qui permet de libere le comptenue
void ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !(*lst) || !del)
		return ;
	del((*lst)->content);
	ft_lstclear(&(*lst)->next, del);
	free(*lst);
	*lst = NULL;
}