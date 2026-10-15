# Battle of History

Jeu de cartes à collectionner en console, écrit en C++ dans le cadre d'un projet d'ING2.

Vous êtes un scientifique passionné d'histoire qui a trouvé le moyen de ramener à la vie des personnages historiques célèbres. Affrontez d'autres dresseurs avec vos icônes de l'Histoire de France et devenez **LE ROI DES ROIS**.

## Fonctionnalités

- **Comptes joueurs** : création d'un joueur (pseudo + mot de passe), sauvegarde automatique dans `joueurs.txt`.
- **Jouer** : partie en 1 contre 1 entre deux joueurs enregistrés, sur la même console.
- **Caserne** : consultation de sa collection et gestion de son deck.
- **Taverne** : boutique où dépenser ses écus pour acheter des cartes.
- **Règlement** : rappel des règles directement dans le jeu.

## Les cartes

| Type | Rôle | Exemples |
|------|------|----------|
| **Créature** | Personnage historique avec des points de vie et trois attaques (coût 1, 2 et 3 énergies). Classées en *légendaire*, *épique* et *rare*. | Louis XIV, Napoléon, Jeanne d'Arc, Charlemagne, Marie Curie… |
| **Énergie** | Symboles royaux nécessaires pour attaquer. | Épée, Couronne, Sceptre, Main de Justice |
| **Spéciale** | Effets ponctuels qui changent le cours de la partie. | Révélation, Malice, Résurrection, Destruction, Cheval de Troie, Entourloupe… |

L'ensemble des 35 cartes (statistiques, prix) est défini dans [main.cpp](main.cpp).

## Règles en bref

1. **Début de partie** : la première carte du deck est mise de côté face cachée, c'est l'**enjeu**. Le gagnant la récupère dans sa collection, le perdant la perd.
2. **Chaque tour** : on pioche une carte, puis on choisit de la jouer ou non. Une créature jouée peut remplacer la créature active ; les cartes refusées ou remplacées repartent sous la pioche ou au cimetière.
3. **Combat** : la créature active attaque en consommant des énergies. Une créature à 0 PV part au cimetière, et les dégâts excédentaires sont retirés aux points de vie du joueur. Un joueur sans créature en jeu doit dérouler sa pioche jusqu'à en trouver une.
4. **Fin de partie** : un joueur perd quand ses points de vie tombent à 0 ou qu'il n'a plus de créature dans son deck.
5. **Écus** : chaque nouveau joueur commence avec 100 écus ; une victoire rapporte 10 écus, une défaite 5.

## Prérequis

Le jeu utilise l'API Windows (`windows.h`, `system("cls")`, couleurs de la console) : **il ne fonctionne que sous Windows**.

- Un compilateur C++11 (MinGW / GCC)
- [Code::Blocks](https://www.codeblocks.org/) (optionnel, un fichier projet est fourni)

## Compilation et lancement

### Avec Code::Blocks

Ouvrir `Projetv3.cbp`, choisir la cible *Debug* ou *Release*, puis *Build and run* (F9).

### En ligne de commande (MinGW)

```bash
g++ -std=c++11 -Wall -o Projetv3.exe main.cpp Affichage.cpp Carte.cpp Creature.cpp Energie.cpp Hero.cpp Special.cpp
Projetv3.exe
```

Lancer l'exécutable depuis le dossier qui contient `joueurs.txt` pour retrouver les joueurs sauvegardés.

### Configuration de la console

L'affichage est positionné au caractère près. Au démarrage, configurer la fenêtre de la console :

1. Clic droit sur la barre de titre → **Propriétés** → **Police** : *Polices Raster*, taille **10x20**
2. **Configuration** → taille de la fenêtre : **187 x 47**

## Structure du projet

```
.
├── main.cpp            # Point d'entrée : création des cartes, menu principal, sauvegarde
├── Affichage.cpp/.h    # Interface console : accueil, partie, Caserne, Taverne, règlement
├── Carte.cpp/.h        # Classe de base Carte (nom, id, type, prix)
├── Creature.cpp/.h     # Carte Créature (PV, 3 attaques)
├── Energie.cpp/.h      # Carte Énergie
├── Special.cpp/.h      # Carte Spéciale (effet)
├── Hero.cpp/.h         # Joueur : collection, deck, cimetière, énergies, écus
├── joueurs.txt         # Sauvegarde des joueurs (format texte séparé par « | »)
├── Projetv3.cbp        # Projet Code::Blocks
└── PowerPointProjet.pptx  # Présentation du projet
```

## Sauvegarde

Les joueurs sont stockés dans `joueurs.txt` : le nombre de joueurs, puis pour chacun son pseudo, mot de passe, écus, victoires, sa collection et son deck, champs séparés par `|`. Le fichier est réécrit après chaque passage par la Caserne, la Taverne ou la création d'un joueur.

> Les mots de passe y sont enregistrés en clair : ce format convient à un projet scolaire, pas à de vraies données.
