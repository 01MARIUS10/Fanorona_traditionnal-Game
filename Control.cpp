#include "Control.hpp"

Control::Control()
{
    cout<<endl<<" sachant que les ligne et colonne sont de 1 a 3 "<<endl;
    cout<<"NOTEZ BIEN ! , l'index 0 est invalide"<<endl<<endl;
    cout<<"Bon jeux :xD  "<<endl<<endl;
    cout<<"Demarer!!!!!!"<<endl;

    cout<<endl<<"____________________________________"<<endl<<endl;
    cout<<" ||\t\t\t\t||"<<endl;
    cout<<" ||\t\t\t\t||"<<endl;
    cout<<"\t||FANORONA TELO||"<<endl;
    cout<<" ||\t\t\t\t||"<<endl;
    cout<<" ||\t\t\t\t||"<<endl;
    cout<<"____________________________________"<<endl<<endl;

    
    play=true;
    move_init();
        
    }
void Control::move_init()
{
    move [0][0]=-1;
    move [0][1]=-1;
    move [1][0]=-1;
    move [1][1]=-1;
    }
Joueur Control::J1_()
{
    return J1;
}
Joueur Control::J2_()
{
    return J2;
}
Terrain Control::terrain_()
{
    return terrain;
}
int Control::switch_joueur(int joueur)
{
    if(joueur==1)
    {
        return 2;
    }
    else if(joueur==2)
    {
        return 1;
    }
    else
        cout<<"error switch joueur,joueur different de 1 et 2"<<endl;
    return -1;
}
int Control::get_line()
{
    int x(-1);
    cout<<"ligne\t: ";
    cin>>x;
    return x;
}
int Control::get_column()
{
    int y(-1);
    cout<<"colonne\t: ";
    cin>>y;
    return y;
}
//-----------------------------------------------------------
void Control::jeu()
{
    int vainceur(0);
    play=!placer();
    if(play)
    {
        vainceur=deplacer();
        cout<<" PARTI FINI : "<<endl;
        cout<<"le Joueur "<<vainceur<<" a gagner la partie"<<endl;
    }
}
//step1 - remplir le terrain piece par piece/return play
bool Control::placer()
{
    int x(-1),y(-1);
    int compteur1(0);
    int compteur2(0);
    for (int numero_piece=0;numero_piece<3;numero_piece++)//mettre en places les trois pieces 
    {
        for(int joueur=1;joueur<=2;joueur++) //le tour de jeu switch entre les deux joueurs 
        {
            //saisi des coordonnees
            cout<<"entrer le "<<numero_piece+1<<"eme piece du JOUEUR"<<joueur<<"! "<<endl;
            x=get_line();
            y=get_column();

            //nuance index realite et programme
            x--;
            y--;

            //verifier la compatibilites des valeus saisi par les joueurs 
            while( (!terrain.getpiece(x,y)==0) || (x<0) || (x>2)|| (y<0) || (y>2))
            {
                if((x<0) || (x>2 )|| (y<0) || (y>2))
                {
                    cout<<"case inexistant,reesayer a nouveau"<<endl;
                }
                else if(terrain.getpiece(x,y)!=0)/////////////////////////////////////////////////
                {
                    cout<<"error ,place deja engage ,retapez a nouveau "<<endl;
                }

                //en cas d'erreur(incompatibilite des valeurs) le programme redemande au joueur de saisir de nouveau
                x=get_line();
                y=get_column();
                cout<<endl;

                //nuance index realite et programme
                x--;
                y--;
            }
                
            //les coordonnes filtrée sont entrer dans le terrain
            terrain.setpiece_in_terrain(joueur,x,y);

            //puis dans les donnes des joueurs ,le tableau pieces 3*2
            if(joueur==1)
            {
                J1.set_coordo(compteur1,x,y);
                compteur1++;
            }
            else if(joueur==2)
            {
                J2.set_coordo(compteur2,x,y);
                compteur2++;
            }

            //afficher le tableau apres chaque pieces placeés  
            terrain.affiche();

            //control si le joueur a gagner
            if(numero_piece==2)
            {
                play=is_win(joueur);
                if(play)
                {
                    cout<<"PARTI FINI :"<<endl;
                    cout<<"le joueur"<<joueur<<" a gagner la partie"<<endl;
                    return play;
                }
            }
        }
    }
    return false;
}
   
//etape 2 deplacement des pieces
int Control::deplacer()
{
    cout<<endl<<"les pieces sont mis en place, deplacez maintenant"<<endl;
    int joueur(1);
    while(play)
    {
            
        cout<<"JOUEUR "<<joueur<<" :";

            //deplacement de chaque joueur
            play=move_pieces(joueur);
            //uploader les valeurs du terrain
            terrain.refresh_terrain(move,joueur);
            //afficher le tableau apres chaque pieces placeés  
            terrain.affiche();

            //switcher les tour des joueurs
            joueur=switch_joueur(joueur);
            cout<<"--------------------------------"<<endl<<endl;
        }
        return joueur;
    }
