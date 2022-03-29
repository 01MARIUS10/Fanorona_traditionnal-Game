#include<iostream>

#include "Control.hpp"

using namespace std;

int main()
{
    Control game;
    game.terrain_().affiche();
    game.jeu();
    return 0;
}