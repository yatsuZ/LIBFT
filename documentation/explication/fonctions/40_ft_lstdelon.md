# ft_lstdelone - Suppression d'un élément de liste chaînée

- [ft\_lstdelone - Suppression d'un élément de liste chaînée](#ft_lstdelone---suppression-dun-élément-de-liste-chaînée)
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
void ft_lstdelone(t_list *lst, void (*del)(void *));
```

## Description

La fonction `ft_lstdelone` libère la mémoire de l'élément `lst` en utilisant la fonction `del` pour supprimer le contenu de l'élément, puis en utilisant `free(3)` pour libérer l'élément lui-même. La mémoire du membre `next` de l'élément n'est pas libérée.

## Paramètres

* `lst` : Le pointeur vers l'élément à libérer.
* `del` : Le pointeur vers la fonction utilisée pour supprimer le contenu de l'élément.

## Valeur de retour

Aucune.

## Comportement

* Si `lst` est `NULL` ou `del` est `NULL`, la fonction ne fait rien.
* La fonction appelle `del` avec le contenu de l'élément `lst` comme argument pour libérer la mémoire du contenu.
* La fonction libère la mémoire de l'élément `lst` lui-même en utilisant `free(3)`.
* La mémoire du membre `next` de l'élément `lst` n'est pas libérée.

## Cas limites à tester

* `lst` est `NULL`.
* `del` est `NULL`.
* `lst` est un élément valide.
* `del` est une fonction valide.

## Pièges à éviter

* Ne pas oublier de vérifier que `lst` et `del` ne sont pas `NULL` avant de les utiliser.
* Ne pas libérer la mémoire du membre `next` de l'élément `lst`.
* S'assurer que la fonction `del` libère correctement la mémoire du contenu de l'élément.

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
    int *data = (int *)malloc(sizeof(int));
    *data = 42;

    t_list *element = ft_lstnew(data);

    ft_lstdelone(element, del_content);

    // element n'existe plus après l'appel à ft_lstdelone

    return (0);
}
```

## Voir aussi

* `free(3)`
* `ft_lstnew(3)`
