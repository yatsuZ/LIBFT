/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:45:00 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/25 17:57:14 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (len && ((little && !little[0] && !big[0]) || (little && !little[0])))
		return ((char *) big);
	if (!little)
		return (NULL);
	while (big[i] && i < len)
	{
		while (big[i + j] && i + j < len && big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return (((char *)big) + i);
		}
		j = 0;
		i++;
	}
	if (!len && !big[0] && big[0] == little[0])
		return ((char *) big);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("res : %s\n", ft_strnstr((const char *)"", "", 0));
	return (0);
}
*/
