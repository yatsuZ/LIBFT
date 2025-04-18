# Fonction : ft_lstmap

- [Fonction : ft\_lstmap](#fonction--ft_lstmap)
	- [Prototype](#prototype)
	- [Valeur de retour](#valeur-de-retour)
	- [Paramètres](#paramètres)
	- [Fonctions externes autorisées](#fonctions-externes-autorisées)
	- [Description](#description)
	- [Comportement](#comportement)
	- [Exemple d'utilisation](#exemple-dutilisation)
	- [Voir aussi](#voir-aussi)

## Prototype

```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

## Valeur de retour

* La nouvelle liste.
* `NULL` si l'allocation échoue.

## Paramètres

* `lst` : L'adresse du pointeur vers un élément.
* `f` : L'adresse de la fonction à appliquer au contenu de chaque élément. Cette fonction prend un `void *` en entrée (le contenu d'un élément de liste) et retourne un `void *` (le nouveau contenu).
* `del` : L'adresse de la fonction permettant de supprimer le contenu d'un élément si nécessaire. Cette fonction prend un `void *` en entrée (le contenu à supprimer) et ne retourne rien (`void`).

## Fonctions externes autorisées

* `malloc`
* `free`

## Description

La fonction `ft_lstmap` itère sur la liste chaînée `lst` et applique la fonction `f` au contenu de chaque élément. Elle crée une nouvelle liste résultant des applications successives de `f`.

La fonction `del` est fournie pour gérer la désallocation du contenu d'un élément de liste en cas d'échec d'allocation pendant le processus de mapping. Si `malloc` échoue à un moment quelconque lors de la création d'un nouvel élément pour la liste résultante, la fonction doit libérer tous les éléments nouvellement créés jusqu'à présent (y compris leur contenu, si alloué par `f`) en utilisant la fonction `del` avant de retourner `NULL`.

La liste originale `lst` n'est pas modifiée par cette fonction.

## Comportement

1.  Parcourir chaque élément de la liste d'entrée `lst`.
2.  Pour chaque élément, appliquer la fonction `f` à son `content`. La valeur de retour de `f` sera le `content` du nouvel élément dans la liste résultante.
3.  Allouer un nouvel élément `t_list` en utilisant `malloc` pour stocker ce nouveau contenu.
4.  Si `malloc` échoue, libérer le contenu nouvellement créé (en utilisant `del` si `f` a alloué de la mémoire) et tous les éléments précédemment créés dans la nouvelle liste, puis retourner `NULL`.
5.  Définir le `content` du nouvel élément avec le résultat de `f`.
6.  Définir le pointeur `next` du nouvel élément à `NULL` initialement.
7.  Lier l'élément nouvellement créé à la fin de la nouvelle liste en cours de construction.
8.  Après avoir parcouru tous les éléments de `lst`, retourner le pointeur vers le premier élément de la nouvelle liste créée.
9.  Si la liste d'entrée `lst` est `NULL`, la fonction doit retourner `NULL` (ou une liste vide, selon le comportement souhaité).

## Exemple d'utilisation

```c
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// Exemple de fonction à appliquer : multiplier le contenu par 2
void *multiply_by_two(void *content) {
    int *num = (int *)content;
    int *new_num = malloc(sizeof(int));
    if (new_num) {
        *new_num = *num * 2;
    }
    return (void *)new_num;
}

// Exemple de fonction de suppression pour le contenu entier
void delete_int_content(void *content) {
    free(content);
}

int main(void) {
    t_list *head = ft_lstnew(malloc(sizeof(int)));
    if (head && head->content)
        *(int *)(head->content) = 1;
    ft_lstadd_back(&head, ft_lstnew(malloc(sizeof(int))));
    if (head->next && head->next->content)
        *(int *)(head->next->content) = 2;
    ft_lstadd_back(&head, ft_lstnew(malloc(sizeof(int))));
    if (head->next->next && head->next->next->content)
        *(int *)(head->next->next->content) = 3;

    t_list *new_list = ft_lstmap(head, multiply_by_two, delete_int_content);

    if (new_list) {
        t_list *current = new_list;
        while (current) {
            printf("%d\n", *(int *)(current->content));
            current = current->next;
        }

        // Libérer la nouvelle liste
        ft_lstclear(&new_list, delete_int_content);
    }

    // Libérer la liste originale
    ft_lstclear(&head, free);

    return (0);
}
```

## Voir aussi

* `ft_lstnew`
* `ft_lstadd_back`
* `ft_lstclear`
* `malloc(3)`
* `free(3)`