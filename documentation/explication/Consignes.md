# ✅ Consignes générales — Projet Libft (42)

Version du sujet : 16.1  
Source : [`fr.subject_libft_fr_v_16.1.pdf`](../utils/fr.subject_libft_fr_v_16.1.pdf)

---

## 📌 Règles générales

- 💻 **Langage** : Le projet doit être entièrement codé en **C**.
- 📏 **Norme** : Le code **doit respecter la norme 42**, même pour les bonus.
  - Toute faute de norme dans le projet (y compris les bonus) = **0**.
- 💥 **Comportement indéfini** : Aucune fonction ne doit provoquer de **segfault**, **bus error**, **double free**, etc.
- 🧠 **Gestion mémoire** :
  - Toute mémoire allouée (avec `malloc`, etc.) doit être libérée correctement.
  - **Aucun leak** ne sera toléré.
- ⚠️ **Variables globales interdites**.
- 🔁 **Fonctions auxiliaires** : Si besoin, elles doivent être **`static`**.
- 📁 Tous les fichiers doivent être à la **racine du dépôt Git**.
- 🚫 Ne rendez **aucun fichier inutile**.
- 🧪 **Tests personnels** fortement recommandés (non notés).

---

## ⚙️ Makefile

Ton `Makefile` doit obligatoirement contenir les règles suivantes :

- `all`
- `clean`
- `fclean`
- `re`
- `$(NAME)`

🔧 Flags requis à la compilation : `-Wall -Wextra -Werror`

---

## 🧱 Fichier de sortie attendu

- 🎯 Nom du fichier de sortie : `libft.a` (bibliothèque statique)
- 🗂️ Il doit être généré **à la racine** du projet.
- 📦 Créé avec la commande `ar`, **pas** avec `libtool`.

---

## 🎁 Partie bonus

- Pour soumettre la partie bonus :
  - Ajouter une règle `bonus` dans le Makefile.
  - Les fichiers doivent avoir le suffixe `_bonus.c` / `_bonus.h`.
- ⚠️ Les bonus **ne seront évalués que si la partie obligatoire est parfaite** :
  - Toutes les fonctions obligatoires doivent être présentes.
  - Aucune erreur, aucun comportement indéfini.

---

## 🧪 Fonctions autorisées

- La majorité des fonctions de la `libc` sont interdites.
- Seules **`malloc`, `free`, `write`** sont autorisées selon les cas.

👉 Vérifie dans le sujet pour chaque fonction ce qui est permis.

---

## 🧾 Evaluation & rendu

- 🧑‍🤝‍🧑 Le projet sera évalué par **peer-evaluation**.
- 🧠 En cas de correction automatique (**Deepthought**), les erreurs stoppent l’évaluation.
- 📤 Tu dois rendre ton travail sur le **Git assigné** par l’école.
  - Seul ce qui est **sur Git** sera évalué.
  - Bien respecter les **noms de fichiers**, **structure**, et **contenu** demandés.

---

## 💡 Conseils pratiques

- 📁 Organise bien ton dossier (`libft.h`, `Makefile`, `ft_*.c`, etc.).
- ⚠️ Pas de `bonus` si une seule fonction obligatoire est fausse ou manquante.
- 🧪 Fais-toi **un dossier de test** (non noté mais super utile).
- 🧘 Prends le temps de **comprendre chaque fonction** avant de la coder.

---

> 📚 Ce fichier résume les règles principales du projet Libft.  
> Il ne remplace pas le PDF officiel, mais sert de rappel clair et rapide pour ton travail quotidien.