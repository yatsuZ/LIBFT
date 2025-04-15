/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:50:45 by yzaoui            #+#    #+#             */
/*   Updated: 2025/04/16 00:04:28 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libft_tester.h"

// comparer avec la vrai fonction faire une boucle de -10 a 255
// certain cas ne son pas similaire !!
int	test_ft_toupper(void)
{
	printf("--- toupper\t: ");
	int c = -10;
	while (c != 255)
	{
		if (toupper(c) != ft_toupper(c))
			return (printf("Error!!! with %c %d, | %d %d\n", (c), c, toupper(c), ft_toupper(c)), 1);
		c++;
	}
	printf("\t✅\n");
	return (0);
}