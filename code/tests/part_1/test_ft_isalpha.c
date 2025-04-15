/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:08:29 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 03:04:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// comparer avec la vrai fonction faire une boucle de -10 a 300
// certain cas ne son pas similaire !!
int	test_ft_isalpha(void)
{
	printf("--- isalpha\t: ");
	int c = -10;
	while (c != 300)
	{
		if ((isalpha(c) != 0) != (ft_isalpha(c) != 0))
			return (printf("Error!!! with %c %d, | %d %d\n", (c), c, isalpha(c), ft_isalpha(c)), 1);
		c++;
	}
	printf("\t✅\n");
	return (0);
}