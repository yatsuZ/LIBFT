/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:56:07 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 16:43:02 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief remplit les n premiers octets de la zone mémoire pointée 
/// par s avec la valeur c .
/// @param s le pointeur void
/// @param c les char a remplir(int)
/// @param n le nombre d'ocurence a partir du pointeur (size_t) 
/// @return le pointeur s aux depart
void	*ft_memset(void *s, int c, size_t n)
{
	void			*res;
	unsigned char	new_c;

	if (!n)
		return (s);
	res = s;
	new_c = c;
	s = s + n - 1;
	while (res && s != res)
	{
		*((char *)(s)) = new_c;
		s--;
	}
	if (s)
		*((char *)(s)) = new_c;
	return (res);
}
