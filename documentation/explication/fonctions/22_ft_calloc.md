# ft_calloc - Allocation de mémoire et initialisation à zéro

- [ft\_calloc - Allocation de mémoire et initialisation à zéro](#ft_calloc---allocation-de-mémoire-et-initialisation-à-zéro)
	- [Prototype](#prototype)
	- [Description](#description)
	- [Valeur de retour](#valeur-de-retour)
	- [Comportement](#comportement)
	- [Cas limites à tester](#cas-limites-à-tester)
	- [Pièges à éviter](#pièges-à-éviter)
	- [Différences avec la version standard](#différences-avec-la-version-standard)
	- [Exemple d'utilisation](#exemple-dutilisation)
	- [Voir aussi](#voir-aussi)

## Prototype

```c
void *ft_calloc(size_t count, size_t size);
```

## Description

La fonction `ft_calloc` alloue de la mémoire pour un tableau de `count` éléments, chacun de taille `size` octets. La mémoire allouée est initialisée à zéro.

## Valeur de retour

-   Retourne un pointeur vers la mémoire allouée.
-   Retourne `NULL` si l'allocation échoue ou si `count` ou `size` vaut zéro.

## Comportement

-   La fonction alloue de la mémoire pour un tableau de `count` éléments, chacun de taille `size` octets.
-   La mémoire allouée est initialisée à zéro.
-   Si `count` ou `size` vaut zéro, la fonction retourne `NULL` ou un pointeur valide vers une zone mémoire de taille zéro.

## Cas limites à tester

-   `count` = 0
-   `size` = 0
-   `count` et `size` très grands (pour tester les dépassements de capacité)
-   Allocation de mémoire réussie
-   Allocation de mémoire échouée

## Pièges à éviter

-   Ne pas oublier de gérer les cas où `count` ou `size` vaut zéro.
-   Ne pas oublier de gérer les dépassements de capacité.
-   Ne pas oublier d'initialiser la mémoire à zéro.
-   Ne pas oublier de libérer la mémoire allouée avec `free` lorsque celle-ci n'est plus nécessaire.

## Différences avec la version standard

-   La version standard est définie dans `<stdlib.h>`.
-   Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
int *arr = (int *)ft_calloc(10, sizeof(int));
if (arr) {
    // Utilisation de arr
    free(arr);
}
```

## Voir aussi

-   `calloc(3)` - Linux man page : [https://man7.org/linux/man-pages/man3/calloc.3.html](https://man7.org/linux/man-pages/man3/calloc.3.html)
-   `malloc(3)`
-   `free(3)`
-   `ft_bzero(3)`
