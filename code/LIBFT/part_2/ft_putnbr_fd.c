/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:50:20 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 17:05:07 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief Elle fais la conversion et les calcul necessaire
/// @param n ce qu'on shouaite affiché
/// @param fd a cette sortie
static void	ft_putnbr_rec(long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_rec(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_rec(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else
		ft_putchar_fd(n % 10 + 48, fd);
}

/// @brief affiche a la sortie fd la conversion d'un int
/// @param n ce qu'on shoauite affiche 
/// @param fd a ce fd
void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	ft_putnbr_rec((long) n, fd);
}