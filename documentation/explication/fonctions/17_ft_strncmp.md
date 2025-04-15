# ft\_strncmp - Comparaison de n caractères de deux chaînes

- [ft\_strncmp - Comparaison de n caractères de deux chaînes](#ft_strncmp---comparaison-de-n-caractères-de-deux-chaînes)
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
int ft_strncmp(const char *s1, const char *s2, size_t n);
```

## Description

La fonction `ft_strncmp` compare les `n` premiers caractères des chaînes `s1` et `s2`.

## Valeur de retour

  - Retourne une valeur entière :
    - Négative si `s1` est inférieure à `s2`.
    - Positive si `s1` est supérieure à `s2`.
    - Zéro si les `n` premiers caractères de `s1` et `s2` sont égaux.

## Comportement

  - La fonction compare les `n` premiers caractères de `s1` et `s2`.
  - La comparaison s'arrête si `n` caractères ont été comparés, si un caractère nul est rencontré dans l'une des chaînes, ou si une différence est trouvée.
  - La fonction ne modifie pas les chaînes d'origine (paramètres `const`).

## Cas limites à tester

```c
NULL, "", "abc", "abcd", "abcde", 0, 1, une grande valeur de n
```

## Pièges à éviter

1.  **Ne pas dépasser `n` caractères** : La comparaison doit s'arrêter après `n` caractères.
2.  **Ne pas oublier le caractère nul** : La comparaison doit s'arrêter si un caractère nul est rencontré.
3.  **Ne pas modifier les chaînes d'origine** : Les paramètres sont `const`, donc les chaînes ne doivent pas être modifiées.

## Différences avec la version standard

  - La version standard est définie dans `<string.h>`.
  - Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char s1[] = "Hello";
char s2[] = "HelloWorld";
int result = ft_strncmp(s1, s2, 5);
```

## Voir aussi

  - [strncmp(3) - Linux man page](https://man7.org/linux/man-pages/man3/strncmp.3.html)
  - `ft_strcmp`, `ft_memcmp` - Fonctions de comparaison
