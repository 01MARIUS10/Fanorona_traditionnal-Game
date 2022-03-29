#include "Joueur.hpp"

Joueur::Joueur() //initialise le coordonne des pieces en -1
    {
        for(int numero_piece=0;numero_piece<3;numero_piece++)
        {
            vector<int> coordonne;
            for(int i=0;i<2;i++)
            {
                coordonne.push_back(-1);
            }
            pieces.push_back(coordonne);
            
        }
        
    }
void Joueur::debug_tableau()
    {
        int i(1);
        cout<<"-------------------------------------------"<<endl;
        cout<<"afficher les coordonnes des 3pieces"<<endl; 
        for(auto& elements:pieces)
        {
            cout<<"pieces n°"<<i<<" :  |";
            for (auto& element:elements)
            {
                cout<<element<<"|";
            }
            i++;
            cout<<endl;
        }
        cout<<"-------------------------------------------"<<endl;
    }
void Joueur::set_coordo(int numero_piece,int x,int y) //remplir le coordonne du nbr eme piece
    {
        pieces[numero_piece][0]=x;
        pieces[numero_piece][1]=y;   
    }
int Joueur::get_num_piece(int x,int y) // coordonne ----->le numero de la piece dans le tableau pieces du joueur
    {
        for(int i=0;i<3;i++)
        {
            if((pieces[i][0]==x)||(pieces[i][1]==y))
            {
                return i;  
            }
        }
        return -1;
    }
int Joueur::getX_of_piece(int numero_piece)
    {
        return pieces[numero_piece][0];
    }
int Joueur::getY_of_piece(int numero_piece)
    {
        return pieces[numero_piece][1];
    }
bool Joueur::is_aligner()
    {
        int tabX[3];
        int tabY[3];
        int compteur(0);
        //meme ligne----------
        if((pieces[0][0]==pieces[1][0])&&(pieces[1][0]==pieces[2][0]))
        {
            return true;
        }
        //meme colonne------------
        if((pieces[0][1]==pieces[1][1])&&(pieces[1][1]==pieces[2][1]))
        {
            return true;
        }
        //les obliques----------------
        for(int i=0;i<3;i++)
        {
            tabX[i]=pieces[i][0];
            tabY[i]=pieces[i][1];
        }
        //oblique de pente negatif
        if((tabX[0]==tabY[0])&&(tabX[1]==tabY[1])&&(tabX[2]==tabY[2]))
        {
            return true;
        }
        //oblique de pente positif
        for(int i=0;i<3;i++)
        {
            
            if(((tabX[i]==0) && (tabY[i]==2))||((tabX[i]==2) && (tabY[i]==0)))
            {
                compteur++;
            }
            else if((tabX[i]==1) && (tabY[i]==1))
            {
                compteur++;
            }
            if(compteur==3)
            {
                cout<<"compteur="<<compteur<<endl;
                return true;
            }
        }
        //else-------------
        return false;
    }