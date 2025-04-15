# ft_lstlast - Récupération du dernier élément d'une liste chaînée

- [ft\_lstlast - Récupération du dernier élément d'une liste chaînée](#ft_lstlast---récupération-du-dernier-élément-dune-liste-chaînée)
	- [Prototype](#prototype)
	- [Description](#description)
	- [Paramètres](#paramètres)
	- [Valeur de retour](#valeur-de-retour)
	- [Comportement](#comportement)
	- [Cas limites à tester](#cas-limites-à-tester)
	- [Pièges à éviter](#pièges-à-éviter)
	- [Exemple d'utilisation](#exemple-dutilisation)
	- [Voir aussi](#voir-aussi)

## Prototype

```c
t_list *ft_lstlast(t_list *lst);
```

## Description

La fonction `ft_lstlast` retourne le dernier élément de la liste chaînée `lst`.

## Paramètres

* `lst` : Le pointeur vers le premier élément de la liste chaînée.

## Valeur de retour

* Retourne le dernier élément de la liste chaînée.
* Retourne `NULL` si la liste est vide (`lst` est `NULL`).

## Comportement

* La fonction parcourt la liste chaînée à partir du premier élément `lst` jusqu'à atteindre le dernier élément, qui est celui dont le pointeur `next` est `NULL`.
* Si la liste est vide (`lst` est `NULL`), la fonction retourne `NULL`.

## Cas limites à tester

* `lst` est `NULL` (liste vide).
* `lst` pointe vers une liste avec un seul élément.
* `lst` pointe vers une liste avec plusieurs éléments.

## Pièges à éviter

* Ne pas oublier de gérer le cas où `lst` est `NULL`.
* Ne pas modifier la liste chaînée pendant la recherche du dernier élément.

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

    t_list *last = ft_lstlast(list);
    if (last) {
        printf("Dernier élément: %p\n", last);
    } else {
        printf("Liste vide.\n");
    }

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
