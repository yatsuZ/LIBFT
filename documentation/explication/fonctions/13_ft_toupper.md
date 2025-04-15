# ft\_toupper - Conversion de caractère en majuscule

- [ft\_toupper - Conversion de caractère en majuscule](#ft_toupper---conversion-de-caractère-en-majuscule)
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
int ft_toupper(int c);
```

## Description

La fonction `ft_toupper` convertit un caractère minuscule en majuscule. Si le caractère n'est pas une lettre minuscule, il est retourné sans modification.

## Valeur de retour

  - Retourne la valeur ASCII du caractère converti en majuscule, ou le caractère d'origine si ce n'est pas une minuscule.

## Comportement

  - La fonction fonctionne avec le jeu de caractères ASCII (7 bits).
  - Elle ne tient pas compte des locales (comportement identique en toutes locales).
  - Elle gère correctement les valeurs hors plage ASCII et EOF.

## Cas limites à tester

```c
-1, 0, 'a', 'z', 'A', 'Z', '0', '9', 127, 128, 255, 256
```

## Pièges à éviter

1.  **Ne pas modifier les caractères non minuscules** : La fonction doit retourner les caractères non minuscules sans les modifier.
2.  **Ne pas oublier la conversion ASCII** : La différence entre une minuscule et sa majuscule correspondante est de 32 en ASCII.
3.  **Ne pas confondre avec d'autres jeux de caractères** : La fonction fonctionne uniquement pour les caractères ASCII.

## Différences avec la version standard

  - La version standard est définie dans `<ctype.h>`.
  - Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char c = 'a';
char upper = ft_toupper(c);
printf("'%c' en majuscule est '%c'\n", c, upper);
```

## Voir aussi

  - [toupper(3) - Linux man page](https://man7.org/linux/man-pages/man3/toupper.3.html)
  - `ft_tolower` - Fonction complémentaire
