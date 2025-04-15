# ft_lstsize - Calcul de la taille d'une liste chaînée

- [ft\_lstsize - Calcul de la taille d'une liste chaînée](#ft_lstsize---calcul-de-la-taille-dune-liste-chaînée)
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
int ft_lstsize(t_list *lst);
```

## Description

La fonction `ft_lstsize` calcule et retourne le nombre d'éléments présents dans la liste chaînée `lst`.

## Paramètres

* `lst` : Le pointeur vers le premier élément de la liste chaînée.

## Valeur de retour

* Retourne la taille (le nombre d'éléments) de la liste chaînée.

## Comportement

* La fonction parcourt la liste chaînée en partant du premier élément `lst` jusqu'à la fin de la liste (indiquée par un pointeur `next` à `NULL`).
* Pour chaque élément rencontré, un compteur est incrémenté.
* La fonction retourne la valeur du compteur, qui représente la taille de la liste.
* Si `lst` est `NULL` (liste vide), la fonction retourne `0`.

## Cas limites à tester

* `lst` est `NULL` (liste vide).
* `lst` pointe vers une liste avec un seul élément.
* `lst` pointe vers une liste avec plusieurs éléments.

## Pièges à éviter

* Ne pas oublier de gérer le cas où `lst` est `NULL`.
* Ne pas modifier la liste chaînée pendant le calcul de la taille.

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
