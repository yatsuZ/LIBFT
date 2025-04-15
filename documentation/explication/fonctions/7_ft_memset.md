# ft\_memset - Remplissage de mémoire

- [ft\_memset - Remplissage de mémoire](#ft_memset---remplissage-de-mémoire)
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
void *ft_memset(void *s, int c, size_t n);
```

## Description

La fonction `ft_memset` remplit les `n` premiers octets de la zone mémoire pointée par `s` avec la valeur `c` (convertie en `unsigned char`).

## Valeur de retour

  - Retourne un pointeur vers la zone mémoire `s`.

## Comportement

  - La fonction remplit les `n` premiers octets de la zone mémoire pointée par `s` avec la valeur `c` (convertie en `unsigned char`).
  - Elle ne tient pas compte du type de données pointé par `s` (elle remplit simplement des octets).
  - Elle gère correctement les pointeurs nuls et les tailles nulles.

## Cas limites à tester

```c
NULL, 0, 1, une grande valeur de n, des valeurs de c variées
```

## Pièges à éviter

1.  **Ne pas oublier la conversion en `unsigned char`** : La valeur `c` doit être convertie en `unsigned char` avant d'être écrite dans la mémoire.
2.  **Ne pas dépasser la taille `n`** : La fonction doit s'arrêter après avoir rempli `n` octets.
3.  **Gérer les pointeurs nuls et les tailles nulles** : La fonction doit se comporter correctement même si `s` est nul ou `n` est nul.

## Différences avec la version standard

  - La version standard est définie dans `<string.h>`.
  - Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char buffer[10];
ft_memset(buffer, 'A', 10);
```

## Voir aussi

  - [memset(3) - Linux man page](https://man7.org/linux/man-pages/man3/memset.3.html)
  - `ft_bzero`, `ft_memcpy`, `ft_memmove` - Fonctions de manipulation de mémoire