//regarde si la partie est fini
bool Control::move_pieces(int joueur)//---------------------------->>>void deplacer
    {
        int numero_piece;
        bool refresh(true);
        //demande ,analyse les coordonnees saisi
        // et stock dans move[0]
        move_init();
        while(refresh)
        {
            piece_to_move(joueur);
            refresh=place_to_move(joueur);
        }
        
        //mettre a jour les coordonnées de la pieces deplacer
        if(joueur==1)
        {
            numero_piece=J1.get_num_piece(move[0][0],move[0][1]);
            J1.set_coordo(numero_piece,(move[1][0]),move[1][1]);
        }
        else if(joueur==2)
        {
            numero_piece=J2.get_num_piece(move[0][0],move[0][1]);
            J2.set_coordo(numero_piece,(move[1][0]),move[1][1]);
        }
        
        return !is_win(joueur);
    }
//verifie si le joueur a gagnée
bool Control::is_win(int joueur)
    {
        if(joueur==1)
        {
            return J1.is_aligner();
        }
        else if(joueur==2)
        {
            return J2.is_aligner();
        }

        return false;
    }
    
//prend la piece(x,y) a deplacer etla stocke dans move[joueur] 
void Control::piece_to_move(int joueur)
    {
        //demmander la piece a bouger
        cout<<endl<<endl;
        cout<<"Deplacer quel pieces :"<<endl;
        int x=get_line();
        int y=get_column();

        //nuance index realite et programme
        x--;
        y--;

        //verifiere si la case appartient au joueur
        while(  (terrain.getpiece(x,y)!=joueur) || (x<0) || (x>2)|| (y<0) || (y>2)  )
        {
            if((x<0) || (x>2 )|| (y<0) || (y>2))
            {
                cout<<"ERREUR :case inexistant,reesayer a nouveau"<<endl;
            }
            else if(terrain.getpiece(x,y)!=0)
            {
                cout<<"ERREUR :piecesn introuvable ,retapez a nouveau "<<endl;
            }
            //en cas d'erreur(incompatibilite des valeurs) le programme redemande au joueur de saisir de nouveau
            x=get_line();
            y=get_line();
            cout<<endl;

            //nuance index realite et programme
            x--;
            y--;

        }
        //apres verification .........
        joueur--;
        move[0][0]=x;//on stock l'abscisse
        move[0][1]=y;//on stock l'ordonne*
        /* piece a bouger OK */
    }
//get la place a deplacer la piece dans move[0]
bool Control::place_to_move(int joueur)
    {
        //cette booleen reinitialise le sais de la piece a deplacer apres 3essai
        int compteur_erreur(3);
        int x(-1) , y(-1);
        bool is_legal_move(false);

        while(!is_legal_move)
        {
            cout<<"Deplacer ou :"<<endl;
            x=get_line();
            y=get_column();
            cout<<endl;

            //nuance index realite et programme
            x--;
            y--;

            while( ((terrain.getpiece(x,y)!=0)) || (x<0) || (x>2)|| (y<0) || (y>2))
            {
                if((x<0) || (x>2 )|| (y<0) || (y>2))
                {
                    cout<<"ERREUR :case inexistant,reesayer a nouveau"<<endl;
                }
                else if(terrain.getpiece(x,y)!=0)
                {
                    cout<<"ERREUR :place deja prise ,retapez a nouveau "<<endl;
                }
                //en cas d'erreur(incompatibilite des valeurs) le programme redemande au joueur de saisir de nouveau
                x=get_line();
                y=get_column();
                cout<<endl;

                //nuance index realite et programme
                x--;
                y--;
                //compter les nbr d'erreur sur la place choisi a mettre 
                //apres 3 essai on reprend une nouvelle pieces a deplacer
                compteur_erreur--;
                if(compteur_erreur==0)
                    return true;

            }
            is_legal_move=etude_de_cas(x,y);
        }
        
        //apres verification .........
        joueur--;
         
        return false;//les erreur n'a pas depasser le compteur
    }
//est ce que le deplacement est legal
bool Control::etude_de_cas(int x,int y)//--------------------->>>place_to_move
    {
        //Aucun mouvement
        if(move[0][0]==x && move[0][1]==y)
        {
            cout<<"ERREUR :vous n'avez effectuer aucun deplacement"<<endl<<endl;
            return false;
        }
        //trier le depl diagonal pres non authoriser
        if( ( ((move[0][0]==1)||(move[0][1]==1)) && ((move[0][0]!=move[0][1])) )   &&   ( ((x==1)||(y==1)) && (x!=y)) )
        {
            cout<<"ERREUR :deplacement diagonal non authoriser"<<endl<<endl;
            return false;
        }
        //tout mouvement qui saute des casses
        if( ((move[0][0]-x==-2)||(move[0][0]-x==2)) && ((move[0][1]-y==-2)||(move[0][1]-y==2)))
        {
            cout<<"ERREUR :le saut de case est interdit "<<endl;
            return false;
        }
        move[1][0]=x;
        move[1][1]=y;
        return true;
    }