# ft\_strlcat - Concaténation de chaîne avec limite de taille

- [ft\_strlcat - Concaténation de chaîne avec limite de taille](#ft_strlcat---concaténation-de-chaîne-avec-limite-de-taille)
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
size_t	ft_strlcat(char *dest, const char *src, size_t size);
```

## Description

La fonction `ft_strlcat` concatène la chaîne `src` à la fin de la chaîne `dest`, en respectant la taille maximale `size`. Elle garantit que `dest` est toujours terminé par un caractère nul, sauf si `size` est nul.

## Valeur de retour

  - Retourne la longueur totale de la chaîne qu'elle a tenté de créer, c'est-à-dire la longueur initiale de `dest` plus la longueur de `src`.

## Comportement

  - La fonction concatène au maximum `size - strlen(dest) - 1` caractères de `src` à la fin de `dest`.
  - Elle termine toujours `dest` par un caractère nul, sauf si `size` est nul.
  - Elle ne tient pas compte du type de données pointé par `src` et `dest` (elle copie simplement des octets).
  - Si `size` est nul, `dest` reste inchangé et la fonction retourne la longueur de `src`.

## Cas limites à tester

```c
NULL, 0, 1, une grande valeur de size, des chaînes src et dest de différentes longueurs (courtes, longues, vides)
```

## Pièges à éviter

1.  **Ne pas oublier de terminer `dest` par un caractère nul** : La fonction doit toujours terminer `dest` par un caractère nul, sauf si `size` est nul.
2.  **Ne pas dépasser la taille `size - 1`** : La fonction doit concaténer au maximum `size - strlen(dest) - 1` caractères de `src` à la fin de `dest`.
3.  **Gérer les pointeurs nuls et les tailles nulles** : La fonction doit se comporter correctement même si `src` ou `dest` est nul ou `size` est nul.
4. **Faire attention a la valeur de retour** : La fonction retourne la longueur totale de la chaîne qu'elle a tenté de créer.

## Différences avec la version standard

  - La version standard est définie dans `<string.h>`.
  - Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char dest[20] = "Hello";
char src[] = " World";
size_t len = ft_strlcat(dest, src, sizeof(dest));
```

## Voir aussi

  - [strlcat(3) - Linux man page](https://www.google.com/search?q=https://man7.org/linux/man-pages/man3/strlcat.3.html)
  - `ft_strcpy`, `ft_strncpy`, `ft_strlcpy` - Fonctions de manipulation de chaînes
