# ft_atoi - Conversion d'une chaîne en entier

- [ft\_atoi - Conversion d'une chaîne en entier](#ft_atoi---conversion-dune-chaîne-en-entier)
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
int ft_atoi(const char *str);
```

## Description

La fonction `ft_atoi` convertit la partie initiale de la chaîne `str` en un entier de type `int`. Elle ignore les espaces et les tabulations en début de chaîne, puis lit les chiffres jusqu'à rencontrer un caractère non numérique.

## Valeur de retour

-   Retourne l'entier converti à partir de la chaîne `str`.
-   Retourne `0` si aucune conversion n'est possible.

## Comportement

-   La fonction ignore les espaces et les tabulations en début de chaîne.
-   Elle gère les signes '+' et '-' en début de chaîne.
-   Elle lit les chiffres jusqu'à rencontrer un caractère non numérique.
-   Elle gère les dépassements de capacité en retournant les valeurs `INT_MAX` ou `INT_MIN` selon le signe.

## Cas limites à tester

-   Chaînes vides.
-   Chaînes contenant uniquement des espaces.
-   Chaînes avec des signes '+' ou '-'.
-   Chaînes avec des chiffres et des caractères non numériques.
-   Chaînes représentant des nombres très grands (dépassant `INT_MAX` ou `INT_MIN`).
-   Chaînes avec des tabulations.
-   Chaînes avec des valeurs null.

## Pièges à éviter

-   Ne pas oublier de gérer les signes '+' et '-'.
-   Ne pas oublier de gérer les espaces et les tabulations en début de chaîne.
-   Ne pas oublier de gérer les dépassements de capacité.
-   Ne pas oublier de retourner `0` si aucune conversion n'est possible.

## Différences avec la version standard

-   La version standard est définie dans `<stdlib.h>`.
-   Notre version doit avoir le même comportement, mais peut être implémentée différemment.

## Exemple d'utilisation

```c
char str[] = "  -12345abc";
int num = ft_atoi(str);
printf("La chaîne '%s' convertie en entier est %d\n", str, num);
```

## Voir aussi

-   `atoi(3)` - Linux man page : [https://man7.org/linux/man-pages/man3/atoi.3.html](https://man7.org/linux/man-pages/man3/atoi.3.html)
-   `ft_isdigit` - Fonction de vérification de caractères numériques
