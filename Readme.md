--------------------jeu <FANORONA 3"> MALAGASY implementer en C++--------------------

c'est un duel entre 2 joueurs, le but du jeu est d'aligner en premier  
ses 3 pions. Le plateau de jeu est vide initialement, les joueurs posant leurs pions 
un à un, puis les déplaçant d'une intersection vers une autre afin de tenter de former 
un alignement.


Le plateau de jeu est tracé sur tout type de support : plateau de bois, pierre, terre,
papier, carton... et les pions utilisés sont souvent faits avec ce qui peut être trouvé 
sur place : cailloux, craie, boules de papier...

ce jeu que l'on va implementer,pour l'instant,dans la console:

1)ou le plateau sera un tableau,
2)et les pions comme des chiffres:  1 pour le joueur1
                                    2 pour le joueur2

A chaque deplacement, le joueur precisera la localisation de la piece qu'il souhaiterai deplacer
ainsi que la place destination du pions 
Pour une meilleur lisibilite,a chaque deplacement ,le plateau virtuel sera afficher constament

En cas d'erreur, que ce soit :
                                    1)deplacer des pions adverse
                                    2)deplacer des pions vide :) /ou plutot aucune piece dans la case saisi
                                    3)deplacer vers une case non vide
                                    4)et aussi sans oublier les deplacements illegaux

les deplacements impossibles:

        | 1 | 2 | 3 |
        | 4 | 5 | 6 |
        | 7 | 8 | 9 |

il est impossible de passer de 2 vers 6    ou 6 vers 2   (2 <----> 6)
                                                meme pour   2<---->4 
                                                            4<---->8
                                                            8<---->6
                                                            6<---->2

Au moment ou un des joueur arrive a aligner ses pieces , le Jeu s'arreterai automatiquement
c'est la VICTOIRE 

Ainsi se deroule le programme, 
Au cas ou vous voudrez mettre un commentaire a propos, je serai ravi de les recevoirs sur mariustsiorimbola@gmail.com
mMerci pour la lecture et bon JEUX xD