/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:03:59 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 00:55:07 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TESTER_H
# define LIBFT_TESTER_H

#define BUFF_SIZE 100

/* ************************************************************************** */
/*                                 INCLUDES                                   */
/* ************************************************************************** */

# include "./../LIBFT/libft.h"// ICI metre le chemin de votre header
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>

/* ************************************************************************** */
/*                                 PARTIE 1                                   */
/* ************************************************************************** */

int	test_ft_isalpha(void);
int	test_ft_isdigit(void);
int	test_ft_isalnum(void);
int	test_ft_isascii(void);
int	test_ft_isprint(void);
int	test_ft_strlen(void);
int	test_ft_memset(void);
int	test_ft_bzero(void);
int	test_ft_memcpy(void);
int test_ft_memmove(void);
int	test_ft_strlcpy(void);
int	test_ft_strlcat(void);
int	test_ft_toupper(void);
int	test_ft_tolower(void);
int	test_ft_strchr(void);
int test_ft_strrchr(void);

/* ************************************************************************** */
/*                                 PARTIE 2                                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                FONCTIONS BONUS                             */
/* ************************************************************************** */


#endif