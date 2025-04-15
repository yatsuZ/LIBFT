# ft\_isprint - Vérification de caractère imprimable

- [ft\_isprint - Vérification de caractère imprimable](#ft_isprint---vérification-de-caractère-imprimable)
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
int ft_isprint(int c);
```

## Description

La fonction `ft_isprint` vérifie si le caractère passé en argument est un caractère imprimable. Un caractère imprimable est un caractère ASCII qui a une représentation visuelle (c'est-à-dire, qui n'est pas un caractère de contrôle).

## Valeur de retour

  - Retourne **1** si le caractère est un caractère imprimable.
  - Retourne **0** dans tous les autres cas.

## Comportement

  - Fonctionne avec le jeu de caractères ASCII (7 bits).
  - Ne tient pas compte des locales (comportement identique en toutes locales).
  - Gère correctement EOF (-1) et les valeurs hors plage ASCII.

## Cas limites à tester

```c
-1, 0, 31, 32, 126, 127, 128, 255, 256
```

## Pièges à éviter

1.  **Oublier les bornes** : Bien vérifier les bornes (32 et 126 inclus).
2.  **Confondre avec d'autres fonctions** : Ne pas accepter les caractères de contrôle (avant 32 ou après 126).

## Différences avec la version standard

  - La version standard peut varier selon la locale (théoriquement).
  - Notre version se limite aux caractères ASCII standards.

## Exemple d'utilisation

```c
if (ft_isprint(c)) {
    printf("'%c' est un caractère imprimable\n", c);
}
```

## Voir aussi

  - [isprint(3) - Linux man page](https://www.google.com/search?q=https://man7.org/linux/man-pages/man3/isprint.3.html)
  - `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii` - Fonctions complémentaires
  - `ft_atoi` - Conversion chaîne vers entier
