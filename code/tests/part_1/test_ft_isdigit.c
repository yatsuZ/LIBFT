/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:30:33 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 03:04:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// comparer avec la vrai fonction faire une boucle de int min a int max
// certain cas ne son pas similaire !!
int	test_ft_isdigit(void)
{
	printf("--- isdigit\t: ");
	int c = -10;
	while (c != 300)
	{
		if ((isdigit(c) != 0) != (ft_isdigit(c) != 0))
			return (printf("Error!!! with %c %d, | %d %d\n", (c), c, isdigit(c), ft_isdigit(c)), 1);
		c++;
	}
	printf("\t✅\n");
	return (0);
}