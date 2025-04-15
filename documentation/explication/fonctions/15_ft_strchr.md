# ft\_strchr - Recherche d'un caractère dans une chaîne

- [ft\_strchr - Recherche d'un caractère dans une chaîne](#ft_strchr---recherche-dun-caractère-dans-une-chaîne)
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
char *ft_strchr(const char *s, int c);
```

## Description

La fonction `ft_strchr` localise la première occurrence du caractère `c` (converti en `char`) dans la chaîne de caractères `s`. Le caractère nul de fin est considéré comme faisant partie de la chaîne.

## Valeur de retour

  - Retourne un pointeur vers la première occurrence du caractère `c` dans `s`.
  - Retourne `NULL` si le caractère `c` n'est pas trouvé dans `s`.

## Comportement

  - La fonction parcourt la chaîne `s` jusqu'à trouver le caractère `c` ou le caractère nul de fin.
  - Si `c` est le caractère nul, la fonction retourne un pointeur vers le caractère nul de fin de `s`.
  - La fonction ne modifie pas la chaîne d'origine (paramètre `const`).

## Cas limites à tester

```c
NULL, "", "abc", "a\\0bc", "long string...", 'a', 'b', 'c', '\\0'
```

## Pièges à éviter

1.  **Ne pas oublier le caractère nul** : Le caractère nul de fin doit être inclus dans la recherche.
2.  **Ne pas modifier la chaîne d'origine** : Le paramètre est `const`, donc la chaîne ne doit pas être modifiée.
3.  **Gérer les pointeurs nuls (si nécessaire)** : Si votre contexte le permet, il peut être utile de gérer les pointeurs nuls.

## Différences avec la version standard

  - La version standard est définie dans `<string.h>`.
  - Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char str[] = "Hello World";
char *ptr = ft_strchr(str, 'W');
if (ptr != NULL) {
    printf("'%c' trouvé à partir de '%s'\n", 'W', ptr);
}
```

## Voir aussi

  - [strchr(3) - Linux man page](https://man7.org/linux/man-pages/man3/strchr.3.html)
  - `ft_strrchr`, `ft_strstr`, `ft_strcspn` - Fonctions de manipulation de chaînes
