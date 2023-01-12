/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:07:14 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/20 14:50:04 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *cha)
{
	size_t	i;

	i = 0;
	while (cha[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
#include<stdio.h>
#include<string.h>

int	main(int argc, char **argv)
{
	printf("base = %ld\n", strlen(argv[1]));
	printf("test = %ld\n", ft_strlen(argv[1]));
	return (0);
}
*/
