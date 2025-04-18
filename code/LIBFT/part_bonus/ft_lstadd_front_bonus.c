/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:25:30 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 17:49:01 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief Ajoute l'element new aux depart de lst.
/// @param lst chaine de t_liste.
/// @param new un mayon qui faudra ajouter à lst.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		lst = &new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
