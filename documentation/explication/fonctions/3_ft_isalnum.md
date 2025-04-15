# ft_isalnum - Vérification de caractère alphanumérique

- [ft\_isalnum - Vérification de caractère alphanumérique](#ft_isalnum---vérification-de-caractère-alphanumérique)
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
int ft_isalnum(int c);
```

## Description

La fonction `ft_isalnum` vérifie si le caractère passé en argument est un chiffre décimal (0-9) ou une lettre alphabétique (A-Z, a-z).

## Valeur de retour

  - Retourne **1** si le caractère est un chiffre (0-9) ou une lettre (A-Z, a-z).
  - Retourne **0** dans tous les autres cas.

## Comportement

  - Fonctionne avec le jeu de caractères ASCII (7 bits).
  - Ne tient pas compte des locales (comportement identique en toutes locales).
  - Gère correctement EOF (-1) et les valeurs hors plage ASCII.

## Cas limites à tester

```c
-1, 47 ('/'), 48 ('0'), 57 ('9'), 58 (':'), 64 ('@'), 65 ('A'), 90 ('Z'), 91 ('['), 96 ('`'), 97 ('a'), 122 ('z'), 123 ('{'), 127, 128, 255, 256
```

## Pièges à éviter

1.  **Accepter d'autres caractères** : Ne pas confondre avec d'autres fonctions (ex : `isxdigit`).
2.  **Oublier les bornes** : Bien vérifier les bornes des chiffres et des lettres (majuscules et minuscules).
3.  **Gestion des signes** : Ne pas accepter '+' ou '-' comme caractères alphanumériques.

## Différences avec la version standard

  - La version standard peut varier selon la locale (théoriquement).
  - Notre version se limite aux caractères ASCII standards.

## Exemple d'utilisation

```c
if (ft_isalnum(c)) {
    printf("'%c' est un caractère alphanumérique\n", c);
}
```

## Voir aussi

  - [isalnum(3) - Linux man page](https://www.google.com/search?q=https://man7.org/linux/man-pages/man3/isalnum.3.html)
  - `ft_isalpha`, `ft_isdigit` - Fonctions complémentaires
  - `ft_atoi` - Conversion chaîne vers entier
