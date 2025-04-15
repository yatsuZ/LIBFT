/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:58:35 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 00:52:45 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief Convertit un caractère majuscule en minuscule. ne fais rien sinon
/// @param c Le char a convertire
/// @return Le char en minuscule sinon rien
int	ft_tolower(int c)
{
	unsigned char	new_c;

	new_c = c;
	if (c == EOF)
		return (EOF);
	if (new_c >= 'A' && new_c <= 'Z')
		return (new_c + ('a' - 'A'));
	return (new_c);
}
