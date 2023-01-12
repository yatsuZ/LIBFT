/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:30:41 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/24 19:35:56 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*src_str;
	unsigned char	*dest_str;
	size_t			i;

	if (!dest)
		return (NULL);
	dest_str = (unsigned char *)dest;
	src_str = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_str[i] = src_str[i];
		++i;
	}
	return (dest);
}

/*
#include<string.h>
#include<stdio.h>


int	main()
{
	char	t[] = "0123456789 qwerty";
	char	test[] = "0123456789 qwerty";
	int	dec;

	dec = 4;
	printf("base :\n dest = %s | src = %s | n = %d\n", t, t + 12, dec);
	ft_memcpy(t, t + 12, dec);
	printf("TEST :\n dest = %s | src = %s | n = %d\n", t, t + 12, dec);
	memcpy(test, test + 12, dec);
}*/
