/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:43:22 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 17:05:34 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief Affiche une chaine de char a la sortie fd
/// @param s ce qu'on shouaite affiche 
/// @param fd a cette sortie
void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	while (s && *s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
