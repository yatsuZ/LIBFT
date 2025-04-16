#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	void	*t;

	t = malloc(0);
	printf("adresse de t malloc(0) = %p\n", t);
	if (t == NULL)
		printf("le pointeur t est quivalent a NULL \n");
	else
	{// JE n'ai pas le droit decrire
		((char *)t)[0] = 'R';
		printf("t[0] = %c \n", *((char *)t));

	}
	free(t);
	return (0);
}
// $> cc test_malloc_0.c && ./aout