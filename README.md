# Suika Game
<br />

Le jeu suika game est un jeu type 2048 où il faut obtenir le plus grand score possible
en plaçant des fruits dans le plateau de jeu dans le but d'obtenir le plus grand score
possible l'ordre des fruits est le suivant:
cerise->fraise->murs->mandarine->orange->pomme->poire->pêche->ananas->melon->pastèque.
<br />

Vous déposez un maximum de fruits possibles dans le plateau de jeu, et essayez d'avoir
un maximum de fusions pour le score soit grand, et vous perdez lorsqu'un fruit dépasse du
plateau de jeu, sinon il n'y a pas d'autres moyens de perdre la partie.



## Le code et l'organisation des fichiers
<br />
Les fichiers sont organisés de la façon suivante:
<br />

- **src**       : Dossier où les dossiers core contenant les classes utilisés
                    dans le mode console et SDL, le dossier sdl qui contient les
                    les classes pour sdl.le dossier console où se trouve les classes
                    pour le jeu mode console.

- **doc**       : Le fichier doxygen où se trouve la documentation du code orange
                    génére la documentation doxygen avec un make doc là où il y'a
                    le Makefile.

- **data**      :Contient les utilitaires images, sons, polices organisé en 3 sous
                   dossiers utile, fruits et menu et contient aussi le fichier de
                   sauvegarde des parties.

- **bin**       : Répertoire où les executables sont stockés suikasdl et suikacons

- **obj**       : Répertoire comportant les compilations intermédiaires (.o)

- **cahierDesCharges**   :Répertoire contenant le cahier des charges avec la présentation
                           du projet, le diagramme des classes et le diagramme de gant pour 
                           la répartition des taches et éventuellement lors du rendu ou
                           plus tard le pdf ou diaporama pour la soutenance du projet


## Pour compiler
<br />

Pour compiler il y'a un Makefile qui est fourni juste avec la commande make vous avez les fichiers suikacons et suikasdl qu'on peut exécuter avec un ./bin/suikacons ou ./bin/suikasdl qui va les Afficher.


## Les executables
<br />

suikacons: Va afficher le jeu suika game en mode console mais cette version n'est pas complète
car le mode console n'est pas vraiment fait pour ça donc pour un jeu minimum jouable il faut
se tourner vers l'exécutable suikasdl

suikasdl: Pour afficher la version la plus avancée du projet qui est affichée avec la bibliothèque
sdl2 et permet de jouer et de mettre des fruits dans le plateau de jeu



## Equipe
<br />

```
id du projet: 33218

Ba Cheikh
p2109987

BAH MAMADOU 
p2107491

YRIUS MARC 
p2210277

```

