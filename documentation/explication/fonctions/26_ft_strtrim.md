# ft_strtrim - Suppression des caractères spécifiés en début et fin de chaîne

- [ft\_strtrim - Suppression des caractères spécifiés en début et fin de chaîne](#ft_strtrim---suppression-des-caractères-spécifiés-en-début-et-fin-de-chaîne)
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
char *ft_strtrim(char const *s1, char const *set);
```

## Description

La fonction `ft_strtrim` alloue (avec `malloc(3)`) et retourne une copie de la chaîne `s1`, dans laquelle les caractères spécifiés dans la chaîne `set` sont supprimés du début et de la fin de la chaîne.

## Paramètres

* `s1` : La chaîne de caractères à trimmer.
* `set` : La chaîne de caractères contenant les caractères à supprimer du début et de la fin de `s1`.

## Valeur de retour

* Retourne une nouvelle chaîne de caractères, copie de `s1` sans les caractères spécifiés dans `set` en début et fin de chaîne.
* Retourne `NULL` si l'allocation de mémoire échoue.

## Comportement

* La fonction alloue de la mémoire pour une nouvelle chaîne de caractères, suffisamment grande pour contenir la copie de `s1` après suppression des caractères spécifiés dans `set`.
* Si `s1` ou `set` sont `NULL`, le comportement de la fonction est indéfini.
* Si `s1` ne contient que des caractères spécifiés dans `set`, la fonction retourne une chaîne vide.
* La mémoire allouée doit être libérée avec `free(3)` lorsque celle-ci n'est plus nécessaire.

## Cas limites à tester

* `s1` est `NULL`.
* `set` est `NULL`.
* `s1` est une chaîne vide.
* `set` est une chaîne vide.
* `s1` ne contient que des caractères spécifiés dans `set`.
* `set` contient tous les caractères de `s1`.
* `s1` est une chaîne très longue.
* `set` est une chaîne très longue.
* Allocation de mémoire réussie.
* Allocation de mémoire échouée.

## Pièges à éviter

* Ne pas oublier de gérer le cas où `s1` ou `set` sont `NULL`.
* Ne pas oublier de terminer la nouvelle chaîne par un caractère nul (`\0`).
* Ne pas oublier de libérer la mémoire allouée avec `free(3)` lorsque celle-ci n'est plus nécessaire.
* Gérer correctement les cas où `s1` ne contient que des caractères spécifiés dans `set`.

## Exemple d'utilisation

```c
#include <stdio.h>

int main(void)
{
    char *s1 = "   Hello, world!   ";
    char *set = " ";
    char *trim = ft_strtrim(s1, set);

    if (trim) {
        printf("Chaîne trimmée: %s\n", trim);
        free(trim);
    }
    return (0);
}
```

## Voir aussi

* `malloc(3)`
* `free(3)`
* `ft_strlen(3)`
* `ft_memcpy(3)`
* `ft_strchr(3)`