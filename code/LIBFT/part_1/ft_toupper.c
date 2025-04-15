/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:50:57 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 00:52:13 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief Convertit un caractère minuscule en majuscule. ne fais rien sinon
/// @param c Le char a convertire
/// @return Le char en majuscule sinon rien
int	ft_toupper(int c)
{
	unsigned char	new_c;

	new_c = c;
	if (c == EOF)
		return (EOF);
	if (new_c >= 'a' && new_c <= 'z')
		return (new_c - ('a' - 'A'));
	return (new_c);
}
