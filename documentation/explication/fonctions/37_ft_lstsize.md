# ft_lstsize - Calcul de la taille d'une liste chaînée

- [ft\_lstsize - Calcul de la taille d'une liste chaînée](#ft_lstsize---calcul-de-la-taille-dune-liste-chaînée)
	- [Exemple d'utilisation](#exemple-dutilisation)
	- [Voir aussi](#voir-aussi)

## Exemple d'utilisation

```c
#include <stdio.h>
#include "libft.h"

int main(void)
{
    t_list *list = NULL;
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;

    ft_lstadd_front(&list, ft_lstnew(&data1));
    ft_lstadd_front(&list, ft_lstnew(&data2));
    ft_lstadd_front(&list, ft_lstnew(&data3));

    int size = ft_lstsize(list);
    printf("Taille de la liste: %d\n", size); // Affiche "Taille de la liste: 3"

    // Libération de la mémoire
    t_list *current = list;
    while (current) {
        t_list *next = current->next;
        free(current);
        current = next;
    }

    return (0);
}
```

## Voir aussi

* `ft_lstnew(3)`
* `ft_lstadd_front(3)`
