/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:49:54 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 23:49:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief cherche la str `little` dans `big` avec comme limite len
/// @param big zone de recherche
/// @param little ce qu'on recherche
/// @param len taille max
/// @return big si `little` et un chaine vide NULL si on touvre pas `little`
/// dans `big` le pointeur de la premier occurence `big`
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little && !(*little))
		return ((char *)big);
	i = 0;
	j = 0;
	while (big && little && big[i] && i < len)
	{
		while (big[i] == little[j] && i < len)
		{
			i++;
			j++;
		}
		i = i - j;
		if (!little[j])
			return ((char *)big + i);
		j = 0;
		i++;
	}
	return (NULL);
}
