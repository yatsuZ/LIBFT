/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:45:02 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/17 17:16:47 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sc;
	size_t	i;
	size_t	size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen((char *) s);
	if (size > 4294967295)
		return (NULL);
	i = 0;
	sc = ft_calloc(++size, sizeof(char));
	while (s[i])
	{
		sc[i] = f((unsigned int)i, s[i]);
		i++;
	}
	sc[i] = '\0';
	return (sc);
}

/*
#include <stdio.h>

char	testfunc(unsigned int n, char c)
{
	printf("c = %c | n = %d | c + n = %c\n", c, n, (char)(c + n));
	return (c + (char) n);
}

int	main(void)
{
	char	t[] = "abcAB";
	char	t2[] = "aaaaaa";
	char	*r;
	char	*r2;

	r = ft_strmapi(t, &testfunc);
	printf("--------\n\n");
	r2 = ft_strmapi(t2, &testfunc);
	printf("t = %s\nr = %s\nt2 = %s\nr2 = %s\n", t, r, t2, r2);
	return (0);
}*/
