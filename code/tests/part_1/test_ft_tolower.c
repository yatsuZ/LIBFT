/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:02:58 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 00:03:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// comparer avec la vrai fonction faire une boucle de -10 a 255
// certain cas ne son pas similaire !!
int	test_ft_tolower(void)
{
	printf("--- tolower\t: ");
	int c = -10;
	while (c != 255)
	{
		if (tolower(c) != ft_tolower(c))
			return (printf("Error!!! with %c %d, | %d %d\n", (c), c, tolower(c), ft_tolower(c)), 1);
		c++;
	}
	printf("\t✅\n");
	return (0);
}