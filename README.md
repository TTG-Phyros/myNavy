# MyNavy

**MyNavy** est un jeu de bataille navale introduit dans un terminal de commande. Grâce à l'utilisation des PID (Processus ID), deux terminaux de commande peuvent communiquer entre eux et permettre de faire se dérouler une partie de bataille navale en temps réel. Les deux joueurs s'affrontent à tour de rôle, et le premier à avoir touché tous les bateaux ennemis remporte la partie.

## 🎮 Gameplayp

Les règles du jeu sont simples et s'inspirent du classique jeu de bataille navale :

- **Joueurs** : La partie se joue entre deux joueurs dans des terminaux de commande distincts.
- **Attaques** : Chaque joueur attaque à tour de rôle, en entrant les coordonnées de l'endroit où ils souhaitent lancer une attaque.
- **Objectif** : Le premier joueur à toucher et couler tous les bateaux ennemis gagne la partie.

### ⚠️ Conditions de victoire :

Le joueur qui réussit à toucher tous les bateaux adverses en premier est déclaré vainqueur.

## 🕹️ Commandes

- **Lancer une attaque** : Chaque joueur entre les coordonnées dans le terminal pour attaquer l'adversaire.
- **Échange d'informations** : Les PID des processus permettent aux deux terminaux de se synchroniser et d'envoyer les résultats de chaque attaque (touché, manqué, coulé).

## 📈 Système de jeu

- **Bateaux à couler** : Chaque joueur a une flotte composée de plusieurs bateaux à protéger.
- **Tour par tour** : Les joueurs s'échangent les tours, l'un attaque pendant que l'autre défend.
- **Système de communication** : Le système PID permet aux deux terminaux de partager l'information sur l'état des attaques.

## 🚧 Fonctionnalités à venir

- [ ] Ajout d'une interface graphique pour jouer en dehors du terminal.
- [ ] Possibilité de jouer contre une IA.
- [ ] Nouveaux modes de jeu (2V2, 5V5).

## 🖼️ Captures d'écran

![In Game](https://github.com/TTG-Phyros/repositoriesPhotos/blob/main/MyNavy/myNavy_In_Game.png)
![Help Menu](https://github.com/TTG-Phyros/repositoriesPhotos/blob/main/MyNavy/myNavy_Help.png)

## 🚀 Installation
### Prérequis

    [MakeFile, GCC]

## Instructions

### Clone le dépôt :

    git clone https://github.com/ton-compte/MyNavy.git

### Accède au dossier du projet :

    cd MyNavy

### Compile le projet :

    make

### Lance le jeu :

- **Joueur 1** : ./my_radar [pos en .txt]
- **Joueur 2** : ./my_radar [pid du joueur 1] [pos en .txt]

### Pour Nettoyer les fichiers :

    make fclean

## Auteur

| [<img src="https://github.com/NattanCochet.png?size=85" width=85><br><sub>Nattan Cochet</sub>](https://github.com/NattanCochet) | [<img src="https://github.com/TTG-Phyros.png?size=85" width=85><br><sub>Nicolas Audibert</sub>](https://github.com/TTG-Phyros)
| :---: | :---: |
