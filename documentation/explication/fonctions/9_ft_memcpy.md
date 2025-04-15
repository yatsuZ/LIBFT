# ft\_memcpy - Copie de mémoire

- [ft\_memcpy - Copie de mémoire](#ft_memcpy---copie-de-mémoire)
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
void *ft_memcpy(void *dest, const void *src, size_t n);
```

## Description

La fonction `ft_memcpy` copie `n` octets depuis la zone mémoire pointée par `src` vers la zone mémoire pointée par `dest`.

## Valeur de retour

  - Retourne un pointeur vers la zone mémoire `dest`.

## Comportement

  - La fonction copie `n` octets depuis la zone mémoire pointée par `src` vers la zone mémoire pointée par `dest`.
  - Elle ne tient pas compte du type de données pointé par `src` et `dest` (elle copie simplement des octets).
  - Elle ne gère pas les chevauchements de mémoire (utiliser `ft_memmove` pour cela).
  - Elle gère correctement les pointeurs nuls et les tailles nulles.

## Cas limites à tester

```c
NULL, 0, 1, une grande valeur de n, des zones mémoire qui se chevauchent (pour tester le comportement indéfini)
```

## Pièges à éviter

1.  **Ne pas oublier la conversion en `unsigned char`** : La fonction doit copier des octets, donc les pointeurs doivent être convertis en `unsigned char *`.
2.  **Ne pas gérer les chevauchements de mémoire** : Si les zones mémoire se chevauchent, le comportement est indéfini.
3.  **Gérer les pointeurs nuls et les tailles nulles** : La fonction doit se comporter correctement même si `src` ou `dest` est nul ou `n` est nul.

## Différences avec la version standard

  - La version standard est définie dans `<string.h>`.
  - Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char src[] = "Hello";
char dest[6];
ft_memcpy(dest, src, 6);
```

## Voir aussi

  - [memcpy(3) - Linux man page](https://man7.org/linux/man-pages/man3/memcpy.3.html)
  - `ft_memmove`, `ft_memcmp`, `ft_memset` - Fonctions de manipulation de mémoire
