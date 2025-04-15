# ft_striteri - Application d'une fonction à chaque caractère d'une chaîne (avec index)

- [ft\_striteri - Application d'une fonction à chaque caractère d'une chaîne (avec index)](#ft_striteri---application-dune-fonction-à-chaque-caractère-dune-chaîne-avec-index)
	- [Prototype](#prototype)
	- [Description](#description)
	- [Paramètres](#paramètres)
	- [Valeur de retour](#valeur-de-retour)
	- [Comportement](#comportement)
	- [Cas limites à tester](#cas-limites-à-tester)
	- [Pièges à éviter](#pièges-à-éviter)
	- [Exemple d'utilisation](#exemple-dutilisation)
	- [Voir aussi](#voir-aussi)

## Prototype

```c
void ft_striteri(char *s, void (*f)(unsigned int, char*));
```

## Description

La fonction `ft_striteri` applique la fonction `f` à chaque caractère de la chaîne `s`, en passant l'indice du caractère comme premier argument et l'adresse du caractère lui-même comme second argument. Chaque caractère est transmis par adresse à `f` afin d'être modifié si nécessaire.

## Paramètres

* `s` : La chaîne de caractères sur laquelle itérer.
* `f` : La fonction à appliquer à chaque caractère.

## Valeur de retour

Aucune.

## Comportement

* La fonction itère sur chaque caractère de la chaîne `s`, en passant l'indice du caractère et son adresse à la fonction `f`.
* La fonction `f` peut modifier le caractère directement via son adresse.
* Si `s` ou `f` sont `NULL`, le comportement de la fonction est indéfini.
* La fonction ne retourne aucune valeur.

## Cas limites à tester

* `s` est `NULL`.
* `f` est `NULL`.
* `s` est une chaîne vide.
* `s` est une chaîne très longue.
* `f` modifie les caractères de manière prévisible.

## Pièges à éviter

* Ne pas oublier de gérer le cas où `s` ou `f` sont `NULL`.
* Ne pas oublier que les caractères sont passés par adresse à `f`.
* Ne pas modifier la chaîne `s` de manière inattendue dans `f`.

## Exemple d'utilisation

```c
#include <stdio.h>

void to_upper(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

int main(void)
{
    char s[] = "hello, world!";
    ft_striteri(s, to_upper);
    printf("Chaîne modifiée: %s\n", s);
    return (0);
}
```

## Voir aussi

* `ft_strmapi(3)`
