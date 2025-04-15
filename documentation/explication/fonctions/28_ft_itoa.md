# ft_itoa - Conversion d'un entier en chaîne de caractères

- [ft\_itoa - Conversion d'un entier en chaîne de caractères](#ft_itoa---conversion-dun-entier-en-chaîne-de-caractères)
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
char *ft_itoa(int n);
```

## Description

La fonction `ft_itoa` alloue (avec `malloc(3)`) et retourne une chaîne de caractères représentant l'entier `n` passé en argument. Les nombres négatifs doivent être gérés.

## Paramètres

* `n` : L'entier à convertir en chaîne de caractères.

## Valeur de retour

* Retourne la chaîne de caractères représentant l'entier `n`.
* Retourne `NULL` si l'allocation échoue.

## Comportement

* La fonction alloue de la mémoire pour une nouvelle chaîne de caractères, suffisamment grande pour contenir la représentation textuelle de l'entier `n`, plus le caractère nul de fin.
* Si `n` est égal à `INT_MIN`, la fonction doit gérer ce cas particulier.
* La mémoire allouée doit être libérée avec `free(3)` lorsque celle-ci n'est plus nécessaire.

## Cas limites à tester

* `n` est égal à `0`.
* `n` est égal à `INT_MIN`.
* `n` est égal à `INT_MAX`.
* `n` est un nombre négatif.
* `n` est un nombre positif.
* Allocation de mémoire réussie.
* Allocation de mémoire échouée.

## Pièges à éviter

* Ne pas oublier de gérer le cas où `n` est égal à `INT_MIN`.
* Ne pas oublier de terminer la nouvelle chaîne par un caractère nul (`\0`).
* Ne pas oublier de libérer la mémoire allouée avec `free(3)` lorsque celle-ci n'est plus nécessaire.
* Gérer correctement les cas où `n` est égal à `0`.

## Exemple d'utilisation

```c
#include <stdio.h>

int main(void)
{
    int n = -12345;
    char *str = ft_itoa(n);

    if (str) {
        printf("Chaîne convertie: %s\n", str);
        free(str);
    }
    return (0);
}
```

## Voir aussi

* `malloc(3)`
* `free(3)`
