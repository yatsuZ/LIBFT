/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:17:20 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/20 20:45:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lon;
	char	*news;
	size_t	space;

	lon = ft_strlen((char *) s);
	if (start > lon)
		return (ft_strdup(""));
	space = lon - start ;
	if (space > len)
		space = len;
	news = ft_calloc(space + 1, sizeof(char));
	i = 0;
	while (s[i + start] && i < len)
	{
		news[i] = s[i + start];
		i++;
	}
	if (news[i])
		news[i] = '\0';
	return (news);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char			t[] = "je suis fou";
	unsigned int	i = 0;
	size_t			len = 4200;
	char			*r;
	int				comp;
	printf("s = %s\nstart = %d\nlen = %ld\n", t, i, len);
	r = ft_substr((const char *) t, i, len);
	printf("RESULT = %s\n", r);
	comp = strcmp((const char *)t, (const char *)r);
	if (comp)
		printf("ERROR %d\n", comp);
	free(r);
	return (0);
}*/
