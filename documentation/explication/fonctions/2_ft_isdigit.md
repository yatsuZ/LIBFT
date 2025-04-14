# ft_isdigit - Vérification de caractère numérique

## Prototype
```c
int ft_isdigit(int c);
```

## Description
La fonction `ft_isdigit` vérifie si le caractère passé en argument est un chiffre décimal (0-9).

## Valeur de retour
- Retourne **1** si le caractère est un chiffre (0-9)
- Retourne **0** dans tous les autres cas

## Comportement
- Fonctionne avec le jeu de caractères ASCII (7 bits)
- Ne tient pas compte des locales (comportement identique en toutes locales)
- Gère correctement EOF (-1) et les valeurs hors plage ASCII

## Implémentation recommandée
```c
int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}
```

## Cas limites à tester
```c
-1, 47 ('/'), 48 ('0'), 57 ('9'), 58 (':'), 127, 128, 255, 256
```

## Pièges à éviter
1. **Accepter d'autres chiffres** : Ne pas confondre avec `isxdigit` (qui accepte A-F/a-f)
2. **Oublier les bornes** : Bien vérifier '0' et '9' inclus
3. **Gestion des signes** : Ne pas accepter '+' ou '-' comme chiffres

## Différences avec la version standard
- La version standard peut varier selon la locale (théoriquement)
- Notre version se limite aux chiffres ASCII standards

## Exemple d'utilisation
```c
if (ft_isdigit(c)) {
    printf("'%c' est un chiffre\n", c);
}
```

## Voir aussi
- [isdigit(3) - Linux man page](https://man7.org/linux/man-pages/man3/isdigit.3.html)
- `ft_isalpha`, `ft_isalnum` - Fonctions complémentaires
- `ft_atoi` - Conversion chaîne vers entier
