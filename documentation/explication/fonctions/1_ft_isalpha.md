# ft_isalpha

- [ft\_isalpha](#ft_isalpha)
	- [Prototype](#prototype)
	- [Description](#description)
	- [Valeur de retour](#valeur-de-retour)
	- [Comportement](#comportement)
	- [Pièges à éviter](#pièges-à-éviter)
	- [Différences avec la version standard](#différences-avec-la-version-standard)
	- [Exemple d'utilisation](#exemple-dutilisation)
	- [Voir aussi](#voir-aussi)


## Prototype
```c
int ft_isalpha(int c);
```

## Description
La fonction `ft_isalpha` vérifie si le caractère passé en argument est une lettre alphabétique (majuscule ou minuscule).

## Valeur de retour
- Retourne **1** si le caractère est une lettre (A-Z ou a-z)
- Retourne **0** dans tous les autres cas

## Comportement
- Fonctionne avec le jeu de caractères ASCII (7 bits)
- Ne tient pas compte des locales (comportement identique en toutes locales)
- Gère correctement EOF (-1) et les valeurs hors plage ASCII

## Pièges à éviter
1. **Oublier le cast implicite** : L'argument est de type `int` mais doit être traité comme `unsigned char`
2. **Tester toutes les valeurs** : Inutile, se concentrer sur les cas limites
3. **Confondre avec isalnum** : Ne pas accepter les chiffres

## Différences avec la version standard
- La version standard peut être affectée par la locale
- Notre version se limite au strict ASCII pour simplifier

## Exemple d'utilisation
```c
if (ft_isalpha(c))
    printf("'%c' est une lettre\n", c);
```

## Voir aussi
- [isalpha(3) - Linux man page](https://man7.org/linux/man-pages/man3/isalpha.3.html)
- `ft_islower`, `ft_isupper` - Fonctions similaires