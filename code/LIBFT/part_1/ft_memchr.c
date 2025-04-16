/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:47:23 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 01:11:49 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief localise la première occurrence du caractère `c` dans 
/// les `n` premiers octets de `s`
/// @param s zone de recheche
/// @param c le char qu'on cherche
/// @param n le nombre delement 
/// @return l'adress ou on trouc `c` dans `s` ou NULL si on trouve rien
void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!s || !n)
		return (NULL);
	while (--n && ((unsigned char) *((unsigned char *)s)) != (unsigned char) c)
	{
		s++;
	}
	if (((unsigned char) *((unsigned char *)s)) == (unsigned char) c)
		return ((void *)s);
	return (NULL);
}
