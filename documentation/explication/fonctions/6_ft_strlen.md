# ft\_strlen - Calcul de la longueur d'une chaîne

- [ft\_strlen - Calcul de la longueur d'une chaîne](#ft_strlen---calcul-de-la-longueur-dune-chaîne)
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
size_t ft_strlen(const char *s);
```

## Description

La fonction `ft_strlen` calcule la longueur de la chaîne de caractères `s`, sans compter le caractère nul de fin ('\\0').

## Valeur de retour

  - Retourne le nombre de caractères dans la chaîne `s` (type `size_t`).

## Comportement

  - La fonction parcourt la chaîne jusqu'à rencontrer le caractère nul de fin.
  - Elle ne modifie pas la chaîne d'origine (paramètre `const`).
  - Elle gère correctement les chaînes vides (retourne 0).

## Cas limites à tester

```c
"", "abc", "a\\0bc", "long string...", NULL (si applicable dans votre contexte)
```

## Pièges à éviter

1.  **Ne pas oublier le caractère nul** : La boucle doit s'arrêter au caractère nul.
2.  **Ne pas modifier la chaîne d'origine** : Le paramètre est `const`, donc la chaîne ne doit pas être modifiée.
3.  **Gérer les pointeurs nuls (si nécessaire)** : Si votre contexte le permet, il peut être utile de gérer les pointeurs nuls.

## Différences avec la version standard

  - La version standard est définie dans `<string.h>`.
  - Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char str[] = "Hello";
size_t len = ft_strlen(str);
printf("La longueur de '%s' est %zu\\n", str, len);
```

## Voir aussi

  - [strlen(3) - Linux man page](https://man7.org/linux/man-pages/man3/strlen.3.html)
  - `ft_strcpy`, `ft_strncpy`, `ft_strlcpy` - Fonctions de manipulation de chaînes
