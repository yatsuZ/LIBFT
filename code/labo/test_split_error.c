#include <stdlib.h>
#include <stdio.h>
#include "./../LIBFT/libft.h"

void	free_split(char ***res)
{
	if (!res || (*res) == NULL)
		return ;
	int i = 0;
	while ((*res) && (*res)[i])
	{
		printf("%d\t= \"%s\"\n", i, (*res)[i]);
		free((*res)[i]);
		(*res)[i++] = NULL;
	}
	free((*res));
	(*res) = NULL;
}

int main(void)
{
	char **res = ft_split("1_a 2_b 3_cdzef 4_szefez  5_fgrefvc,eirnvoubezufvb 6_mvk 7_sojvo 8_eohrf    9_kzfbvihzr   10_fv 11_iyfbziuref      12_oiboicbd                       13   ", ' ');
	int i = 0;
	if (!res)
		printf("res == NULL il y a eu un probleme.\n");
	while (res && res[i])
	{
		printf("%d\t= \"%s\"\n", i, res[i]);
		i++;
	}
	printf("-----------------------------------\n");
	free_split(&res);
	return (0);
}
// modifio split. pour qu'un partir dun certain moment substr renvoye null
// $> cc test_split_error.c -L./../LIBFT -lft -I./../LIBFT && valgrind ./a.out

// (*res)[i] = ft_substr(s, start, end - start);
// Modifier cette ligne dans ft_split.c pour modifie le condition

// et faut make LIBFT