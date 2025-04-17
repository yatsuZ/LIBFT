/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:03:59 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/17 16:55:57 by yzaoui           ###   ########.fr       */
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
# include <errno.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>

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
int	test_ft_strrchr(void);
int	test_ft_strncmp(void);
int test_ft_memchr(void);
int test_ft_memcmp(void);
int test_ft_strnstr(void);
int test_ft_atoi(void);
int test_ft_calloc(void);
int test_ft_strdup(void);

/* ************************************************************************** */
/*                                 PARTIE 2                                   */
/* ************************************************************************** */

int test_ft_substr(void);
int test_ft_strjoin(void);
int test_ft_strtrim(void);
int test_ft_split(void);
int test_ft_itoa(void);
int test_ft_strmapi(void);
int test_ft_striteri(void);
int test_ft_putfd(void);

/* ************************************************************************** */
/*                                FONCTIONS BONUS                             */
/* ************************************************************************** */


#endif