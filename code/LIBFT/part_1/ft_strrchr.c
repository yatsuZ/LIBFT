/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:19:40 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 00:58:46 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief cherche le dernier c dans s
/// @param s chaine de charactere constante
/// @param c (int) char qu'on rechere
/// @return l'adresse de la ou il a trouver c ou NULL si il trouve pas
char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = NULL;
	while (s && *s)
	{
		if ((char)*s == (char)c)
			res = (char *)s;
		s++;
	}
	if ((char)*s == (char)c)
		res = (char *)s;
	return (res);
}
