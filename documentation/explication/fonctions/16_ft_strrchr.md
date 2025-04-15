# ft\_strrchr - Recherche de la dernière occurrence d'un caractère dans une chaîne

- [ft\_strrchr - Recherche de la dernière occurrence d'un caractère dans une chaîne](#ft_strrchr---recherche-de-la-dernière-occurrence-dun-caractère-dans-une-chaîne)
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
char *ft_strrchr(const char *s, int c);
```

## Description

La fonction `ft_strrchr` localise la dernière occurrence du caractère `c` (converti en `char`) dans la chaîne de caractères `s`. Le caractère nul de fin est considéré comme faisant partie de la chaîne.

## Valeur de retour

  - Retourne un pointeur vers la dernière occurrence du caractère `c` dans `s`.
  - Retourne `NULL` si le caractère `c` n'est pas trouvé dans `s`.

## Comportement

  - La fonction parcourt la chaîne `s` de la fin vers le début, jusqu'à trouver le caractère `c` ou le début de la chaîne.
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
4. **Parcourir la chaine de la fin vers le debut**: ou garder en memoire le dernier endroit ou le caractère a été trouvé.

## Différences avec la version standard

  - La version standard est définie dans `<string.h>`.
  - Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char str[] = "Hello World Hello";
char *ptr = ft_strrchr(str, 'l');
if (ptr != NULL) {
    printf("Dernière occurrence de '%c' trouvée à partir de '%s'\n", 'l', ptr);
}
```

## Voir aussi

  - [strrchr(3) - Linux man page](https://man7.org/linux/man-pages/man3/strrchr.3.html)
  - `ft_strchr`, `ft_strstr`, `ft_strcspn` - Fonctions de manipulation de chaînes
