/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 02:45:52 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/15 03:04:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// comparer avec la vrai fonction faire une boucle de -10 a 255
// certain cas ne son pas similaire !!
int	test_ft_isprint(void)
{
	printf("--- isprint\t: ");
	int c = -10;
	while (c != 300)
	{
		if ((isprint(c) != 0) != (ft_isprint(c) != 0))
			return (printf("Error!!! with %c %d, | %d %d\n", (c), c, isprint(c), ft_isprint(c)), 1);
		c++;
	}
	printf("\t✅\n");
	return (0);
}