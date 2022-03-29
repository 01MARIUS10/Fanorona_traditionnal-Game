#include<iostream>
#include<vector>

using namespace std;


class Joueur
{
private:
    vector<vector<int>> pieces;
public:
    //initialise le coordonne des pieces en -1
    Joueur(); 
    void debug_tableau();

    //remplir le coordonne du nbr eme piece
    void set_coordo(int numero_piece,int x,int y) ;
    
    // coordonne ----->le numero de la piece dans le tableau pieces du joueur
    int get_num_piece(int x,int y);
    int getX_of_piece(int numero_piece);
    int getY_of_piece(int numero_piece);
    bool is_aligner();
    
};
