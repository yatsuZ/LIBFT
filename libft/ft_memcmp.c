/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:11:04 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/25 13:08:52 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;
	int				r;

	i = 0;
	c2 = (unsigned char *) s2;
	c1 = (unsigned char *) s1;
	while (i < n)
	{
		r = c1[i] - c2[i];
		if (r != 0)
		{
			return (r);
		}
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char	t[] =  "t\200";
	char	t2[] = "t\0";
	size_t	n = 2;

	printf("arg1 = %s\narg2 = %s\narg3 = %ld\n", t, t2, n);
	printf("FUNC = %d\nTEST = %d\n", memcmp(t, t2, n), ft_memcmp(t, t2, n));
	return (0);
}*/
