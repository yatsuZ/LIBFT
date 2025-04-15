# ft_lstclear - Suppression et libération de toute une liste chaînée

- [ft\_lstclear - Suppression et libération de toute une liste chaînée](#ft_lstclear---suppression-et-libération-de-toute-une-liste-chaînée)
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
void ft_lstclear(t_list **lst, void (*del)(void *));
```

## Description

La fonction `ft_lstclear` supprime et libère la mémoire de l'élément pointé par `lst` et de tous les éléments suivants de la liste chaînée. Elle utilise la fonction `del` pour supprimer le contenu de chaque élément, puis `free(3)` pour libérer la mémoire de chaque élément lui-même. Enfin, elle met le pointeur initial `lst` à `NULL`.

## Paramètres

* `lst` : L'adresse du pointeur vers le premier élément de la liste chaînée à libérer.
* `del` : Le pointeur vers la fonction utilisée pour supprimer le contenu de chaque élément.

## Valeur de retour

Aucune.

## Comportement

* Si `lst` est `NULL` ou `*lst` est `NULL`, la fonction ne fait rien.
* La fonction parcourt la liste chaînée à partir de l'élément pointé par `lst`, en appelant `del` pour chaque élément afin de libérer la mémoire du contenu, puis en libérant la mémoire de l'élément lui-même avec `free(3)`.
* Après avoir libéré tous les éléments, la fonction met le pointeur `lst` à `NULL`.

## Cas limites à tester

* `lst` est `NULL`.
* `*lst` est `NULL` (liste vide).
* `del` est `NULL`.
* `lst` pointe vers une liste avec un seul élément.
* `lst` pointe vers une liste avec plusieurs éléments.

## Pièges à éviter

* Ne pas oublier de vérifier que `lst` et `*lst` ne sont pas `NULL` avant de les utiliser.
* Ne pas oublier de mettre le pointeur `lst` à `NULL` après avoir libéré tous les éléments.
* S'assurer que la fonction `del` libère correctement la mémoire du contenu de chaque élément.

## Exemple d'utilisation

```c
#include <stdio.h>
#include "libft.h"

void del_content(void *content)
{
    free(content);
}

int main(void)
{
    t_list *list = NULL;
    int *data1 = (int *)malloc(sizeof(int));
    *data1 = 1;
    int *data2 = (int *)malloc(sizeof(int));
    *data2 = 2;
    int *data3 = (int *)malloc(sizeof(int));
    *data3 = 3;

    ft_lstadd_back(&list, ft_lstnew(data1));
    ft_lstadd_back(&list, ft_lstnew(data2));
    ft_lstadd_back(&list, ft_lstnew(data3));

    ft_lstclear(&list, del_content);

    // list est maintenant NULL

    return (0);
}
```

## Voir aussi

* `free(3)`
* `ft_lstnew(3)`
* `ft_lstadd_back(3)`
* `ft_lstdelone(3)`
