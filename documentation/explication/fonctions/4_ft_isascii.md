# ft\_isascii - Vérification de caractère ASCII

- [ft\_isascii - Vérification de caractère ASCII](#ft_isascii---vérification-de-caractère-ascii)
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
int ft_isascii(int c);
```

## Description

La fonction `ft_isascii` vérifie si le caractère passé en argument est un caractère ASCII (code entre 0 et 127 inclus).

## Valeur de retour

  - Retourne **1** si le caractère est un caractère ASCII.
  - Retourne **0** dans tous les autres cas.

## Comportement

  - Fonctionne avec le jeu de caractères ASCII (7 bits).
  - Ne tient pas compte des locales (comportement identique en toutes locales).
  - Gère correctement EOF (-1) et les valeurs hors plage ASCII.

## Cas limites à tester

```c
-1, 0, 127, 128, 255, 256
```

## Pièges à éviter

1.  **Oublier les bornes** : Bien vérifier les bornes (0 et 127 inclus).
2.  **Confondre avec d'autres jeux de caractères** : Ne pas accepter les caractères étendus (au-delà de 127).

## Différences avec la version standard

  - La version standard peut varier selon la locale (théoriquement).
  - Notre version se limite aux caractères ASCII standards.

## Exemple d'utilisation

```c
if (ft_isascii(c)) {
    printf("'%c' est un caractère ASCII\n", c);
}
```

## Voir aussi

  - [isascii(3) - Linux man page](https://www.google.com/search?q=https://man7.org/linux/man-pages/man3/isascii.3.html)
  - `ft_isalpha`, `ft_isdigit`, `ft_isalnum` - Fonctions complémentaires
  - `ft_atoi` - Conversion chaîne vers entier
