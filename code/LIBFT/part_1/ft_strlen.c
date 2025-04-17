/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 02:48:09 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 11:44:48 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief Verifie les nombre de caractere du parametre temp qu'on as vu de \0
/// @param s pointeur de char constant
/// @return le nombre de char excepte \0
size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	while (s && *s++)
	{
		res++;
	}
	return (res);
}
