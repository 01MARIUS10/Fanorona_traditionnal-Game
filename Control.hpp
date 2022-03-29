#include<iostream>

#include "Joueur.hpp"
#include "Terrain.hpp"

using namespace std;

class Control
{
private:
    bool play;
    Joueur J1;
    Joueur J2;
    Terrain terrain;
    int move[2][2];


public:
    Control();
    void move_init();
    Joueur J1_();
    Joueur J2_();
    Terrain terrain_();
    int switch_joueur(int joueur);
    int get_line();
    int get_column();
    void jeu();
    bool placer();
    int deplacer();
    bool move_pieces(int joueur);
    bool is_win(int joueur);
    void piece_to_move(int joueur);
    bool place_to_move(int joueur);
    bool etude_de_cas(int x,int y);
};
