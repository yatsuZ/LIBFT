/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:11:51 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 16:18:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	size;
	char	*castc;

	if (!s || !f)
		return ;
	size = ft_strlen((char *) s);
	if (size > UINT_MAX)
		return ;
	i = 0;
	castc = s;
	while (s[i])
	{
		f((unsigned int)i, castc++);
		i++;
	}
}
