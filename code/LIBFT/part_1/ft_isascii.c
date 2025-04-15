/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 02:37:14 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 02:43:06 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief Vérifie si le paramètre est un caractère ascii.
/// @param c Le paramètre à vérifier (int).
/// @return 1 si c'est le cas, 0 sinon.
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
