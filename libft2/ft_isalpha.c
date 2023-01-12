/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:53:48 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/18 15:44:55 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(char cha)
{
	if ((cha >= 'a' && cha <= 'z') || (cha >= 'A' && cha <= 'Z'))
		return (1024);
	return (0);
}
/*
#include<stdio.h>
#include <ctype.h>

int	main(void)
{
	int	ct;
	int	c;
	int	i = -10;

	while (i <= 255)
	{
		c = isalpha(i);
		ct = ft_isalpha(i);
		if ((c && !ct) || (!c && ct))
		{
			printf("y a une erreur\ni = %d\ntest = %d\nfunc = %d\n", i, ct, c);
			return (0);
		}
		i++;
	}
	printf("le Testeur dis nimp >:( il ma fais peur\n");
	printf("cest pas la aute du testeur juste la vrai fonction retourne ");
	printf("2 p 10 soit 1024 en decimal soit 10000000000 en binaire");
	return (0);
}*/
