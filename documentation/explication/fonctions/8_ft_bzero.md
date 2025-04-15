# ft\_bzero - Mise à zéro de mémoire

- [ft\_bzero - Mise à zéro de mémoire](#ft_bzero---mise-à-zéro-de-mémoire)
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
void ft_bzero(void *s, size_t n);
```

## Description

La fonction `ft_bzero` met à zéro les `n` premiers octets de la zone mémoire pointée par `s`.

## Valeur de retour

  - La fonction ne retourne aucune valeur (type `void`).

## Comportement

  - La fonction remplit les `n` premiers octets de la zone mémoire pointée par `s` avec des zéros.
  - Elle ne tient pas compte du type de données pointé par `s` (elle remplit simplement des octets).
  - Elle gère correctement les pointeurs nuls et les tailles nulles.

## Cas limites à tester

```c
NULL, 0, 1, une grande valeur de n
```

## Pièges à éviter

1.  **Ne pas oublier de mettre à zéro tous les `n` octets** : La fonction doit s'arrêter après avoir rempli `n` octets.
2.  **Gérer les pointeurs nuls et les tailles nulles** : La fonction doit se comporter correctement même si `s` est nul ou `n` est nul.

## Différences avec la version standard

  - La version standard est définie dans `<string.h>`.
  - Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char buffer[10];
ft_bzero(buffer, 10);
```

## Voir aussi

  - [bzero(3) - Linux man page](https://man7.org/linux/man-pages/man3/bzero.3.html)
  - `ft_memset`, `ft_memcpy`, `ft_memmove` - Fonctions de manipulation de mémoire
