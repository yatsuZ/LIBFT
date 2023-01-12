/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:20:41 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/21 17:18:11 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	size;
	char	*castc;

	if (!s || !f)
		return ;
	size = ft_strlen((char *) s);
	if (size > 4294967295)
		return ;
	i = 0;
	castc = s;
	while (s[i])
	{
		f((unsigned int)i, castc++);
		i++;
	}
}

/*
#include <stdio.h>

void	testfunc(unsigned int n, char *c)
{
//	printf("c = %c | n = %d | c + n = %c\n", c[n], n, (char)(c[n] + n));
	*c += n;
}

int	main(void)
{
	char	t[] = "0000000000";
	char	t2[] = "aaaaaa";

	printf("t = %s\nt2 = %s\n", t,t2);
	ft_striteri(t, &testfunc);
	printf("--------\n\n");
	ft_striteri(t2, &testfunc);
	printf("t = %s\nt2 = %s\n", t,t2);
	return (0);
}*/
