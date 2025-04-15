/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 02:41:12 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 02:42:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief Vérifie si le paramètre est un caractère affichable.
/// @param c Le paramètre à vérifier (int).
/// @return 1 si c'est le cas, 0 sinon.
int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}
