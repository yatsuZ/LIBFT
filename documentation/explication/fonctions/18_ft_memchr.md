# ft\_memchr - Recherche d'un caractère dans une zone mémoire

- [ft\_memchr - Recherche d'un caractère dans une zone mémoire](#ft_memchr---recherche-dun-caractère-dans-une-zone-mémoire)
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
void *ft_memchr(const void *s, int c, size_t n);
```

## Description

La fonction `ft_memchr` localise la première occurrence du caractère `c` (converti en `unsigned char`) dans les `n` premiers octets de la zone mémoire pointée par `s`.

## Valeur de retour

  - Retourne un pointeur vers la première occurrence du caractère `c` dans la zone mémoire.
  - Retourne `NULL` si le caractère `c` n'est pas trouvé dans les `n` premiers octets.

## Comportement

  - La fonction parcourt les `n` premiers octets de la zone mémoire pointée par `s` jusqu'à trouver le caractère `c` ou jusqu'à atteindre la fin de la zone mémoire.
  - La comparaison se fait octet par octet, en convertissant `c` en `unsigned char`.
  - La fonction ne modifie pas la zone mémoire d'origine (paramètre `const`).

## Cas limites à tester

```c
NULL, 0, 1, une grande valeur de n, des zones mémoire contenant et ne contenant pas le caractère `c`
```

## Pièges à éviter

1.  **Ne pas oublier la conversion en `unsigned char`** : La comparaison doit se faire octet par octet, donc `c` doit être converti en `unsigned char`.
2.  **Ne pas dépasser `n` octets** : La fonction doit s'arrêter après avoir parcouru `n` octets.
3.  **Gérer les pointeurs nuls et les tailles nulles** : La fonction doit se comporter correctement même si `s` est nul ou `n` est nul.

## Différences avec la version standard

  - La version standard est définie dans `<string.h>`.
  - Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char str[] = "Hello World";
void *ptr = ft_memchr(str, 'W', 11);
if (ptr != NULL) {
    printf("'%c' trouvé à partir de l'adresse %p\n", 'W', ptr);
}
```

## Voir aussi

  - [memchr(3) - Linux man page](https://man7.org/linux/man-pages/man3/memchr.3.html)
  - `ft_memcmp`, `ft_memcpy`, `ft_memmove` - Fonctions de manipulation de mémoire
