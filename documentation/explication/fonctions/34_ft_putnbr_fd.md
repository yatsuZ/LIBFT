# ft_putnbr_fd - Écriture d'un entier sur un descripteur de fichier

- [ft\_putnbr\_fd - Écriture d'un entier sur un descripteur de fichier](#ft_putnbr_fd---écriture-dun-entier-sur-un-descripteur-de-fichier)
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
void ft_putnbr_fd(int n, int fd);
```

## Description

La fonction `ft_putnbr_fd` écrit l'entier `n` sur le descripteur de fichier `fd` donné.

## Paramètres

* `n` : L'entier à écrire.
* `fd` : Le descripteur de fichier sur lequel écrire.

## Valeur de retour

Aucune.

## Comportement

* La fonction utilise l'appel système `write(2)` pour écrire l'entier `n` sur le descripteur de fichier `fd`.
* Si `fd` est un descripteur de fichier valide, l'entier est écrit.
* Si `fd` n'est pas un descripteur de fichier valide, le comportement de la fonction est indéfini.
* La fonction gère les entiers négatifs.
* La fonction ne retourne aucune valeur.

## Cas limites à tester

* `fd` est un descripteur de fichier valide (par exemple, `1` pour la sortie standard, `2` pour la sortie d'erreur).
* `fd` n'est pas un descripteur de fichier valide.
* `n` est un entier positif.
* `n` est un entier négatif.
* `n` est égal à `0`.
* `n` est égal à `INT_MIN` ou `INT_MAX`.

## Pièges à éviter

* Ne pas oublier de vérifier que `fd` est un descripteur de fichier valide avant d'appeler `write(2)`.
* Ne pas oublier de gérer les erreurs potentielles de `write(2)`.
* Ne pas oublier de gérer les entiers négatifs.
* Ne pas oublier de gérer les cas limites tels que `INT_MIN` et `INT_MAX`.

## Exemple d'utilisation

```c
#include <stdio.h>

int main(void)
{
    ft_putnbr_fd(-12345, 1); // Écrit -12345 sur la sortie standard
    ft_putnbr_fd('\n', 1);
    return (0);
}
```

## Voir aussi

* `write(2)`
