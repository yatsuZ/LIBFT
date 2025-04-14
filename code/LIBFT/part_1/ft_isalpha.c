/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:37:50 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/14 15:25:42 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief Vérifie si le paramètre est un caractère alphabétique.
/// @param c Le paramètre à vérifier (int).
/// @return 1 si c'est un caractère alphabétique, 0 sinon.
int	ft_isalpha(int c)
{
	unsigned char	newc;

	newc = c;
	return ((newc >= 'A' && newc <= 'Z') || (newc >= 'a' && newc <= 'z'));
}
