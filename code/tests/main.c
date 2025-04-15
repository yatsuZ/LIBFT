/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:24:01 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/14 22:27:45 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft_tester.h"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	return (0);
}