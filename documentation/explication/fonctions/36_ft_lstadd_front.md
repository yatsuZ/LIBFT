# ft_lstadd_front - Ajout d'un élément en tête de liste chaînée

- [ft\_lstadd\_front - Ajout d'un élément en tête de liste chaînée](#ft_lstadd_front---ajout-dun-élément-en-tête-de-liste-chaînée)
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
void ft_lstadd_front(t_list **lst, t_list *new);
```

## Description

La fonction `ft_lstadd_front` ajoute l'élément `new` au début de la liste chaînée pointée par `lst`.

## Paramètres

* `lst` : L'adresse du pointeur vers le premier élément de la liste.
* `new` : L'adresse du pointeur vers l'élément à ajouter à la liste.

## Valeur de retour

Aucune.

## Comportement

* La fonction ajoute l'élément `new` au début de la liste chaînée pointée par `lst`.
* Si `lst` est `NULL`, le comportement de la fonction est indéfini.
* Si `new` est `NULL`, la liste n'est pas modifiée.
* La fonction ne retourne aucune valeur.

## Cas limites à tester

* `lst` est `NULL`.
* `new` est `NULL`.
* `lst` pointe vers une liste vide.
* `lst` pointe vers une liste non vide.
* `new` est un élément valide.

## Pièges à éviter

* Ne pas oublier de gérer le cas où `lst` est `NULL`.
* Ne pas modifier la liste si `new` est `NULL`.
* Ne pas oublier de mettre à jour le pointeur `lst` pour qu'il pointe vers le nouvel élément en tête de liste.

## Exemple d'utilisation

```c
#include <stdio.h>
#include "libft.h"

int main(void)
{
    t_list *list = NULL;
    int data1 = 1;
    int data2 = 2;

    t_list *new_element1 = ft_lstnew(&data1);
    t_list *new_element2 = ft_lstnew(&data2);

    ft_lstadd_front(&list, new_element1);
    ft_lstadd_front(&list, new_element2);

    // La liste contient maintenant new_element2 -> new_element1 -> NULL

    // ...

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
