/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:21:41 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/15 12:02:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	long	i;
	char	*d;
	char	*s;

	if (!dest || !src)
		return (NULL);
	d = (char *) dest;
	s = (char *) src;
	if (s > d)
	{
		ft_memcpy(d, s, n);
	}
	else
	{
		i = n - 1;
		while (d[i] && i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dest);
}

/*
//il y a eu plusieur interpretation pour le ft_memove 
#include<stdio.h>
#include<string.h>

int	main()
{
	char	t[] = "0123456789 qwerty";
	char	test[] = "0123456789 qwerty";
	int		dec;

	dec = 4;
	printf("base :\n dest = %s | src = %s | n = %d\n", t + 12, t, dec);
	ft_memmove(t + 12, t, dec);
	printf("TEST :\n dest = %s | src = %s | n = %d\n", t +12, t, dec);
	memmove(test + 12, test, dec);
	printf("fonc :\n dest = %s | src = %s | n = %d\n", test + 12, test, dec);
}*/
