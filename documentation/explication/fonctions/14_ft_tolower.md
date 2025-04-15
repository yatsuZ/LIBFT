# ft\_tolower - Conversion de caractère en minuscule

- [ft\_tolower - Conversion de caractère en minuscule](#ft_tolower---conversion-de-caractère-en-minuscule)
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
int ft_tolower(int c);
```

## Description

La fonction `ft_tolower` convertit un caractère majuscule en minuscule. Si le caractère n'est pas une lettre majuscule, il est retourné sans modification.

## Valeur de retour

  - Retourne la valeur ASCII du caractère converti en minuscule, ou le caractère d'origine si ce n'est pas une majuscule.

## Comportement

  - La fonction fonctionne avec le jeu de caractères ASCII (7 bits).
  - Elle ne tient pas compte des locales (comportement identique en toutes locales).
  - Elle gère correctement les valeurs hors plage ASCII et EOF.

## Cas limites à tester

```c
-1, 0, 'a', 'z', 'A', 'Z', '0', '9', 127, 128, 255, 256
```

## Pièges à éviter

1.  **Ne pas modifier les caractères non majuscules** : La fonction doit retourner les caractères non majuscules sans les modifier.
2.  **Ne pas oublier la conversion ASCII** : La différence entre une majuscule et sa minuscule correspondante est de 32 en ASCII.
3.  **Ne pas confondre avec d'autres jeux de caractères** : La fonction fonctionne uniquement pour les caractères ASCII.

## Différences avec la version standard

  - La version standard est définie dans `<ctype.h>`.
  - Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char c = 'A';
char lower = ft_tolower(c);
printf("'%c' en minuscule est '%c'\n", c, lower);
```

## Voir aussi

  - [tolower(3) - Linux man page](https://man7.org/linux/man-pages/man3/tolower.3.html)
  - `ft_toupper` - Fonction complémentaire
