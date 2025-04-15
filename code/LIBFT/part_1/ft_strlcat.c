/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:33:13 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 00:52:28 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief rajoute src a la fin de dest respect la size demandé.
/// S'arrete a la fin de src ou size
/// @param dest le resultat, le destination
/// @param src ce que je vais rajouetr a la fin de dest
/// @param size La taille qu'on shouaite avoir src+dest
/// @return la longueur totale de la chaîne qu'elle a tenté de créer.
/// longueur initiale de dest plus la longueur de src
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;

	i = 0;
	if (!dest || !src)
		return (0);
	len_dest = ft_strlen(dest);
	while (size && src[i] && (i + len_dest) < size - 1)
	{
		dest[i + len_dest] = src[i];
		i++;
	}
	if (size < len_dest)
		return (ft_strlen(src) + size);
	dest[i + len_dest] = '\0';
	return (ft_strlen(src) + len_dest);
}
