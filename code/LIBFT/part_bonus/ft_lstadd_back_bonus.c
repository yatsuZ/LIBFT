/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:02:03 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 18:25:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief ajoute new a la fin de lst
/// @param lst tete du mayon
/// @param new lelement a ajouté
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	else if (!lst)
		lst = &new;
	else if (!(*lst))
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}