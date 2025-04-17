/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:14:22 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 15:42:17 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft.h"

/// @brief Compte le nombre de mot separer par c
/// @param s 
/// @param c separateur
/// @return le nombre de mot separer par c
static size_t	count_word(char const *s, char c)
{
	size_t	nbw;
	size_t	i;
	int		boolean;

	boolean = 1;
	i = 0;
	nbw = 0;
	while (s[i])
	{
		if (s[i] == c)
			boolean = 1;
		else
		{
			if (boolean)
				nbw++;
			boolean = 0;
		}
		i++;
	}
	return (nbw);
}

/// @brief mets a jour les position de start et end
/// @param start debut du cut
/// @param end fin du cut
/// @param s chaine de char
/// @param c separateur
static void	get_start_and_end(size_t *start, size_t *end, const char *s, char c)
{
	*start = *end;
	while (s[*end] && s[*end] != c)
		(*end)++;
}

/// @brief set chaque tableau de res
/// @param res pointeur du tableau
/// @param s chaine dont sera extraite les mots
/// @param c le seperateur
/// @param i index du tableau res
/// @return index du tableau + 1 de la ou il y a un probleme de memoire.
/// Sinon 0 si tout se passe bien
static size_t	ft_set_split(char ***res, char const *s, char c, size_t i)
{
	size_t	start;
	size_t	end;

	start = 1;
	end = 0;
	while (s[end])
	{
		if (s[end] == c)
			start = 1;
		else
		{
			if (start)
			{
				get_start_and_end(&start, &end, s, c);
				(*res)[i] = ft_substr(s, start, end - start);
				if ((*res)[i++] == NULL)
					return (i);
				end--;
			}
			start = 0;
		}
		end++;
	}
	return (0);
}

/// @brief free tout si y a une error
/// @param res ce que je dois free
/// @param nbr_of_word le nombre delement du tableau
/// @param error si y a une erreur
static void	ft_free_split(char ***res, size_t error)
{
	if (!error)
		return ;
	while (error--)
	{
		free((*res)[error]);
	}
	free(*res);
	*res = NULL;
}

/// @brief fais un tableau de de char contenant chaque mot separer par c
/// @param s 
/// @param c seperateur
/// @return un tableau de string ou null si probleme de memoir
char	**ft_split(char const *s, char c)
{
	size_t		error;
	size_t		nbr_of_word;
	char		**res;

	if (!s)
		return (NULL);
	nbr_of_word = count_word(s, c);
	error = 0;
	res = ft_calloc(nbr_of_word + 1, sizeof(char *));
	res[nbr_of_word] = NULL;
	if (!res)
		return (NULL);
	error = ft_set_split(&res, s, c, 0);
	ft_free_split(&res, error);
	return (res);
}
