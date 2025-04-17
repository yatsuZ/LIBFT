/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:08:26 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 13:54:31 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief une nouvelle string qui sera s1 + s2
/// @param s1 debut
/// @param s2 fin
/// @return la nouvelle string qu'il faudra free
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	new_len;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	new_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = ft_calloc(new_len, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcpy(res + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (res);
}
