/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:55:10 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 00:51:40 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief pareil que memcpy mais gère les chevauchements de mémoire
/// @param dest le resultat, le destination
/// @param src la source, se qu'on copie
/// @param n le nombre d'element
/// @return dest
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *) dest;
	s = (char *) src;
	if (!dest || !src)
		return (dest);
	else if (!(d >= s && d <= s + n))
		return (ft_memcpy(d, s, n));
	while (n && --n)
	{
		d[n] = s[n];
	}
	d[n] = s[n];
	return (dest);
}
