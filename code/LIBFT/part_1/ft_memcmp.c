/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:51:10 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 01:11:07 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief compare les `n` premiers octets 
/// des zones mémoire pointées par `s1` et `s2`
/// @param s1 zone memoire de s1
/// @param s2 zone memoire de s2
/// @param n le nombre delement a comparer
/// @return s1[dif] - s2[dif]
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	if (!s1 || !s2 || !n)
		return (0);
	ucs1 = (unsigned char *) s1;
	ucs2 = (unsigned char *) s2;
	while (--n && *ucs1 == *ucs2)
	{
		ucs1++;
		ucs2++;
	}
	return (*ucs1 - *ucs2);
}
