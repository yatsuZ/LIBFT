/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:46:00 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 21:23:27 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief similaire a memcopy mais garantie de terminer pas un \0
/// @param dest le resultat, le destination
/// @param src la source, se qu'on copie
/// @param size la taille de dest
/// @return Retourne la longueur totale de src, sans compter le caractère nul.
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (src[i] && (size && i < (size - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i++] = '\0';
	return (ft_strlen((char *)src));
}
