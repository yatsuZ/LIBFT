/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:07:37 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 01:15:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief cree une string avec les meme element que s1
/// @param s1 la string qu'on copie
/// @return la nouvelle string NULL si on as pas pue la copier.
/// (IL FAUT LA FREE)
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	str = (char *) s1;
	len = ft_strlen(str) + 1;
	ptr = ft_calloc(len, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str, len);
	return (ptr);
}
