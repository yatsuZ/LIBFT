# ft_strnstr - Localisation d'une sous-chaîne dans une chaîne limitée

- [ft\_strnstr - Localisation d'une sous-chaîne dans une chaîne limitée](#ft_strnstr---localisation-dune-sous-chaîne-dans-une-chaîne-limitée)
	- [Prototype](#prototype)
	- [Description](#description)
	- [Paramètres](#paramètres)
	- [Valeur de retour](#valeur-de-retour)
	- [Comportement](#comportement)
	- [Cas limites à tester](#cas-limites-à-tester)
	- [Pièges à éviter](#pièges-à-éviter)
	- [Différences avec la version standard](#différences-avec-la-version-standard)
	- [Exemple d'utilisation](#exemple-dutilisation)
	- [Voir aussi](#voir-aussi)
	- [Source](#source)

## Prototype

```c
char *ft_strnstr(const char *big, const char *little, size_t len);
```

## Description

La fonction `ft_strnstr` localise la première occurrence de la chaîne `little` dans la chaîne `big`, où au plus `len` caractères de `big` sont recherchés.

## Paramètres

-   `big`: La chaîne dans laquelle rechercher.
-   `little`: La sous-chaîne à trouver.
-   `len`: Le nombre maximum de caractères de `big` à rechercher.

## Valeur de retour

-   Si `little` est une chaîne vide, `big` est retourné.
-   Si `little` n'est pas trouvé dans `big`, `NULL` est retourné.
-   Sinon, un pointeur vers le premier caractère de la première occurrence de `little` dans `big` est retourné.

## Comportement

-   La fonction recherche la première occurrence de `little` dans `big`, en limitant la recherche aux `len` premiers caractères de `big`.
-   Si `little` est une chaîne vide, la fonction retourne `big`.
-   Les caractères après un `\0` dans `big` ne sont pas évalués.

## Cas limites à tester

-   `big` = `NULL` (si votre contexte le permet)
-   `little` = `NULL` (si votre contexte le permet)
-   `big` = `""`
-   `little` = `""`
-   `len` = `0`
-   `len` = `1`
-   `len` = une grande valeur
-   `little` non trouvé
-   `little` trouvé au début de `big`
-   `little` trouvé à la fin de `big`
-   `little` trouvé au milieu de `big`
-   `big` contient des `\0`

## Pièges à éviter

-   Ne pas dépasser `len` caractères lors de la recherche.
-   Gérer correctement les chaînes vides.
-   Ne pas lire au-delà de la fin d'une chaîne.
-   La comparaison doit s'arrêter quand un `\0` est détecté.

## Différences avec la version standard

-   La fonction `strnstr` est une extension spécifique à FreeBSD, donc elle n'est pas standardisée dans C.

## Exemple d'utilisation

```c
const char *largestring = "Foo Bar Baz";
const char *smallstring = "Bar";
char *ptr;

ptr = strnstr(largestring, smallstring, strlen(largestring));

if (ptr != NULL) {
    printf("Sous-chaîne trouvée: %s\n", ptr);
} else {
    printf("Sous-chaîne non trouvée.\n");
}

ptr = strnstr(largestring, smallstring, 4);

if (ptr == NULL) {
    printf("Sous-chaîne non trouvée (len=4)\n");
}
```

## Voir aussi

-   `strstr(3)`
-   `strcasestr(3)`
-   `strcasestr_l(3)`

## Source

-   [strnstr(3) - FreeBSD man page](https://man.freebsd.org/cgi/man.cgi?query=strnstr&sektion=3)
