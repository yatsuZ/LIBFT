/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:20:35 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/14 15:29:24 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief Vérifie si le paramètre est un caractère numeric base 10.
/// @param c Le paramètre à vérifier (int).
/// @return 1 si c'est un caractère numeric, 0 sinon.
int	ft_isdigit(int c)
{
	unsigned char	newc;

	newc = c;
	return ((newc >= '0' && newc <= '9'));
}
