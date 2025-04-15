# ft_strdup - Duplication d'une chaîne de caractères

- [ft\_strdup - Duplication d'une chaîne de caractères](#ft_strdup---duplication-dune-chaîne-de-caractères)
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
char *ft_strdup(const char *s1);
```

## Description

La fonction `ft_strdup` alloue de la mémoire pour une nouvelle chaîne de caractères, qui est une copie de la chaîne `s1`. La mémoire allouée doit être libérée avec `free`.

## Valeur de retour

-   Retourne un pointeur vers la chaîne dupliquée.
-   Retourne `NULL` si l'allocation de mémoire échoue.

## Comportement

-   La fonction alloue de la mémoire pour une nouvelle chaîne de caractères, qui est une copie de la chaîne `s1`.
-   La nouvelle chaîne de caractères est terminée par un caractère nul (`\0`).
-   Si `s1` est `NULL`, le comportement de la fonction est indéfini.
-   Si l'allocation de mémoire échoue, la fonction retourne `NULL`.

## Cas limites à tester

-   `s1` = `NULL`
-   `s1` = `""` (chaîne vide)
-   `s1` = une chaîne de caractères normale
-   `s1` = une très longue chaîne de caractères
-   Allocation de mémoire réussie
-   Allocation de mémoire échouée

## Pièges à éviter

-   Ne pas oublier de gérer le cas où `s1` est `NULL`.
-   Ne pas oublier de terminer la nouvelle chaîne de caractères par un caractère nul (`\0`).
-   Ne pas oublier de libérer la mémoire allouée avec `free` lorsque celle-ci n'est plus nécessaire.
-   Ne pas oublier de vérifier si malloc a reussi.

## Différences avec la version standard

-   La version standard est définie dans `<string.h>`.
-   Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char *str = "Hello, world!";
char *dup = ft_strdup(str);

if (dup) {
    printf("Duplicated string: %s\n", dup);
    free(dup);
}
```

## Voir aussi

-   `strdup(3)` - Linux man page : [https://man7.org/linux/man-pages/man3/strdup.3.html](https://man7.org/linux/man-pages/man3/strdup.3.html)
-   `malloc(3)`
-   `free(3)`
-   `ft_strlen(3)`
-   `ft_memcpy(3)`