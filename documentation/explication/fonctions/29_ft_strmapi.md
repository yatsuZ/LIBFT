# ft_strmapi - Application d'une fonction à chaque caractère d'une chaîne

- [ft\_strmapi - Application d'une fonction à chaque caractère d'une chaîne](#ft_strmapi---application-dune-fonction-à-chaque-caractère-dune-chaîne)
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
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

## Description

La fonction `ft_strmapi` applique la fonction `f` à chaque caractère de la chaîne `s`, en passant l'indice du caractère comme premier argument et le caractère lui-même comme second argument. Une nouvelle chaîne de caractères est créée (avec `malloc(3)`), résultant des applications successives de `f`.

## Paramètres

* `s` : La chaîne de caractères sur laquelle itérer.
* `f` : La fonction à appliquer à chaque caractère.

## Valeur de retour

* Retourne la chaîne de caractères résultant des applications successives de `f`.
* Retourne `NULL` si l'allocation échoue.

## Comportement

* La fonction alloue de la mémoire pour une nouvelle chaîne de caractères, suffisamment grande pour contenir la chaîne résultant de l'application de `f` à chaque caractère de `s`, plus le caractère nul de fin.
* Si `s` est `NULL`, la fonction retourne `NULL`.
* Si l'allocation de mémoire échoue, la fonction retourne `NULL`.
* La mémoire allouée doit être libérée avec `free(3)` lorsque celle-ci n'est plus nécessaire.

## Cas limites à tester

* `s` est `NULL`.
* `f` est `NULL`.
* `s` est une chaîne vide.
* `s` est une chaîne très longue.
* `f` modifie les caractères de manière prévisible.
* Allocation de mémoire réussie.
* Allocation de mémoire échouée.

## Pièges à éviter

* Ne pas oublier de gérer le cas où `s` ou `f` sont `NULL`.
* Ne pas oublier de terminer la nouvelle chaîne par un caractère nul (`\0`).
* Ne pas oublier de libérer la mémoire allouée avec `free(3)` lorsque celle-ci n'est plus nécessaire.
* Gérer correctement les cas où `s` est une chaîne vide.

## Exemple d'utilisation

```c
#include <stdio.h>

char to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int main(void)
{
    char *s = "hello, world!";
    char *map = ft_strmapi(s, to_upper);

    if (map) {
        printf("Chaîne mappée: %s\n", map);
        free(map);
    }
    return (0);
}
```

## Voir aussi

* `malloc(3)`
* `free(3)`
* `ft_strlen(3)`
