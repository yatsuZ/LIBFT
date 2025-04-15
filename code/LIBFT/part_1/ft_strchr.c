/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:34:07 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 00:52:22 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief cherche le premier c dans s
/// @param s chaine de charactere constante
/// @param c (int) char qu'on rechere
/// @return l'adresse de la ou il a trouver c ou NULL si il trouve pas
char	*ft_strchr(const char *s, int c)
{
	while (s && *s && *s != (char) c)
	{
		s++;
	}
	if (*s != (char) c)
		return (NULL);
	return ((char *)s);
}
