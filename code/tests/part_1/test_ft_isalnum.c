/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 22:26:49 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 03:04:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// comparer avec la vrai fonction faire une boucle de -10 a 255
// certain cas ne son pas similaire !!
int	test_ft_isalnum(void)
{
	printf("--- isalnum\t: ");
	int c = -10;
	while (c != 255)
	{
		if ((isalnum(c) != 0) != (ft_isalnum(c) != 0))
			return (printf("Error!!! with %c %d, | %d %d\n", (c), c, isalnum(c), ft_isalnum(c)), 1);
		c++;
	}
	printf("\t✅\n");
	return (0);
}