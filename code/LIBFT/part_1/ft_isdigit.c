/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:20:35 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/14 15:24:09 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief Vérifie si le paramètre est un caractère alphabétique.
/// @param c Le paramètre à vérifier (int).
/// @return 1 si c'est un caractère alphabétique, 0 sinon.
int	ft_isalpha(int	c)
{
	unsigned char newc = c;
	return ((newc >= 'A' && newc <= 'Z') || (newc >= 'a' && newc <= 'z'));
}
