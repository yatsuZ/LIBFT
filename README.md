# Libft

> 📚 Projet 42 — Ce projet a pour objectif de nous faire coder en C une bibliothèque de fonctions usuelles que nous pourrons utiliser pour nos prochains projets.

---

## 📑 Table des matières

- [Libft](#libft)
	- [📑 Table des matières](#-table-des-matières)
	- [📁 Structure du projet](#-structure-du-projet)
	- [🧠 Objectif](#-objectif)
	- [⚙️ Compilation](#️-compilation)
	- [✅ Fonctions implémentées](#-fonctions-implémentées)
		- [Partie 1 — Fonctions standard](#partie-1--fonctions-standard)
		- [Partie 2 — Fonctions supplémentaires](#partie-2--fonctions-supplémentaires)
		- [Partie bonus — Listes chaînées](#partie-bonus--listes-chaînées)
	- [🧪 Tests](#-tests)
	- [📒 Documentation personnelle](#-documentation-personnelle)
	- [📚 Ressources](#-ressources)
	- [👤 Auteur](#-auteur)
	- [🔖 Remarques](#-remarques)

---

## 📁 Structure du projet

```
.
├── README.md                  # Ce fichier
├── code/
│   ├── code/tests/                # Scripts de test (à venir)
│   └── LIBFT/                 # Code source du projet (dossier à rendre)
└── documentation/
    ├── explication/           # Explications détaillées (par fonction)
    │   └── fonctions/         # Une fiche .md par fonction
    └── utils/                 
        ├── fr.subject_libft_fr_v_15.pdf
        └── fr.subject_libft_fr_v_16.1.pdf
```

---

## 🧠 Objectif

Libft est le tout premier projet du cursus 42.  
Il consiste à recréer une bibliothèque standard en C (`libc`), sans utiliser les fonctions interdites.

Les objectifs pédagogiques sont :

- Apprendre à organiser un projet C avec un Makefile.
- S’approprier les fonctions de base de la bibliothèque C.
- Gérer proprement la mémoire (malloc, free, pointeurs...).
- Comprendre l’importance d’un code normé et lisible.

👉 Voir les [consignes générales](./documentation/explication/Consignes.md)

---

## ⚙️ Compilation

```bash
cd code/LIBFT
make
```

Cela génère la bibliothèque statique `libft.a`.

💡 Pour l’utiliser dans vos projets :  
Voir [ce guide](./documentation/explication/utilisation_libft.md) sur les `.a`.

---

## ✅ Fonctions implémentées

### Partie 1 — Fonctions standard

| ID  | Fonction         | Fait ✅ | Testée 🧪 | Notes 📌 |
|-----|------------------|--------|-----------|-----------|
| 1   | `ft_isalpha`     | ✅     | ✅        |   en de hors de ascii pas pris en compte comportement indeterminer        |
| 2   | `ft_isdigit`     | ✅     | ✅        |   en de hors de ascii pas pris en compte comportement indeterminer        |
| 3   | `ft_isalnum`     | ✅     | ✅        |   en de hors de ascii pas pris en compte comportement indeterminer        |
| 4   | `ft_isascii`     | ✅     | ✅        |           |
| 5   | `ft_isprint`     | ✅     | ✅        |   en de hors de ascii pas pris en compte comportement indeterminer        |
| 6   | `ft_strlen`      | ✅     | ✅        |           |
| 7   | `ft_memset`      | ✅     | ✅        |           |
| 8   | `ft_bzero`       | ✅     | ✅        |           |
| 9   | `ft_memcpy`      | ✅     | ✅        |           |
| 10  | `ft_memmove`     | ✅     | ✅        |           |
| 11  | `ft_strlcpy`     | ✅     | ✅        |           |
| 12  | `ft_strlcat`     | ✅     | ✅        |           |
| 13  | `ft_toupper`     | ✅     | ✅        |           |
| 14  | `ft_tolower`     | ✅     | ✅        |           |
| 15  | `ft_strchr`      | ✅     | ✅        |           |
| 16  | `ft_strrchr`     | ✅     | ✅        |           |
| 17  | `ft_strncmp`     | ✅     | ✅        |           |
| 18  | `ft_memchr`      | ✅     | ✅        |           |
| 19  | `ft_memcmp`      | ✅     | ✅        |           |
| 20  | `ft_strnstr`     | ✅     | ✅        |           |
| 21  | `ft_atoi`        | ✅     | ✅        |           |
| 22  | `ft_calloc`      | ✅     | ✅        |           |
| 23  | `ft_strdup`      | ✅     | ✅        |           |

### Partie 2 — Fonctions supplémentaires

| ID  | Fonction         | Fait ✅ | Testée 🧪 | Notes 📌 |
|-----|------------------|--------|-----------|------------|
| 24  | `ft_substr`      | ⬜️     | ⬜️        |            |
| 25  | `ft_strjoin`     | ⬜️     | ⬜️        |            |
| 26  | `ft_strtrim`     | ⬜️     | ⬜️        |            |
| 27  | `ft_split`       | ⬜️     | ⬜️        |            |
| 28  | `ft_itoa`        | ⬜️     | ⬜️        |            |
| 29  | `ft_strmapi`     | ⬜️     | ⬜️        |            |
| 30  | `ft_striteri`    | ⬜️     | ⬜️        |            |
| 31  | `ft_putchar_fd`  | ⬜️     | ⬜️        |            |
| 32  | `ft_putstr_fd`   | ⬜️     | ⬜️        |            |
| 33  | `ft_putendl_fd`  | ⬜️     | ⬜️        |            |
| 34  | `ft_putnbr_fd`   | ⬜️     | ⬜️        |            |

### Partie bonus — Listes chaînées

```c
typedef struct s_list
{
    void          *content;
    struct s_list *next;
} t_list;
```

> 💡 Les fichiers doivent avoir un suffixe `_bonus.c` et être compilés via `make bonus`.

| ID  | Fonction            | Fait ✅ | Testée 🧪 | Notes 📌 |
|-----|---------------------|--------|-----------|----------|
| 35  | `ft_lstnew`         | ⬜️     | ⬜️        |          |
| 36  | `ft_lstadd_front`   | ⬜️     | ⬜️        |          |
| 37  | `ft_lstsize`        | ⬜️     | ⬜️        |          |
| 38  | `ft_lstlast`        | ⬜️     | ⬜️        |          |
| 39  | `ft_lstadd_back`    | ⬜️     | ⬜️        |          |
| 40  | `ft_lstdelone`      | ⬜️     | ⬜️        |          |
| 41  | `ft_lstclear`       | ⬜️     | ⬜️        |          |
| 42  | `ft_lstiter`        | ⬜️     | ⬜️        |          |
| 43  | `ft_lstmap`         | ⬜️     | ⬜️        |          |

---

## 🧪 Tests

Un dossier `code/tests/` contiendra des fichiers pour tester indépendamment chaque fonction.  
👉 Exécutable de test à venir : `tester`

---

## 📒 Documentation personnelle

Les explications complètes sont dans :

```
documentation/explication/fonctions/
```

Chaque fiche `.md` contient :

- le prototype de la fonction,
- des explications simples,
- les cas limites,
- l’implémentation en C,
- des remarques et des pièges à éviter.

---

## 📚 Ressources

- [📄 Sujet officiel PDF](./documentation/utils/fr.subject_libft_fr.pdf)
- [🧠 Cours & fiches](./documentation/explication/)

---

## 👤 Auteur

| Info         | Détail                                                             |
|--------------|--------------------------------------------------------------------|
| Nom          | Zaoui                                                              |
| Prénom       | Yassine                                                            |
| Pseudo       | Yatsu                                                              |
| Login 42     | yzaoui                                                             |
| Instagram    | [@yatsu__officiel](https://www.instagram.com/yatsu__officiel/)    |

---

## 🔖 Remarques

Ce dépôt est à but pédagogique.  
Il vise à progresser dans le langage C tout en respectant des standards professionnels (norme, structure, modularité...).
