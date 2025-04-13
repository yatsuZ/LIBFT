# Utiliser la librairie statique `libft.a`

---

## 📦 Qu'est-ce que `libft.a` ?

C’est une **archive statique** (un ensemble de `.o`) générée par le Makefile de ton projet.  
Elle regroupe toutes les fonctions de la lib dans un seul fichier qu’on peut lier à d’autres programmes C.

---

## ⚙️ Étapes pour l'utiliser dans un autre projet

### 1. Compiler la libft

```bash
cd chemin/vers/libft
make
```

Tu obtiens un fichier `libft.a`.

---

### 2. Inclure le header dans ton fichier source

Dans ton fichier `.c` :

```c
#include "libft.h"
```

⚠️ Vérifie que le chemin du header est correct dans ton projet (tu peux l’adapter ou le copier).

---

### 3. Compiler ton projet avec la libft

Exemple si tu as un fichier `main.c` qui utilise des fonctions de `libft` :

```bash
gcc main.c -L. -lft -I./LIBFT
```

- `-L.` : indique où chercher la librairie (`libft.a`)
- `-lft` : cherche `libft.a` (le `lib` est implicite)
- `-I./LIBFT` : indique où se trouve `libft.h`

---

## 💡 Exemple complet

```bash
gcc main.c -L./code/LIBFT -lft -I./code/LIBFT -o mon_programme
```

---

## 🛠 Astuce Makefile

Tu peux aussi ajouter dans ton propre Makefile :

```makefile
LIBFT_DIR = ./code/LIBFT
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) main.c -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)
```

---

## 🔚 Résumé

- Compile ta lib avec `make`
- Inclue `libft.h`
- Lie `libft.a` avec `-L` et `-lft`
