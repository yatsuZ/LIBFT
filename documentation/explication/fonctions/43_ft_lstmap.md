# ft_lstiter - Application d'une fonction à chaque élément d'une liste chaînée

- [ft\_lstiter - Application d'une fonction à chaque élément d'une liste chaînée](#ft_lstiter---application-dune-fonction-à-chaque-élément-dune-liste-chaînée)
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
void ft_lstiter(t_list *lst, void (*f)(void *));
```

## Description

La fonction `ft_lstiter` itère sur la liste chaînée `lst` et applique la fonction `f` au contenu de chaque élément.

## Paramètres

* `lst` : Le pointeur vers le premier élément de la liste chaînée.
* `f` : Le pointeur vers la fonction à appliquer au contenu de chaque élément.

## Valeur de retour

Aucune.

## Comportement

* La fonction parcourt la liste chaînée `lst` et applique la fonction `f` au contenu de chaque élément.
* Si `lst` est `NULL` ou `f` est `NULL`, la fonction ne fait rien.
* La fonction ne retourne aucune valeur.

## Cas limites à tester

* `lst` est `NULL`.
* `f` est `NULL`.
* `lst` pointe vers une liste vide.
* `lst` pointe vers une liste avec un seul élément.
* `lst` pointe vers une liste avec plusieurs éléments.
* `f` est une fonction valide qui modifie le contenu des éléments.

## Pièges à éviter

* Ne pas oublier de gérer le cas où `lst` ou `f` sont `NULL`.
* Ne pas modifier la liste chaînée pendant l'itération, sauf si cela est intentionnel.
* S'assurer que la fonction `f` ne provoque pas d'erreurs.

## Exemple d'utilisation

```c
#include <stdio.h>
#include "libft.h"

void print_content(void *content)
{
    printf("Contenu: %d\n", *(int *)content);
}

int main(void)
{
    t_list *list = NULL;
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;

    ft_lstadd_back(&list, ft_lstnew(&data1));
    ft_lstadd_back(&list, ft_lstnew(&data2));
    ft_lstadd_back(&list, ft_lstnew(&data3));

    ft_lstiter(list, print_content);

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
* `ft_lstadd_back(3)`
