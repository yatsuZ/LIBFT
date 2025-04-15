# ft\_memcmp - Comparaison de zones mémoire

- [ft\_memcmp - Comparaison de zones mémoire](#ft_memcmp---comparaison-de-zones-mémoire)
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
int ft_memcmp(const void *s1, const void *s2, size_t n);
```

## Description

La fonction `ft_memcmp` compare les `n` premiers octets des zones mémoire pointées par `s1` et `s2`.

## Valeur de retour

  - Retourne une valeur entière :
    - Négative si `s1` est inférieure à `s2`.
    - Positive si `s1` est supérieure à `s2`.
    - Zéro si les `n` premiers octets de `s1` et `s2` sont égaux.

## Comportement

  - La fonction compare les `n` premiers octets de `s1` et `s2`.
  - La comparaison s'arrête si `n` octets ont été comparés ou si une différence est trouvée.
  - La comparaison se fait octet par octet, en considérant les octets comme des `unsigned char`.
  - La fonction ne modifie pas les zones mémoire d'origine (paramètres `const`).

## Cas limites à tester

```c
NULL, 0, 1, une grande valeur de n, des zones mémoire identiques et différentes
```

## Pièges à éviter

1.  **Ne pas oublier la conversion en `unsigned char`** : La comparaison doit se faire octet par octet, donc les octets doivent être considérés comme des `unsigned char`.
2.  **Ne pas dépasser `n` octets** : La comparaison doit s'arrêter après `n` octets.
3.  **Gérer les pointeurs nuls et les tailles nulles** : La fonction doit se comporter correctement même si `s1` ou `s2` est nul ou `n` est nul.

## Différences avec la version standard

  - La version standard est définie dans `<string.h>`.
  - Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char str1[] = "Hello";
char str2[] = "HelloWorld";
int result = ft_memcmp(str1, str2, 5);
```

## Voir aussi

  - [memcmp(3) - Linux man page](https://man7.org/linux/man-pages/man3/memcmp.3.html)
  - `ft_memcpy`, `ft_memmove`, `ft_memchr` - Fonctions de manipulation de mémoire
