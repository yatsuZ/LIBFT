/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:37:01 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 19:22:28 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief remplit les n premiers octets de la zone mémoire pointée 
/// par s avec le char \0 .
/// @param s le pointeur void
/// @param n le nombre d'ocurence a partir du pointeur (size_t) 
void	ft_bzero(void *s, size_t n)
{
	s = ft_memset(s, 0, n);
}
