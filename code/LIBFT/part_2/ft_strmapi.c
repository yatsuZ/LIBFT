/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:51:16 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 16:04:40 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief cree une nouvelle string ou on as apliquer la ft f a char de s
/// @param s string de reference
/// @param f focntion qu'on apliquera prendra un int et un char en parametre 
/// et return un char.
/// @return une string
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sc;
	size_t	i;
	size_t	size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen((char *) s);
	if (size > LONG_MAX)
		return (NULL);
	i = 0;
	sc = ft_calloc(++size, sizeof(char));
	if (!sc)
		return (NULL);
	while (s[i])
	{
		sc[i] = f((unsigned int)i, s[i]);
		i++;
	}
	sc[i] = '\0';
	return (sc);
}
