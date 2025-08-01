# get\_next\_line - 42

## 📚 Description

`get_next_line` est un projet fondamental de l'école 42 qui consiste à écrire une fonction capable de lire un fichier ligne par ligne. Ce projet permet d'approfondir la gestion de la mémoire, les appels système comme `read()`, et la manipulation de buffers dynamiques.

---

## 🔧 Fonction principale

```c
char *get_next_line(int fd);
```

Cette fonction lit le contenu d’un descripteur de fichier et renvoie une ligne complète à chaque appel, jusqu’à atteindre la fin du fichier ou une erreur.

---

## 🧪 Fonctionnalités

* Lecture par blocs grâce à un buffer défini par `BUFFER_SIZE`
* Retour d’une ligne complète avec le `\n` (sauf dernière ligne sans saut)
* Utilisation de mémoire dynamique pour reconstituer les lignes
* Utilisation d'une variable statique pour garder l'état entre les appels
* Gestion d'erreurs : descripteur invalide, `read()` défaillant, etc.

---

## 📦 Fichiers principaux

* `get_next_line.c` : logique principale de lecture et découpage
* `get_next_line_utils.c` : fonctions utilitaires (strlen, strchr, etc.)
* `get_next_line.h` : prototype de la fonction et includes

---

## 🖼️ Note du projet

<p align="center">
 <img width="199" height="169" alt="image" src="https://github.com/user-attachments/assets/5d1708a5-fc33-4d29-893c-405e83ab0581" />
</p>

---

## 🫐 Auteur

* Océane (ocviller)
* Projet réalisé à 42 Paris, 2025
