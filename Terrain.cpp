#include "Terrain.hpp"

Terrain::Terrain() //initialise le terrain en 0(vide)
    {
        vector<int> ligne;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                ligne.push_back(0);
            }
            terrain.push_back(ligne);
        }
    }
void Terrain::setpiece_in_terrain(int joueur,int x,int y)//place la piece du joueur dans le terrain
    {
        terrain[x][y]=joueur; //joueur prend comme valeur 1(J1) ou 2(J2)
    }
int Terrain::getpiece(int x,int y)//donne la valeur de la pieces dans une case de coordonne x,y
    {
        return terrain[x][y];
    }
void Terrain::affiche()//affiche le terrain en numero (0 et 1 et 2)
    {
        cout<<endl<<"-----------AFFICHAGE------------"<<endl<<endl;
        for(int i=0;i<3;i++)
        {
            cout<<"\t| ";
            for(int j=0;j<3;j++)
            {
                cout<<terrain[i][j]<<" | " ;
            }
            cout<<endl<<endl;
        }
    }
void Terrain::refresh_terrain(int move[][2],int joueur)
    {
        terrain[move[0][0]][move[0][1]]=0;
        terrain[move[1][0]][move[1][1]]=joueur;
    }