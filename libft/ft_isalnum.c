/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:57:39 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/20 14:55:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<unistd.h>

int	ft_isalnum(int cha)
{
	if (ft_isdigit(cha) || ft_isalpha(cha))
		return (8);
	return (0);
}

/*
pk la fonction de base return 8
int	main(void)
{
	if (ft_isalnum('1') == 1)
	{
		write(1, "T", 1);
	}
	return (0);
}
*/
