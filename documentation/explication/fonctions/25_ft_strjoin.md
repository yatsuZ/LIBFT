# ft_strjoin - Concaténation de deux chaînes de caractères

- [ft\_strjoin - Concaténation de deux chaînes de caractères](#ft_strjoin---concaténation-de-deux-chaînes-de-caractères)
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
char *ft_strjoin(char const *s1, char const *s2);
```

## Description

La fonction `ft_strjoin` alloue (avec `malloc(3)`) et retourne une nouvelle chaîne de caractères, résultat de la concaténation des chaînes `s1` et `s2`.

## Paramètres

* `s1` : La chaîne de caractères préfixe.
* `s2` : La chaîne de caractères suffixe.

## Valeur de retour

* Retourne la nouvelle chaîne de caractères résultant de la concaténation de `s1` et `s2`.
* Retourne `NULL` si l'allocation de mémoire échoue.

## Comportement

* La fonction alloue de la mémoire pour une nouvelle chaîne de caractères, suffisamment grande pour contenir la concaténation de `s1` et `s2`, plus le caractère nul de fin.
* Si `s1` ou `s2` sont `NULL`, le comportement de la fonction est indéfini.
* La mémoire allouée doit être libérée avec `free(3)` lorsque celle-ci n'est plus nécessaire.

## Cas limites à tester

* `s1` est `NULL`.
* `s2` est `NULL`.
* `s1` et `s2` sont des chaînes vides.
* `s1` ou `s2` sont des chaînes très longues.
* Allocation de mémoire réussie.
* Allocation de mémoire échouée.

## Pièges à éviter

* Ne pas oublier de gérer le cas où `s1` ou `s2` sont `NULL`.
* Ne pas oublier de terminer la nouvelle chaîne par un caractère nul (`\0`).
* Ne pas oublier de libérer la mémoire allouée avec `free(3)` lorsque celle-ci n'est plus nécessaire.
* Gérer correctement les cas où `s1` ou `s2` sont des chaînes vides.

## Exemple d'utilisation

```c
#include <stdio.h>

int main(void)
{
    char *s1 = "Hello, ";
    char *s2 = "world!";
    char *join = ft_strjoin(s1, s2);

    if (join) {
        printf("Chaîne concaténée: %s\n", join);
        free(join);
    }
    return (0);
}
```

## Voir aussi

* `malloc(3)`
* `free(3)`
* `ft_strlen(3)`
* `ft_memcpy(3)`
