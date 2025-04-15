# ft_split - Découpage d'une chaîne de caractères en tableau de chaînes

- [ft\_split - Découpage d'une chaîne de caractères en tableau de chaînes](#ft_split---découpage-dune-chaîne-de-caractères-en-tableau-de-chaînes)
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
char **ft_split(char const *s, char c);
```

## Description

La fonction `ft_split` alloue (avec `malloc(3)`) et retourne un tableau de chaînes de caractères obtenu en séparant la chaîne `s` à l'aide du caractère `c`, utilisé comme délimiteur. Le tableau doit être terminé par `NULL`.

## Paramètres

* `s` : La chaîne de caractères à découper.
* `c` : Le caractère délimiteur.

## Valeur de retour

* Retourne un tableau de chaînes de caractères résultant du découpage de `s`.
* Retourne `NULL` si l'allocation échoue.

## Comportement

* La fonction alloue de la mémoire pour un tableau de chaînes de caractères, chaque chaîne représentant une sous-chaîne de `s` délimitée par le caractère `c`.
* Si `s` est `NULL`, la fonction retourne `NULL`.
* Si `s` est une chaîne vide ou ne contient que des délimiteurs, la fonction retourne un tableau contenant uniquement `NULL`.
* La mémoire allouée pour le tableau et les chaînes doit être libérée avec `free(3)` lorsque celle-ci n'est plus nécessaire.

## Cas limites à tester

* `s` est `NULL`.
* `s` est une chaîne vide.
* `s` ne contient que des délimiteurs.
* `c` est le caractère nul (`\0`).
* `s` contient plusieurs délimiteurs consécutifs.
* `s` se termine par un délimiteur.
* Allocation de mémoire réussie.
* Allocation de mémoire échouée.

## Pièges à éviter

* Ne pas oublier de gérer le cas où `s` est `NULL`.
* Ne pas oublier de terminer le tableau par `NULL`.
* Ne pas oublier de libérer la mémoire allouée avec `free(3)` lorsque celle-ci n'est plus nécessaire.
* Gérer correctement les cas où `s` est une chaîne vide ou ne contient que des délimiteurs.
* Gérer correctement les cas où l'allocation de mémoire échoue.

## Exemple d'utilisation

```c
#include <stdio.h>

int main(void)
{
    char *s = "  Hello, world!  ";
    char c = ' ';
    char **split = ft_split(s, c);

    if (split) {
        for (int i = 0; split[i]; i++) {
            printf("split[%d]: %s\n", i, split[i]);
            free(split[i]);
        }
        free(split);
    }
    return (0);
}
```

## Voir aussi

* `malloc(3)`
* `free(3)`
* `ft_strlen(3)`
* `ft_memcpy(3)`