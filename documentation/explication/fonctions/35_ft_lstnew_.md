# ft_lstnew - Création d'un nouvel élément de liste chaînée

- [ft\_lstnew - Création d'un nouvel élément de liste chaînée](#ft_lstnew---création-dun-nouvel-élément-de-liste-chaînée)
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
t_list *ft_lstnew(void *content);
```

## Description

La fonction `ft_lstnew` alloue (avec `malloc(3)`) et retourne un nouvel élément de liste chaînée. La variable membre `content` est initialisée avec la valeur du paramètre `content`. La variable membre `next` est initialisée à `NULL`.

## Paramètres

* `content` : Le contenu du nouvel élément.

## Valeur de retour

* Retourne le nouvel élément de liste chaînée.
* Retourne `NULL` si l'allocation échoue.

## Comportement

* La fonction alloue de la mémoire pour un nouvel élément de type `t_list`.
* Le membre `content` du nouvel élément est initialisé avec le pointeur `content` passé en paramètre.
* Le membre `next` du nouvel élément est initialisé à `NULL`.
* Si l'allocation de mémoire échoue, la fonction retourne `NULL`.

## Cas limites à tester

* `content` est `NULL`.
* `content` est un pointeur valide vers une donnée.
* Allocation de mémoire réussie.
* Allocation de mémoire échouée.

## Pièges à éviter

* Ne pas oublier de gérer le cas où l'allocation de mémoire échoue.
* Ne pas oublier d'initialiser le membre `next` à `NULL`.

## Exemple d'utilisation

```c
#include <stdio.h>
#include "libft.h"

int main(void)
{
    int data = 42;
    t_list *new_element = ft_lstnew(&data);

    if (new_element) {
        printf("Nouvel élément créé avec succès.\n");
        // Utilisation de new_element
        // ...
        // Libération de la mémoire
        free(new_element);
    } else {
        printf("Échec de la création du nouvel élément.\n");
    }
    return (0);
}
```

## Voir aussi

* `malloc(3)`
