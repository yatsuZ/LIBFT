/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:51:30 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/20 15:56:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pt;
	size_t	totalsize;

	if (!nmemb && !size)
		return (NULL);
	else if (!nmemb || !size)
		return (malloc(0));
	totalsize = size * nmemb;
	if (totalsize / size != nmemb)
		return (NULL);
	pt = malloc(totalsize);
	if (!pt)
		return (NULL);
	ft_bzero(pt, totalsize);
	return (pt);
}
/*
#include <stdint.h>
#include <stdio.h>

int	main()
{
	size_t	input = 4;
	size_t	size = sizeof(char);
	char	*strT = ft_calloc(input, size);
	char	*str = calloc(input, size);
	size_t	i = 0;


	strT[2] = 'P';
	str[2] = 'L';
	printf("\nreturn of calloc = %p\n", calloc(1, 9223372036854775807));
	printf("nmemb = %ld\nsize = %ld\n", input, size);
	printf("TEST = ");
	while (i < input)
		printf("%c, ",strT[i++]);
	i = 0;
	printf("\nFUNC = ");
	while (i < input)
		printf("%c, ",str[i++]);
	return (0);
}*/
