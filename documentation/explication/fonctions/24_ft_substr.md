# ft_substr - Extraction d'une sous-chaîne

- [ft\_substr - Extraction d'une sous-chaîne](#ft_substr---extraction-dune-sous-chaîne)
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
char *ft_substr(char const *s, unsigned int start, size_t len);
```

## Description

La fonction `ft_substr` alloue (avec `malloc(3)`) et retourne une nouvelle chaîne de caractères, qui est une sous-chaîne de la chaîne `s`. La sous-chaîne commence à l'index `start` et a une longueur maximale de `len`.

## Paramètres

* `s` : La chaîne de caractères à partir de laquelle la sous-chaîne sera extraite.
* `start` : L'index de début de la sous-chaîne dans `s`.
* `len` : La longueur maximale de la sous-chaîne à extraire.

## Valeur de retour

* Retourne la nouvelle chaîne de caractères extraite de `s`.
* Retourne `NULL` si l'allocation de mémoire échoue.

## Comportement

* Si `start` est supérieur ou égal à la longueur de `s`, une chaîne vide est retournée.
* Si `len` est supérieur à la longueur de `s` à partir de `start`, la sous-chaîne retournée sera limitée à la longueur restante de `s`.
* La mémoire allouée pour la nouvelle chaîne doit être libérée avec `free(3)` lorsque celle-ci n'est plus nécessaire.

## Cas limites à tester

* `s` est `NULL`.
* `start` est supérieur ou égal à la longueur de `s`.
* `len` est supérieur à la longueur de `s` à partir de `start`.
* `s` est une chaîne vide.
* `len` est 0.

## Pièges à éviter

* Ne pas oublier de gérer le cas où `s` est `NULL`.
* Ne pas oublier de terminer la nouvelle chaîne par un caractère nul (`\0`).
* Ne pas oublier de libérer la mémoire allouée avec `free(3)` lorsque celle-ci n'est plus nécessaire.
* Gérer les cas où `start` est hors des limites de `s`.
* Gérer les cas où `len` est plus grand que la longueur restante de `s`.

## Exemple d'utilisation

```c
#include <stdio.h>

int main(void)
{
    char *s = "Hello, world!";
    char *sub = ft_substr(s, 7, 5);

    if (sub) {
        printf("Sous-chaîne: %s\n", sub);
        free(sub);
    }
    return (0);
}
```

## Voir aussi

* `malloc(3)`
* `free(3)`
* `ft_strlen(3)`
* `ft_memcpy(3)`
* `ft_strdup(3)`
* [`https://www.man7.org/linux/man-pages//man3/function::substr.3stap.html`](https://www.man7.org/linux/man-pages//man3/function::substr.3stap.html)