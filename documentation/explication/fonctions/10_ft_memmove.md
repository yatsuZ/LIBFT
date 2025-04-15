# ft\_memmove - Copie de mémoire (avec chevauchement)

- [ft\_memmove - Copie de mémoire (avec chevauchement)](#ft_memmove---copie-de-mémoire-avec-chevauchement)
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
void *ft_memmove(void *dest, const void *src, size_t n);
```

## Description

La fonction `ft_memmove` copie `n` octets depuis la zone mémoire pointée par `src` vers la zone mémoire pointée par `dest`. Contrairement à `ft_memcpy`, `ft_memmove` gère les chevauchements de mémoire, garantissant une copie correcte même si les zones `src` et `dest` se chevauchent.

## Valeur de retour

  - Retourne un pointeur vers la zone mémoire `dest`.

## Comportement

  - La fonction copie `n` octets depuis la zone mémoire pointée par `src` vers la zone mémoire pointée par `dest`.
  - Elle gère correctement les chevauchements de mémoire en utilisant une copie intermédiaire si nécessaire.
  - Elle ne tient pas compte du type de données pointé par `src` et `dest` (elle copie simplement des octets).
  - Elle gère correctement les pointeurs nuls et les tailles nulles.

## Cas limites à tester

```c
NULL, 0, 1, une grande valeur de n, des zones mémoire qui se chevauchent (à la fois `src` > `dest` et `dest` > `src`)
```

## Pièges à éviter

1.  **Ne pas oublier la gestion des chevauchements** : La fonction doit se comporter correctement même si les zones mémoire se chevauchent.
2.  **Ne pas oublier la conversion en `unsigned char`** : La fonction doit copier des octets, donc les pointeurs doivent être convertis en `unsigned char *`.
3.  **Gérer les pointeurs nuls et les tailles nulles** : La fonction doit se comporter correctement même si `src` ou `dest` est nul ou `n` est nul.

## Différences avec la version standard

  - La version standard est définie dans `<string.h>`.
  - Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char str[] = "Hello World";
ft_memmove(str + 6, str, 5); // Déplacer "Hello" après "World"
```

## Voir aussi

  - [memmove(3) - Linux man page](https://man7.org/linux/man-pages/man3/memmove.3.html)
  - `ft_memcpy`, `ft_memcmp`, `ft_memset` - Fonctions de manipulation de mémoire
