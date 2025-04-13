# 🧱 Étape 1 — Créer les fichiers

Pour commencer le projet **Libft**, je dois créer la bonne structure de fichiers. Voici ce que j’ai mis en place :

- [🧱 Étape 1 — Créer les fichiers](#-étape-1--créer-les-fichiers)
  - [📁 Arborescence de base](#-arborescence-de-base)
  - [🔍 Organisation de `libft.h`](#-organisation-de-libfth)
  - [⚙️ Structure du Makefile](#️-structure-du-makefile)
  - [✅ La suite](#-la-suite)

---

## 📁 Arborescence de base

1. `libft.h` → le fichier d’en-tête principal (header)
2. `Makefile` → script de compilation automatique
3. `part_1/` → contient tous les fichiers `.c` de la partie 1
4. `part_2/` → contient tous les fichiers `.c` de la partie 2
5. `part_bonus/` → contient tous les fichiers `.c` pour les fonctions bonus

---

## 🔍 Organisation de `libft.h`

On peut diviser le fichier `libft.h` en **5 sections** :

1. ✅ Les `#include` nécessaires (`stdlib.h`, `unistd.h`, etc.)
2. 🔢 Les déclarations des fonctions de la **partie 1**
3. 🔣 Les déclarations des fonctions de la **partie 2**
4. 🧱 La **définition de la structure** `t_list` (utilisée dans les bonus)
5. 🛠️ Les déclarations des fonctions **bonus** (liées aux listes chaînées)

---

## ⚙️ Structure du Makefile

Le `Makefile` est composé de plusieurs éléments :

- `.PHONY` : pour déclarer les cibles qui ne sont pas des fichiers
- Des **variables** :
  - Chemins des fichiers sources
  - Noms des objets `.o`
  - Nom du programme (`libft.a`)
  - Commandes (`CC`, `CFLAGS`, `AR`, etc.)
- Et enfin des **règles** :
  - `all`, `clean`, `fclean`, `re`
  - `bonus` pour compiler les fichiers bonus

## ✅ La suite

Maintenant que toute la structure est en place, il ne reste plus qu’à :

1. 🧠 **Coder les fonctions** une par une (en suivant l’ordre que je préfère)
2. 🧪 **Créer des testeurs** pour chaque fonction :
   - Pour valider leur comportement
   - Pour détecter les erreurs ou comportements inattendus
   - Et s’assurer qu’elles respectent bien la norme et la mémoire

Chaque fonction aura sa propre **fiche `.md`** dans `documentation/explication/fonctions/`, pour détailler :
- ce qu’elle fait,
- comment je l’ai écrite,
- quels cas j’ai testés,
- et mes remarques perso.
