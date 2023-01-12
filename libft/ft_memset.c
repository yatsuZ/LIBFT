/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:03:36 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/15 11:57:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast;

	if (!s)
		return (NULL);
	cast = (unsigned char *)s;
	while (n--)
		cast[n] = c;
	return (s);
}
/*
#include<string.h>
#include<stdio.h>

int	main(void)
{
	char t[] = "";
	char t2[] = "YOLO";
	printf("ARG1 = %s\nARG2 = %s\n", t, t2);
	memset(t, '2', 3);
	ft_memset(t2, '3', 3);
	printf("FUNC = %s\nTEST = %s\n", t, t2);
	return (0);
}*/
