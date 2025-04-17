/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:21:00 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 13:56:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

ssize_t	pos_of_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1 && s1[i])
	{
		j = 0;
		while (set && set[j] && set[j] != s1[i])
		{
			j++;
		}
		if (set[j] != s1[i])
			return (i);
		i++;
	}
	return (-1);
}

ssize_t	pos_of_end(char const *s1, char const *set, size_t len_s1)
{
	size_t	i;
	size_t	j;

	i = len_s1;
	while (i)
	{
		--i;
		j = 0;
		while (set && set[j] && set[j] != s1[i])
		{
			j++;
		}
		if (set[j] != s1[i])
			return (i);
	}
	return (len_s1);
}

/// @brief une copie de la chaîne `s1`, 
/// dans laquelle les caractères spécifiés dans la chaîne `set` 
/// sont supprimés du début et de la fin de la chaîne.
/// @param s1 chaine a recopier
/// @param set liste de char a ne pas recopier
/// @return une nouvelle string ui est une copier de s1 sans les char 
/// de set u debut et la fin de s1. (ou null si pas poissible 
/// dallouer de la memoire)
char	*ft_strtrim(char const *s1, char const *set)
{
	ssize_t	start;
	ssize_t	end;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	start = pos_of_start(s1, set);
	if (start == -1)
		return (ft_calloc(1, sizeof(char)));
	end = pos_of_end(s1, set, ft_strlen(s1));
	return (ft_substr(s1, (unsigned int) start, end - start + 1));
}
