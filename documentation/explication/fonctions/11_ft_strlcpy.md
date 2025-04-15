# ft\_strlcpy - Copie de chaîne avec limite de taille

- [ft\_strlcpy - Copie de chaîne avec limite de taille](#ft_strlcpy---copie-de-chaîne-avec-limite-de-taille)
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
size_t ft_strlcpy(char *dest, const char *src, size_t size);
```

## Description

La fonction `ft_strlcpy` copie la chaîne de caractères `src` dans `dest`, en respectant la taille maximale `size`. Elle garantit que `dest` est toujours terminé par un caractère nul, sauf si `size` est nul.

## Valeur de retour

  - Retourne la longueur totale de `src`, sans compter le caractère nul.

## Comportement

  - La fonction copie au maximum `size - 1` caractères de `src` dans `dest`.
  - Elle termine toujours `dest` par un caractère nul, sauf si `size` est nul.
  - Elle ne tient pas compte du type de données pointé par `src` et `dest` (elle copie simplement des octets).
  - Si `size` est nul, `dest` reste inchangé et la fonction retourne la longueur de `src`.

## Cas limites à tester

```c
NULL, 0, 1, une grande valeur de size, des chaînes src de différentes longueurs (courtes, longues, vides)
```

## Pièges à éviter

1.  **Ne pas oublier de terminer `dest` par un caractère nul** : La fonction doit toujours terminer `dest` par un caractère nul, sauf si `size` est nul.
2.  **Ne pas dépasser la taille `size - 1`** : La fonction doit copier au maximum `size - 1` caractères de `src` dans `dest`.
3.  **Gérer les pointeurs nuls et les tailles nulles** : La fonction doit se comporter correctement même si `src` ou `dest` est nul ou `size` est nul.

## Différences avec la version standard

  - La version standard est définie dans `<string.h>`.
  - Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char src[] = "Hello World";
char dest[6];
size_t len = ft_strlcpy(dest, src, 6);
```

## Voir aussi

  - [strlcpy(3) - Linux man page](https://www.google.com/search?q=https://man7.org/linux/man-pages/man3/strlcpy.3.html)
  - `ft_strcpy`, `ft_strncpy`, `ft_strlcat` - Fonctions de manipulation de chaînes
