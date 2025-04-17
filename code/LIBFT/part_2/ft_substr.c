/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:10:43 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 11:49:24 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief cree une nouvelle string a partir de s[start] de longuer len
/// @param s chaine de string
/// @param start debut de la copie
/// @param len la longuer de la nouvelle string
/// @return la nouvelle string et null si pas possible (doit free)
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	len_str;

	if (!s)
		return (ft_calloc(1, sizeof(char)));
	len_str = ft_strlen((char *) s);
	if (start >= len_str)
		return (ft_calloc(1, sizeof(char)));
	else if (len_str - start < len)
		len = len_str - start;
	len++;
	res = ft_calloc(len, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s + start, len);
	return (res);
}
