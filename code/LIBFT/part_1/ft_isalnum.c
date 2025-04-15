/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:23:10 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/14 22:35:05 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief Vérifie si le paramètre est un caractère numeric base 10 ou 
/// un caractère alphabétique.
/// @param c Le paramètre à vérifier (int).
/// @return 1 si c'est le cas, 0 sinon.
int	ft_isalnum(int c)
{
	return (ft_isalpha((unsigned char)c) || ft_isdigit((unsigned char)c));
}
