/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:27:43 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/20 16:58:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && (size > 0 && i < (size - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
	{
		dest[i++] = '\0';
	}
	return (ft_strlen((char *)src));
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <bsd/bsd.h>
#include <string.h>
int		main(int ac, char **av)
{
	if (ac == 3)
	{
		char	n1[250];
		char	n2[250];
		printf("%lu\n",strlcpy(n1, av[1], atoi(av[2])));
		printf("%s\n", n1);
		printf("%lu\n",ft_strlcpy(n2, av[1], atoi(av[2])));
		printf("%s\n", n2);
	}
	return (0);
}*/
