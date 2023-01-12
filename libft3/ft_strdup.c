/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:17:35 by yzaoui            #+#    #+#             */
/*   Updated: 2022/11/20 17:52:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	char	*str;

	str = (char *) s;
	len = ft_strlen(str) + 1;
	ptr = ft_calloc(len, sizeof(char));
	ft_strlcpy(ptr, str, len);
	return (ptr);
}
