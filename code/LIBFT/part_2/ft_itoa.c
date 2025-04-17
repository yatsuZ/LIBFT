/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:43:37 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 16:04:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief dis le nombre de char qu'il y a dans n (ft recursive)
/// @param n le nombre
/// @param size le nombre de char en parametre
/// @return le nombre de char
static size_t	ft_nbrofchar(long n, size_t size)
{
	size++;
	if (n < 0)
		size = ft_nbrofchar(-n, size);
	else if (n >= 10)
		size = ft_nbrofchar(n / 10, size);
	return (size);
}

/// @brief ajoue des char dans s. (fonction recursive)
/// @param n la valeur a convertir
/// @param s resultat
/// @param i index dans s
/// @return lindex de i
static size_t	ft_add(long n, char *s, size_t i)
{
	if (n < 0)
	{
		s[i] = '-';
		i = ft_add(-n, s, ++i);
	}
	else if (n >= 10)
	{
		i = ft_add(n / 10, s, i);
		s[i] = (char)(n % 10) + 48;
	}
	else
		s[i] = (char)(n % 10) + 48;
	return (++i);
}

/// @brief convertie un int en char *
/// @param n ce qu'on veut convertir
/// @return un string et NULL si y a un probléme
char	*ft_itoa(int n)
{
	size_t	nbrofchar;
	char	*strint;

	nbrofchar = ft_nbrofchar((long)n, 0) + 1;
	strint = ft_calloc(nbrofchar, sizeof(char));
	if (!strint)
		return (strint);
	ft_add((long)n, strint, 0);
	return (strint);
}
