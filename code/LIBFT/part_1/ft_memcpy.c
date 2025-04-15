/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:47:05 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 16:55:16 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief dois coppier les n premier element de src vers des
/// @param dest le resultat, le destination
/// @param src la source, se qu'on copie
/// @param n le nombre d'element
/// @return dest
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*src_str;
	unsigned char	*dest_str;
	size_t			i;

	if (!dest)
		return (NULL);
	dest_str = (unsigned char *)dest;
	src_str = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_str[i] = src_str[i];
		++i;
	}
	return (dest);
}
