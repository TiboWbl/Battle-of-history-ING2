#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>
#include <iostream>
#include "Affichage.h"
#include "Hero.h"
#include "Carte.h"


void Color(int couleurDuTexte,int couleurDeFond)
{

    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);

    /*    (0 : NOIR) (1 : BLEU FONCE)  (2 : VERT FONCE) (3 : TURQUOISE) (4 : Rouge FONCE) (5 : VIOLET)
        (6 : VERT CACA D OIE) (7 : GRIS CLAIR) (8 : GRIS FONCE) (9 : BLEU FLUO) (10 : VERT FLUO) (11 : TURQUOISE)
        (12 : ROUGE FLUO ) (13 : VIOLET 2) (14 : JAUNE) (15 : BLANC)
    */
}
void gotoligcol( int lig, int col )
{
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
void JEU()
{
    gotoligcol(8,86);
    Color(14,0);
    std :: cout << "BATTLE OF HISTORY";
    gotoligcol(9,90);
    Color(14,0);
    std :: cout << "( FRANCE )";
}

void TUTO()
{
    gotoligcol(0,0);
    std :: cout << "IMPORTANT" << std::endl << std::endl;
    std::cout << "Faire clique droit sur la barre d'outil de cette fenetre -> PROPRIETES -> POLICE" << std::endl << std ::endl;
    std :: cout <<"Mettre la police : POLICES RASTER, Taille : 10x20"<< std :: endl <<std::endl;
    std::cout << "Allez dans CONFIGURATION -> TAILLE DE LA FENETRE 187x47" << std::endl << std::endl << std:: endl;
    system("Pause");
}


int Ecran_Acceuil()
{
    unsigned choix=0;
    int i;
    char carre;
    char rectangle;
    char triangle;
    char fleche;
    system("cls");
    fleche=0x1A;
    triangle=0x10;
    carre=0xDB;
    rectangle=0xDC;

    do
    {
        for (i=53; i<135; i++)
        {
            if(i<78)
            {
                Color(1,0);
            }
            else if (i<109)
            {
                Color(15,0);
            }
            else if (i>=110)
            {
                Color(4,0);
            }
            gotoligcol(6,i);
            std :: cout << rectangle;
            gotoligcol(27,i);
            std :: cout << rectangle;
        }


        Color(1,0);
        gotoligcol(6,53); ///coin haut gauche
        std :: cout << rectangle;
        gotoligcol(27,53); /// coin bas gauche
        std :: cout << rectangle;
        for (i=7; i<28; i++)
        {
            Color(1,0);
            gotoligcol(i,53);
            std :: cout << carre;
            Color(4,0);
            gotoligcol(i,134);
            std :: cout << carre;
        }

        JEU();

        Color(1,0);
        gotoligcol(13,53);
        std :: cout << carre;
        gotoligcol(13,87);
        Color(14,0);
        std :: cout << triangle;
        std :: cout <<"    JOUER ";
        gotoligcol(13,100);
        std :: cout << fleche << " 1";
        Color(1,0);
        gotoligcol(15,53);
        std :: cout << carre;
        Color(14,0);
        gotoligcol(15,87);
        std :: cout << triangle;
        std :: cout <<"   CASERNE ";
        gotoligcol(15,100);
        std :: cout << fleche << " 2";
        Color(1,0);
        gotoligcol(17,53);
        std :: cout << carre;
        Color(14,0);
        gotoligcol(17,87);
        std :: cout << triangle;
        std :: cout <<"   TAVERNE";
        gotoligcol(17,100);
        std :: cout << fleche << " 3";
        Color(1,0);
        gotoligcol(19,53);
        std :: cout << carre;
        Color(14,0);
        gotoligcol(19,87);
        std :: cout << triangle;
        std :: cout <<"  REGLEMENT ";
        gotoligcol(19,100);
        std :: cout << fleche << " 4";
        Color(1,0);
        gotoligcol(21,53);
        std :: cout << carre;
        Color(14,0);
        gotoligcol(21,87);
        std :: cout << triangle;
        std :: cout <<" NEW JOUEUR   ";
        gotoligcol(21,100);
        std :: cout << fleche << " 5";
        Color(1,0);
        gotoligcol(21,53);
        std :: cout << carre;
        gotoligcol(23,87);
        Color(15,0);
        gotoligcol(26,55);
        std :: cout << "Veuillez entrer un chiffre ... ";

        do
        {
            std::cin>>choix;
            Color(15,4);
            gotoligcol(26,94);
            if ((choix!=1)&&(choix!=2)&&(choix!=3)&&(choix!=4)&&(choix!=5))
            {
                std :: cout << "Choix non valide !! ... ";
                Sleep(2000);
                Color(0,0);
                gotoligcol(26,94);
                std::cout<<"                          ";
                gotoligcol(26,55);
                Color(15,0);
                std :: cout << "Veuillez entrer un chiffre ...       ";
                gotoligcol(26,86);
            }
        }
        while((choix!=1)&&(choix!=2)&&(choix!=3)&&(choix!=4)&&(choix!=5));
        Color(15,0);
        system("cls");
    }
    while (choix>6);
    system("cls");
    return choix;
}


int Reglement ()
{
    int retour;
    do
    {
        gotoligcol(1,75);
        Color(5,15);
        printf(" JEU DE CARTES A COLLECTIONNER \n\n");
        Color(11,0);
        std :: cout << "\t Vous etes un scientifique chevronne et passionne d'histoire qui a trouve un moyen de ramener a la vie des personnages historiques celebres. Vous avez fait part de " << std :: endl << std :: endl;
        std :: cout << "\t vos recherches au monde entier et une communaute de de dressseur passione d histoire a vu le jour. Affrontez vous des des comabats acharnes avec vos differents " << std :: endl << std :: endl;
        std :: cout << "\t icones historiques que vous avez acquis et devenez LE ROI DES ROIS."  << std :: endl << std :: endl;
        Color(12,0);
        std :: cout << "1. MATERIEL :" << std :: endl << std :: endl;
        Color(11,0);
        std :: cout << "\t - Cartes ENERGIES, ici caracterisees par les differents symboles des rois de France, a savoir : sceptre, epee, couronne et la main de la justice."  << std :: endl << std :: endl;
        std :: cout << "\t - Cartes CREATURES, ici caracterisees par les differents rois et reines de France celebres mais aussi par des peronnages qui ont marqué l Histoire."  << std :: endl << std :: endl;
        std :: cout << "\t - Cartes SPECIALES, qui sont des cartes qui peuvent modifier le cours de la partie avec des actions variees."  << std :: endl << std :: endl;
        std :: cout << "\t - Des ECUS, qui sont le syteme de monnaie du jeu. Vous pouvez en acquerir en gagant des combats et vous pouvez les depenser pour acheter des cartes de type ENERGIE," << std :: endl << std :: endl;
        std :: cout << "\t CREATURE ou encore SPECIALE dans la caserne du jeu." << std :: endl << std :: endl;
        Color(12,0);
        std :: cout << "2. DEBUT D UNE PARTIE :" << std :: endl << std :: endl;
        Color(11,0);
        std :: cout << "\t Au debut de chaque partie, la 1ere carte du Deck (sur le dessus donc) est prise et placee a part, face cachee : c est l enjeu. Le gagnant de la partie" << std :: endl << std :: endl;
        std :: cout << "\t gagne cette carte qui integrera sa collection et le perdant n aura plus cette carte dans sa collection." << std :: endl << std :: endl;
        Color(12,0);
        std :: cout << "3. DEROULEMENT D UNE PARTIE :" << std :: endl << std :: endl;
        Color(11,0);
        std :: cout << "\t Au debut de chaque tour une nouvelle carte de la pioche est tiree. Le joueur peut decider de la jouer ou pas. Si la carte est jouee elle peut (dans le cas d une carte creature" << std :: endl << std :: endl;
        std :: cout << "\t ou speciale persistante) remplacer la carte active correspondante (remplacer la creature en jeu ou la speciale persistante). Les cartes refusees (non jouees) ainsi que les" << std :: endl << std :: endl;
        std :: cout << "\t cartes remplacees peuvent repartir sous la pioche ou au sommet du cimetiere. Les cartes creatures tuees (points de vie a 0) vont au sommet du cimetiere.Les points de degat" << std :: endl << std :: endl;
        std :: cout << "\t excedentaires vont se soustraire aux points de vie du joueur. Quand le joueur dont c est le tour de jeu n a pas de creature posee(parce qu elle vient de se faire tuer) il" << std :: endl << std :: endl;
        std :: cout << "\t doit derouler sa pioche (prendre au sommet, remettre dessous,sans jouer) jusqu a en trouver une qu il doit alors obligatoirement poser." << std :: endl << std :: endl;
        Color(12,0);
        std :: cout << "4. FIN DE LA PARITE :" << std :: endl << std :: endl;
        Color(11,0);
        std :: cout << "\t La partie prend fin lorsque les points de vie d un joueur arrivent a 0. Pour qu un joueur gagne la partie, il faut soit que le joueur adverse n est plus de carte creature" << std :: endl << std :: endl;
        std :: cout << "\t dans son deck ou alors que vous lui faites descendre ses points de vie a 0 en l attaqauant avec vos cartes creatures." << std :: endl << std :: endl;
        Color(12,0);
        std :: cout << "5. VOCABULAIRE :" << std :: endl << std :: endl;
        Color(11,0);
        std :: cout << "\t TAVERNE   : Lieu ou vous pouvez acheter des cartes (SPECIALES, CREATURES, ENERGIES)." << std :: endl << std :: endl;
        std :: cout << "\t CASERNE   : Lieu ou vous pouvez consulter votre collection." << std :: endl << std :: endl;
        std :: cout << "\t ECUS      : Monnaie du jeu. Chaque nouveau joueur demarre le jeu avec une somme de 10 ecus." << std :: endl << std :: endl;
        std :: cout << "\t             En cas de victoire : +10 ecus." << std :: endl << std :: endl;
        std :: cout << "\t             En cas de defaite : +5 ecus." << std :: endl << std :: endl;
        std :: cout << "\t CIMETIERE : Lieu ou vont les cartes mortes au combats." << std :: endl << std :: endl;

        Color(6,0);
        std :: cout << "Saisissez : " << std :: endl;
        std :: cout << "0. Pour revenir a l'acceuil...\t";
        Color(15,0);
        std :: cin >> retour;
        system("cls");
    }
    while (retour!=0);
    return retour;

}

int chercheHero(std::vector<Hero> hero,std::string _pseudo,std::string _mdp)
{
    int a=300;
    for(unsigned i=0; i<hero.size(); i++)
    {
        if((_pseudo==hero[i].getPseudo())&&(_mdp==hero[i].getMdp()))
            return i;
    }
    Color(15,4);
    std::cout << std :: endl <<"Pas de pseudo correspondant dans la base de donnee, verifier l orthographe du pseudo"<<std::endl;
    Color(15,0);
    return a;
}

std::vector <Hero> Caserne(std::vector<Hero> hero,std::vector<Carte*> Collection)
{
    int retour;
    int x;

    char coin1;
    char coin2;
    char trait1;
    char trait2;

    std :: string pseudo;
    std :: string mdp;

    coin1 = 0xD9;
    coin2 = 0xDA;
    trait1 = 0xB3;
    trait2 = 0xC4;

    gotoligcol(6,72);
    Color(11,0);
    std :: cout << coin2;
    gotoligcol(7,72);
    std :: cout << trait1;
    gotoligcol(6,73);
    std :: cout << trait2;
    gotoligcol(6,74);
    std :: cout << trait2;
    gotoligcol(7,73);
    Color(15,0);
    std :: cout << " Veuillez entrer votre pseudo : ";
    Color(11,0);
    gotoligcol(10,125);
    std :: cout << coin1;
    gotoligcol(9,125);
    std :: cout << trait1;
    gotoligcol(10,124);
    std :: cout << trait2;
    gotoligcol(10,123);
    std :: cout << trait2;
    gotoligcol(9,73);
    Color(15,0);
    std :: cout << " Veuillez entrer votre mot de passe : ";
    gotoligcol(7,106);
    std :: cin >> pseudo;
    gotoligcol(9,113);
    std :: cin >> mdp;
    gotoligcol(12,10);


    x=chercheHero(hero,pseudo,mdp);
    if(x!=300)
    {
        hero[x].affichHero(Collection);
    }
    do
    {
        Color(6,0);
        retour=0;
    }
    while (retour!=0);
    return hero;
}


Hero NewJoueur (std::vector<Carte*> Bibliotheque)
{
    int retour;
    char carre;
    char rectangle;
    char trait1;
    char trait2;
    char trait8;
    int i;

    std :: string nom;
    std :: string prenom;
    std :: string pseudo;
    std :: string mdp;
    std :: string cmdp;

    trait1=0xC4;
    trait2=0xBA;
    trait8=0xCD;
    carre=0xDB;
    rectangle=0xDC;

    do
    {
        system("cls");
        Color(14,0);
        for (i=72; i<115; i++)
        {
            gotoligcol(6,i);
            std :: cout << trait8;
            gotoligcol(27,i);
            std :: cout << trait8;
            gotoligcol(11,i);
            std :: cout << trait1;

        }

        for (i=7; i<27; i++)
        {
            gotoligcol(i,71);
            std :: cout << trait2;
            gotoligcol(i,115);
            std :: cout << trait2;

        }

        gotoligcol(12,73);
        std :: cout << "NOM : ";
        gotoligcol(14,73);
        std :: cout << "PRENOM : ";
        gotoligcol(16,73);
        std :: cout << trait1;
        gotoligcol(18,73);
        std :: cout << "PSEUDO : ";
        gotoligcol(20,73);
        std :: cout << "MOT DE PASSE : ";
        gotoligcol(22,73);
        std :: cout << "CONFIRMATION MDP : ";
        gotoligcol(24,73);
        std :: cout << trait1;
        gotoligcol(26,73);
        std :: cout << "Annuler -> 0 / Confirmer -> 1 : ";
        gotoligcol(8,85);
        std :: cout << "BATTLE OF HISTORY";
        gotoligcol(9,88);
        std :: cout << "( IDENTITE )";
        Color(15,0);
        gotoligcol(12,79);
        std :: cin >> nom;
        gotoligcol(14,82);
        std :: cin >> prenom;
        gotoligcol(18,82);
        std :: cin >> pseudo;
        gotoligcol(20,88);
        std :: cin >> mdp;
        gotoligcol(22,92);
        std :: cin >> cmdp;
        if (mdp!=cmdp)
        {
            Color(14,0);
            gotoligcol(22,73);
            std :: cout << "CONFIRMATION MDP :                       ";
            gotoligcol(22,92);
            Color(15,4);
            std :: cout << "Plus qu une chance !";
            Sleep(3000);
            Color(14,0);
            gotoligcol(22,73);
            std :: cout << "CONFIRMATION MDP :                       ";
            gotoligcol(22,92);
            Color(15,0);
            std :: cin >> cmdp;

            if (mdp!=cmdp)
            {
                //return 0;
            }
        }
        Color(15,0);
        gotoligcol(26,105);
        std :: cin >> retour;

///////////////////////////////////////////////////////////////////////////

        if(retour==1)
        {
            system("cls");
            Hero H(pseudo,mdp);


            for (i=10; i<79; i++)
            {
                gotoligcol(6,i);
                std :: cout << rectangle;
            }

            for (i=107; i<176; i++)
            {
                gotoligcol(6,i);
                std :: cout << rectangle;
            }

            for (i=10; i<176; i++)
            {
                gotoligcol(51,i);
                std :: cout << rectangle;
            }

            for (i=7; i<52; i++)
            {
                gotoligcol(i,10);
                std :: cout << carre;
                gotoligcol(i,175);
                std :: cout << carre;
            }

            ///"""""""""""""""""""""""""""""""""""""

            for (i=15; i<50; i++)
            {
                Color(5,0);
                gotoligcol(8,i);
                std :: cout << trait8;
                gotoligcol(13,i);
                std :: cout << trait8;
            }


            for (i=9; i<13; i++)
            {
                Color(5,0);
                gotoligcol(i,14);
                std :: cout << trait2;
                gotoligcol(i,50);
                std :: cout << trait2;
            }

            gotoligcol(15,20);
            Color(5,0);
            std :: cout << " CARTE CREATURE EPIQUE";




            /// ''''''''''''''''''''''''''''  ///

            for (i=55; i<90; i++)
            {
                Color(9,0);
                gotoligcol(8,i);
                std :: cout << trait8;
                gotoligcol(25,i);
                std :: cout << trait8;
            }


            for (i=9; i<25; i++)
            {
                Color(9,0);
                gotoligcol(i,54);
                std :: cout << trait2;
                gotoligcol(i,90);
                std :: cout << trait2;
            }

            gotoligcol(27,60);
            Color(9,0);
            std :: cout << " CARTES CREATURES RARES";

///''''''''''''''''''''''''''''''''

            for (i=95; i<130; i++)
            {
                Color(10,0);
                gotoligcol(8,i);
                std :: cout << trait8;
                gotoligcol(25,i);
                std :: cout << trait8;
            }


            for (i=9; i<25; i++)
            {
                Color(10,0);
                gotoligcol(i,94);
                std :: cout << trait2;
                gotoligcol(i,130);
                std :: cout << trait2;
            }

            gotoligcol(27,104);
            Color(10,0);
            std :: cout << "CARTES SPECIALES";

///'''''''''''''''''''''''

            for (i=135; i<170; i++)
            {
                Color(15,0);
                gotoligcol(8,i);
                std :: cout << trait8;
                gotoligcol(47,i);
                std :: cout << trait8;
            }



            for (i=9; i<47; i++)
            {
                Color(15,0);
                gotoligcol(i,134);
                std :: cout << trait2;
                gotoligcol(i,170);
                std :: cout << trait2;
            }

            gotoligcol(49,140);
            Color(15,0);
            std :: cout << "     CARTES ENERGIES";


            gotoligcol(40,15);
            std :: cout << "TOTAL DE CARTES : 23";
            gotoligcol(41,15);
            std :: cout << "     - 1 CARTE EPIQUE";
            gotoligcol(42,15);
            std :: cout << "     - 5 CARTES RARES";
            gotoligcol(43,15);
            std :: cout << "     - 5 CARTES SPECIALES";
            gotoligcol(44,15);
            std :: cout << "     - 12 CARTES ENERGIES";

            H.ajouterCarte(Bibliotheque,6);
            H.ajouterCarte(Bibliotheque,10);
            H.ajouterCarte(Bibliotheque,12);
            H.ajouterCarte(Bibliotheque,13);
            H.ajouterCarte(Bibliotheque,16);
            H.ajouterCarte(Bibliotheque,21);
            H.ajouterCarte(Bibliotheque,22);
            H.ajouterCarte(Bibliotheque,22);
            H.ajouterCarte(Bibliotheque,22);
            H.ajouterCarte(Bibliotheque,23);
            H.ajouterCarte(Bibliotheque,23);
            H.ajouterCarte(Bibliotheque,23);
            H.ajouterCarte(Bibliotheque,24);
            H.ajouterCarte(Bibliotheque,24);
            H.ajouterCarte(Bibliotheque,24);
            H.ajouterCarte(Bibliotheque,25);
            H.ajouterCarte(Bibliotheque,25);
            H.ajouterCarte(Bibliotheque,25);
            H.ajouterCarte(Bibliotheque,27);
            H.ajouterCarte(Bibliotheque,34);
            H.ajouterCarte(Bibliotheque,35);
            H.ajouterCarte(Bibliotheque,34);
            H.ajouterCarte(Bibliotheque,35);
            H.Affiche_deck_Newjoueur();
            return H;

        }

        if(retour==0)
        {
            return Hero();
        }
    }
    while ((retour!=0)&&(retour!=1));
    return Hero();
}

std::vector <Hero> Taverne (std::vector<Hero> hero,std::vector<Carte*> Bibliotheque)
{
    int retour;
    int i;
    std :: string pseudo;
    char trait2;
    char trait8;
    char coeur;
    char pique;
    char carreau;
    char trefle;

    coeur=0x03;
    carreau=0x04;
    trefle=0x05;
    pique=0x05;
    trait2=0xBA;
    trait8=0xCD;

    do
    {
        gotoligcol(1,85);
        Color(5,15);
        printf(" TAVERNE \n\n");
        Color(11,0);
        std :: cout << "  Bienvenu dans la taverne de BATTTLE OF HISTORY. Ici vous pouvez acquerir des cartes de touutes sortes. Faites vous plaisir !! " << std :: endl << std :: endl << std :: endl;
        Color(12,0);
        std :: cout << "\t CARTES CREATURES" << std :: endl << std :: endl;
        ///-------------------------------- CARTES LEG ------------------------------------ ///

/// LOUIS XIV

        Color(6,0);
        gotoligcol(8,1);
        std :: cout << "------------------------------------------------------------------------------------LEGENDAIRE--------------------------------------------------------------------------------------------" << std :: endl << std :: endl;
        Color(11,0);
        std :: cout << "  RAPPEL sur les cartes ENERGIES et leurs symboles: EPEE -> E, SCEPTRE -> S, COURONNE -> C, MAIN DE LA JUSTICE -> J";

        for (i=5; i<35; i++)
        {
            Color(6,0);
            gotoligcol(12,i);
            std :: cout << trait8;
            gotoligcol(29,i);
            std :: cout << trait8;
        }

        for(i=6; i<34; i++)
        {

            gotoligcol(17,i);
            std :: cout << trait8;
        }

        for (i=13; i<29; i++)
        {
            Color(6,0);
            gotoligcol(i,4);
            std :: cout << trait2;
            gotoligcol(i,35);
            std :: cout << trait2;
        }
        gotoligcol(14,5);
        std :: cout << " LOUIS XIV \t    72hp";
        gotoligcol(15,5);
        std :: cout << " (1643-1715)";
        gotoligcol(19,5);
        std :: cout << " ATT 1: \t      C \t25";
        gotoligcol(21,5);
        std :: cout << " ATT 2: \t     C C\t30";
        gotoligcol(23,5);
        std :: cout << " ATT 3: \t    C C C\t38";
        gotoligcol(27,20);
        Color(15,0);
        std :: cout << "1";

        /// NAPOLEON ///

        for (i=45; i<75; i++)
        {
            Color(6,0);
            gotoligcol(12,i);
            std :: cout << trait8;
            gotoligcol(29,i);
            std :: cout << trait8;
        }

        for(i=46; i<74; i++)
        {

            gotoligcol(17,i);
            std :: cout << trait8;
        }

        for (i=13; i<29; i++)
        {
            Color(6,0);
            gotoligcol(i,44);
            std :: cout << trait2;
            gotoligcol(i,75);
            std :: cout << trait2;
        }
        gotoligcol(14,45);
        std :: cout << " NAPOLEON  \t    52hp";
        gotoligcol(15,45);
        std :: cout << " (1769-1821)";
        gotoligcol(19,45);
        std :: cout << " ATT 1: \t      S \t25";
        gotoligcol(21,45);
        std :: cout << " ATT 2: \t     S S\t31";
        gotoligcol(23,45);
        std :: cout << " ATT 3: \t    S S S\t39";
        gotoligcol(27,60);
        Color(15,0);
        std :: cout << "2";

/// JEANNE ///

        for (i=85; i<115; i++)
        {
            Color(6,0);
            gotoligcol(12,i);
            std :: cout << trait8;
            gotoligcol(29,i);
            std :: cout << trait8;
        }

        for(i=86; i<114; i++)
        {

            gotoligcol(17,i);
            std :: cout << trait8;
        }

        for (i=13; i<29; i++)
        {
            Color(6,0);
            gotoligcol(i,84);
            std :: cout << trait2;
            gotoligcol(i,115);
            std :: cout << trait2;
        }
        gotoligcol(14,85);
        std :: cout << " JEANNE D ARC  \t    19hp";
        gotoligcol(15,85);
        std :: cout << " (1412-1431)";
        gotoligcol(19,85);
        std :: cout << " ATT 1: \t      J \t0";
        gotoligcol(21,85);
        std :: cout << " ATT 2: \t     J J\t0";
        gotoligcol(23,85);
        std :: cout << " ATT 3: \t    J J J\t50";
        gotoligcol(27,100);
        Color(15,0);
        std :: cout << "3";

        Color(11,0);
        gotoligcol(33,1);
        std :: cout << "  Prix a l unite des cartes legendaires: 130 ECUS..." << std :: endl << std :: endl << std :: endl;


        /// ----------------------------------- CARTES EPIQUES----------------------------------------///


        Color(5,0);
        std :: cout << "--------------------------------------------------------------------------------------EPIQUE-----------------------------------------------------------------------------------------------" << std :: endl << std :: endl;
        Color(11,0);
        std :: cout << "  RAPPEL sur les cartes ENERGIES et leurs symboles: EPEE -> E, SCEPTRE -> S, COURONNE -> C, MAIN DE LA JUSTICE -> J";

        /// CHARLEMAGNE ///

        for (i=5; i<35; i++)
        {
            Color(5,0);
            gotoligcol(40,i);
            std :: cout << trait8;
            gotoligcol(57,i);
            std :: cout << trait8;
        }

        for(i=6; i<34; i++)
        {

            gotoligcol(45,i);
            std :: cout << trait8;
        }

        for (i=41; i<57; i++)
        {
            Color(5,0);
            gotoligcol(i,4);
            std :: cout << trait2;
            gotoligcol(i,35);
            std :: cout << trait2;
        }
        gotoligcol(42,5);
        std :: cout << " CHARLEMAGNE \t    46hp";
        gotoligcol(43,5);
        std :: cout << " (768-814)";
        gotoligcol(47,5);
        std :: cout << " ATT 1: \t      S \t0";
        gotoligcol(49,5);
        std :: cout << " ATT 2: \t     S S\t25";
        gotoligcol(51,5);
        std :: cout << " ATT 3: \t    S S S\t31";
        gotoligcol(55,20);
        Color(15,0);
        std :: cout << "4";

        /// CLOVIS ///

        for (i=45; i<75; i++)
        {
            Color(5,0);
            gotoligcol(40,i);
            std :: cout << trait8;
            gotoligcol(57,i);
            std :: cout << trait8;
        }

        for(i=46; i<74; i++)
        {

            gotoligcol(45,i);
            std :: cout << trait8;
        }

        for (i=41; i<57; i++)
        {
            Color(5,0);
            gotoligcol(i,44);
            std :: cout << trait2;
            gotoligcol(i,75);
            std :: cout << trait2;
        }
        gotoligcol(42,45);
        std :: cout << " CLOVIS  \t\t    29hp";
        gotoligcol(43,45);
        std :: cout << " (482-511)";
        gotoligcol(47,45);
        std :: cout << " ATT 1: \t      E \t0";
        gotoligcol(49,45);
        std :: cout << " ATT 2: \t     E E\t26";
        gotoligcol(51,45);
        std :: cout << " ATT 3: \t    E E E\t33";
        gotoligcol(55,60);
        Color(15,0);
        std :: cout << "5";

/// VERCINGETORIX ///

        for (i=85; i<115; i++)
        {
            Color(5,0);
            gotoligcol(40,i);
            std :: cout << trait8;
            gotoligcol(57,i);
            std :: cout << trait8;
        }

        for(i=86; i<114; i++)
        {

            gotoligcol(45,i);
            std :: cout << trait8;
        }

        for (i=41; i<57; i++)
        {
            Color(5,0);
            gotoligcol(i,84);
            std :: cout << trait2;
            gotoligcol(i,115);
            std :: cout << trait2;
        }
        gotoligcol(42,85);
        std :: cout << " VERCINGETORIX  \t    30hp";
        gotoligcol(43,85);
        std :: cout << " (-82-(-52))";
        gotoligcol(47,85);
        std :: cout << " ATT 1: \t      E \t0";
        gotoligcol(49,85);
        std :: cout << " ATT 2: \t     E E\t0";
        gotoligcol(51,85);
        std :: cout << " ATT 3: \t    E E E\t32";
        gotoligcol(55,100);
        Color(15,0);
        std :: cout << "6";

        /// BLANCHE DE CASTILLE ///

        for (i=125; i<155; i++)
        {
            Color(5,0);
            gotoligcol(40,i);
            std :: cout << trait8;
            gotoligcol(57,i);
            std :: cout << trait8;
        }

        for(i=126; i<154; i++)
        {

            gotoligcol(45,i);
            std :: cout << trait8;
        }

        for (i=41; i<57; i++)
        {
            Color(5,0);
            gotoligcol(i,124);
            std :: cout << trait2;
            gotoligcol(i,155);
            std :: cout << trait2;
        }
        gotoligcol(42,125);
        std :: cout << " BLANCHE DE CASTILLE    64hp";
        gotoligcol(43,125);
        std :: cout << " (1188-1252)";
        gotoligcol(47,125);
        std :: cout << " ATT 1: \t      J \t23";
        gotoligcol(49,125);
        std :: cout << " ATT 2: \t     J J\t26";
        gotoligcol(51,125);
        std :: cout << " ATT 3: \t    J J J\t35";
        gotoligcol(55,140);
        Color(15,0);
        std :: cout << "7";

        /// MARIE-ANTOINETTE ///

        for (i=5; i<35; i++)
        {
            Color(5,0);
            gotoligcol(65,i);
            std :: cout << trait8;
            gotoligcol(82,i);
            std :: cout << trait8;
        }

        for(i=6; i<34; i++)
        {

            gotoligcol(70,i);
            std :: cout << trait8;
        }

        for (i=66; i<82; i++)
        {
            Color(5,0);
            gotoligcol(i,4);
            std :: cout << trait2;
            gotoligcol(i,35);
            std :: cout << trait2;
        }
        gotoligcol(67,5);
        std :: cout << " MARIE-ANTOINETTE \t    38hp";
        gotoligcol(68,5);
        std :: cout << " (1755-1793)";
        gotoligcol(72,5);
        std :: cout << " ATT 1: \t      C \t0";
        gotoligcol(74,5);
        std :: cout << " ATT 2: \t     C C\t23";
        gotoligcol(76,5);
        std :: cout << " ATT 3: \t    C C C\t29";
        gotoligcol(80,20);
        Color(15,0);
        std :: cout << "8";

        /// FRANCOIS 1ER ///

        for (i=45; i<75; i++)
        {
            Color(5,0);
            gotoligcol(65,i);
            std :: cout << trait8;
            gotoligcol(82,i);
            std :: cout << trait8;
        }

        for(i=46; i<74; i++)
        {

            gotoligcol(70,i);
            std :: cout << trait8;
        }

        for (i=66; i<82; i++)
        {
            Color(5,0);
            gotoligcol(i,44);
            std :: cout << trait2;
            gotoligcol(i,75);
            std :: cout << trait2;
        }
        gotoligcol(67,45);
        std :: cout << " FRANCOIS 1ER  \t    53hp";
        gotoligcol(68,45);
        std :: cout << " (1494-1547)";
        gotoligcol(72,45);
        std :: cout << " ATT 1: \t      C \t24";
        gotoligcol(74,45);
        std :: cout << " ATT 2: \t     C C\t26";
        gotoligcol(76,45);
        std :: cout << " ATT 3: \t    C C C\t28";
        gotoligcol(80,60);
        Color(15,0);
        std :: cout << "9";

        Color(11,0);
        gotoligcol(86,1);
        std :: cout << "  Prix a l unite des cartes epiques: 80 ECUS..." << std :: endl << std :: endl << std :: endl;

        /// ------------------------------------------------------------------------CARTES RARES--------------------------------------------------------///

        Color(9,0);
        std :: cout << "-------------------------------------------------------------------------------------RARE-------------------------------------------------------------------------------------------------" << std :: endl << std :: endl;
        Color(11,0);
        std :: cout << "  RAPPEL sur les cartes ENERGIES et leurs symboles: EPEE -> E, SCEPTRE -> S, COURONNE -> C, MAIN DE LA JUSTICE -> J";

        /// LOUIS XVI ///

        for (i=5; i<35; i++)
        {
            Color(9,0);
            gotoligcol(93,i);
            std :: cout << trait8;
            gotoligcol(110,i);
            std :: cout << trait8;
        }

        for(i=6; i<34; i++)
        {

            gotoligcol(98,i);
            std :: cout << trait8;
        }

        for (i=94; i<110; i++)
        {
            Color(9,0);
            gotoligcol(i,4);
            std :: cout << trait2;
            gotoligcol(i,35);
            std :: cout << trait2;
        }
        gotoligcol(95,5);
        std :: cout << " LOUIS XVI \t    39hp";
        gotoligcol(96,5);
        std :: cout << " (1754-1793)";
        gotoligcol(100,5);
        std :: cout << " ATT 1: \t      C \t0";
        gotoligcol(102,5);
        std :: cout << " ATT 2: \t     C C\t20";
        gotoligcol(104,5);
        std :: cout << " ATT 3: \t    C C C\t25";
        gotoligcol(108,20);
        Color(15,0);
        std :: cout << "10";

        /// LOUIS XV ///

        for (i=45; i<75; i++)
        {
            Color(9,0);
            gotoligcol(93,i);
            std :: cout << trait8;
            gotoligcol(110,i);
            std :: cout << trait8;
        }

        for(i=46; i<74; i++)
        {

            gotoligcol(98,i);
            std :: cout << trait8;
        }

        for (i=94; i<110; i++)
        {
            Color(9,0);
            gotoligcol(i,44);
            std :: cout << trait2;
            gotoligcol(i,75);
            std :: cout << trait2;
        }
        gotoligcol(95,45);
        std :: cout << " LOUIS XV  \t    64hp";
        gotoligcol(96,45);
        std :: cout << " (1710-1774)";
        gotoligcol(100,45);
        std :: cout << " ATT 1: \t      C \t17";
        gotoligcol(102,45);
        std :: cout << " ATT 2: \t     C C\t20";
        gotoligcol(104,45);
        std :: cout << " ATT 3: \t    C C C\t23";
        gotoligcol(108,60);
        Color(15,0);
        std :: cout << "11";

/// SAINT LOUIS ///

        for (i=85; i<115; i++)
        {
            Color(9,0);
            gotoligcol(93,i);
            std :: cout << trait8;
            gotoligcol(110,i);
            std :: cout << trait8;
        }

        for(i=86; i<114; i++)
        {

            gotoligcol(98,i);
            std :: cout << trait8;
        }

        for (i=94; i<110; i++)
        {
            Color(9,0);
            gotoligcol(i,84);
            std :: cout << trait2;
            gotoligcol(i,115);
            std :: cout << trait2;
        }
        gotoligcol(95,85);
        std :: cout << " LOUIS IX, ST LOUIS     56hp";
        gotoligcol(96,85);
        std :: cout << " (1214-1270)";
        gotoligcol(100,85);
        std :: cout << " ATT 1: \t      J \t16";
        gotoligcol(102,85);
        std :: cout << " ATT 2: \t     J J\t23";
        gotoligcol(104,85);
        std :: cout << " ATT 3: \t    J J J\t25";
        gotoligcol(108,100);
        Color(15,0);
        std :: cout << "12";

        /// PHILIPPE LE BEL ///

        for (i=125; i<155; i++)
        {
            Color(9,0);
            gotoligcol(93,i);
            std :: cout << trait8;
            gotoligcol(110,i);
            std :: cout << trait8;
        }

        for(i=126; i<154; i++)
        {

            gotoligcol(98,i);
            std :: cout << trait8;
        }

        for (i=94; i<110; i++)
        {
            Color(9,0);
            gotoligcol(i,124);
            std :: cout << trait2;
            gotoligcol(i,155);
            std :: cout << trait2;
        }
        gotoligcol(95,125);
        std :: cout << " PHILIPPE IV LE BEL     46hp";
        gotoligcol(96,125);
        std :: cout << " (1268-1314)";
        gotoligcol(100,125);
        std :: cout << " ATT 1: \t      E \t18";
        gotoligcol(102,125);
        std :: cout << " ATT 2: \t     E E\t20";
        gotoligcol(104,125);
        std :: cout << " ATT 3: \t    E E E\t24";
        gotoligcol(108,140);
        Color(15,0);
        std :: cout << "13";





        /// HENRi IV ///




        for (i=5; i<35; i++)
        {
            Color(9,0);
            gotoligcol(118,i);
            std :: cout << trait8;
            gotoligcol(135,i);
            std :: cout << trait8;
        }

        for(i=6; i<34; i++)
        {

            gotoligcol(123,i);
            std :: cout << trait8;
        }

        for (i=119; i<135; i++)
        {
            Color(9,0);
            gotoligcol(i,4);
            std :: cout << trait2;
            gotoligcol(i,35);
            std :: cout << trait2;
        }
        gotoligcol(120,5);
        std :: cout << " HENRI IV \t\t     57hp";
        gotoligcol(121,5);
        std :: cout << " (1553-1610)";
        gotoligcol(125,5);
        std :: cout << " ATT 1: \t      S \t0";
        gotoligcol(127,5);
        std :: cout << " ATT 2: \t     S S\t20";
        gotoligcol(129,5);
        std :: cout << " ATT 3: \t    S S S\t25";
        gotoligcol(133,20);
        Color(15,0);
        std :: cout << "14";

        /// CHARLES VII ///

        for (i=45; i<75; i++)
        {
            Color(9,0);
            gotoligcol(118,i);
            std :: cout << trait8;
            gotoligcol(135,i);
            std :: cout << trait8;
        }

        for(i=46; i<74; i++)
        {

            gotoligcol(123,i);
            std :: cout << trait8;
        }

        for (i=119; i<135; i++)
        {
            Color(9,0);
            gotoligcol(i,44);
            std :: cout << trait2;
            gotoligcol(i,75);
            std :: cout << trait2;
        }
        gotoligcol(120,45);
        std :: cout << " CHARLES VII  \t    58hp";
        gotoligcol(121,45);
        std :: cout << " (1403-1461)";
        gotoligcol(125,45);
        std :: cout << " ATT 1: \t      E \t16";
        gotoligcol(127,45);
        std :: cout << " ATT 2: \t     E E\t20";
        gotoligcol(129,45);
        std :: cout << " ATT 3: \t    E E E\t26";
        gotoligcol(133,60);
        Color(15,0);
        std :: cout << "15";

/// PEPIN LE BREF ///

        for (i=85; i<115; i++)
        {
            Color(9,0);
            gotoligcol(118,i);
            std :: cout << trait8;
            gotoligcol(135,i);
            std :: cout << trait8;
        }

        for(i=86; i<114; i++)
        {

            gotoligcol(123,i);
            std :: cout << trait8;
        }

        for (i=119; i<135; i++)
        {
            Color(9,0);
            gotoligcol(i,84);
            std :: cout << trait2;
            gotoligcol(i,115);
            std :: cout << trait2;
        }
        gotoligcol(120,85);
        std :: cout << " PEPIN LE BREF \t    54hp";
        gotoligcol(121,85);
        std :: cout << " (714-768)";
        gotoligcol(125,85);
        std :: cout << " ATT 1: \t      E \t17";
        gotoligcol(127,85);
        std :: cout << " ATT 2: \t     E E\t19";
        gotoligcol(129,85);
        std :: cout << " ATT 3: \t    E E E\t26";
        gotoligcol(133,100);
        Color(15,0);
        std :: cout << "16";

        /// LOUIS XI ///

        for (i=125; i<155; i++)
        {
            Color(9,0);
            gotoligcol(118,i);
            std :: cout << trait8;
            gotoligcol(135,i);
            std :: cout << trait8;
        }

        for(i=126; i<154; i++)
        {

            gotoligcol(123,i);
            std :: cout << trait8;
        }

        for (i=119; i<135; i++)
        {
            Color(9,0);
            gotoligcol(i,124);
            std :: cout << trait2;
            gotoligcol(i,155);
            std :: cout << trait2;
        }
        gotoligcol(120,125);
        std :: cout << " LOUIS XI  \t     60hp";
        gotoligcol(121,125);
        std :: cout << " (1423-1483)";
        gotoligcol(125,125);
        std :: cout << " ATT 1: \t      S \t16";
        gotoligcol(127,125);
        std :: cout << " ATT 2: \t     S S\t18";
        gotoligcol(129,125);
        std :: cout << " ATT 3: \t    S S S\t24";
        gotoligcol(133,140);
        Color(15,0);
        std :: cout << "17";



/// PAUSE ///


        /// MARIE DE MEDICIS ///


        for (i=5; i<35; i++)
        {
            Color(9,0);
            gotoligcol(143,i);
            std :: cout << trait8;
            gotoligcol(160,i);
            std :: cout << trait8;
        }

        for(i=6; i<34; i++)
        {

            gotoligcol(148,i);
            std :: cout << trait8;
        }

        for (i=144; i<160; i++)
        {
            Color(9,0);
            gotoligcol(i,4);
            std :: cout << trait2;
            gotoligcol(i,35);
            std :: cout << trait2;
        }

        gotoligcol(145,5);
        std :: cout << " MARIE DE MEDICIS \t     67hp";
        gotoligcol(146,5);
        std :: cout << " (1575-1642)";
        gotoligcol(150,5);
        std :: cout << " ATT 1: \t      J \t18";
        gotoligcol(152,5);
        std :: cout << " ATT 2: \t     J J\t20";
        gotoligcol(154,5);
        std :: cout << " ATT 3: \t    J J J\t24";
        gotoligcol(158,20);
        Color(15,0);
        std :: cout << "18";

        /// ALIENOR D AQUITAINE ///

        for (i=45; i<75; i++)
        {
            Color(9,0);
            gotoligcol(143,i);
            std :: cout << trait8;
            gotoligcol(160,i);
            std :: cout << trait8;
        }

        for(i=46; i<74; i++)
        {

            gotoligcol(148,i);
            std :: cout << trait8;
        }

        for (i=144; i<160; i++)
        {
            Color(9,0);
            gotoligcol(i,44);
            std :: cout << trait2;
            gotoligcol(i,75);
            std :: cout << trait2;
        }
        gotoligcol(145,45);
        std :: cout << " ALIENOR D AQUITAINE    82hp";
        gotoligcol(146,45);
        std :: cout << " (1122-1204)";
        gotoligcol(150,45);
        std :: cout << " ATT 1: \t      S \t18";
        gotoligcol(152,45);
        std :: cout << " ATT 2: \t     S S\t20";
        gotoligcol(154,45);
        std :: cout << " ATT 3: \t    S S S\t22";
        gotoligcol(158,60);
        Color(15,0);
        std :: cout << "19";

/// MARIE CURIE ///

        for (i=85; i<115; i++)
        {
            Color(9,0);
            gotoligcol(143,i);
            std :: cout << trait8;
            gotoligcol(160,i);
            std :: cout << trait8;
        }

        for(i=86; i<114; i++)
        {

            gotoligcol(148,i);
            std :: cout << trait8;
        }

        for (i=144; i<160; i++)
        {
            Color(9,0);
            gotoligcol(i,84);
            std :: cout << trait2;
            gotoligcol(i,115);
            std :: cout << trait2;
        }
        gotoligcol(145,85);
        std :: cout << " MARIE CURIE    \t     67hp";
        gotoligcol(146,85);
        std :: cout << " (1867-1934)";
        gotoligcol(150,85);
        std :: cout << " ATT 1: \t      J \t19";
        gotoligcol(152,85);
        std :: cout << " ATT 2: \t     J J\t21";
        gotoligcol(154,85);
        std :: cout << " ATT 3: \t    J J J\t23";
        gotoligcol(158,100);
        Color(15,0);
        std :: cout << "20";

        /// OLYMPES DE GOUGES ///

        for (i=125; i<155; i++)
        {
            Color(9,0);
            gotoligcol(143,i);
            std :: cout << trait8;
            gotoligcol(160,i);
            std :: cout << trait8;
        }

        for(i=126; i<154; i++)
        {

            gotoligcol(148,i);
            std :: cout << trait8;
        }

        for (i=144; i<160; i++)
        {
            Color(9,0);
            gotoligcol(i,124);
            std :: cout << trait2;
            gotoligcol(i,155);
            std :: cout << trait2;
        }

        gotoligcol(145,125);
        std :: cout << " OLYMPES DE GOUGES      45hp";
        gotoligcol(146,125);
        std :: cout << " (1748-1793)";
        gotoligcol(150,125);
        std :: cout << " ATT 1: \t      J \t20";
        gotoligcol(152,125);
        std :: cout << " ATT 2: \t     J J\t21";
        gotoligcol(154,125);
        std :: cout << " ATT 3: \t    J J J\t22";
        gotoligcol(158,140);
        Color(15,0);
        std :: cout << "21";

        Color(11,0);
        gotoligcol(164,1);
        std :: cout << "  Prix a l unite des cartes rares: 35 ECUS..."  << std :: endl << std :: endl << std :: endl << std :: endl;


/// CARTES ENERGIES ///



        Color(12,0);
        std :: cout << "\t CARTES ENERGIES" << std :: endl << std :: endl;
        Color(11,0);
        std :: cout << "  RAPPEL sur les cartes ENERGIES et leurs symboles: EPEE -> E, SCEPTRE -> S, COURONNE -> C, MAIN DE LA JUSTICE -> J";


        /// EPEE ///

        for (i=5; i<35; i++)
        {
            Color(15,0);
            gotoligcol(174,i);
            std :: cout << trait8;
            gotoligcol(191,i);
            std :: cout << trait8;
        }

        for(i=6; i<34; i++)
        {

            gotoligcol(179,i);
            std :: cout << trait8;
        }

        for (i=175; i<191; i++)
        {
            Color(15,0);
            gotoligcol(i,4);
            std :: cout << trait2;
            gotoligcol(i,35);
            std :: cout << trait2;
        }
        gotoligcol(176,5);
        std :: cout << " \t\t   EPEE";
        gotoligcol(184,20);
        std :: cout << carreau;
        gotoligcol(189,20);
        Color(15,0);
        std :: cout << "22";

        /// COURONNE ///

        for (i=45; i<75; i++)
        {
            Color(15,0);
            gotoligcol(174,i);
            std :: cout << trait8;
            gotoligcol(191,i);
            std :: cout << trait8;
        }

        for(i=46; i<74; i++)
        {

            gotoligcol(179,i);
            std :: cout << trait8;
        }

        for (i=175; i<191; i++)
        {
            Color(15,0);
            gotoligcol(i,44);
            std :: cout << trait2;
            gotoligcol(i,75);
            std :: cout << trait2;
        }
        gotoligcol(176,45);
        std :: cout << " \t\t COURONNE";
        gotoligcol(184,60);
        std :: cout << trefle;
        gotoligcol(189,60);
        Color(15,0);
        std :: cout << "23";

/// SCEPTRE ///

        for (i=85; i<115; i++)
        {
            Color(15,0);
            gotoligcol(174,i);
            std :: cout << trait8;
            gotoligcol(191,i);
            std :: cout << trait8;
        }

        for(i=86; i<114; i++)
        {

            gotoligcol(179,i);
            std :: cout << trait8;
        }

        for (i=175; i<191; i++)
        {
            Color(15,0);
            gotoligcol(i,84);
            std :: cout << trait2;
            gotoligcol(i,115);
            std :: cout << trait2;
        }
        gotoligcol(176,85);
        std :: cout << " \t\t SCEPTRE ";
        gotoligcol(184,100);
        std :: cout << coeur;
        gotoligcol(189,100);
        Color(15,0);
        std :: cout << "24";

        /// MAIN DE LA JUSTICE ///

        for (i=125; i<155; i++)
        {
            Color(15,0);
            gotoligcol(174,i);
            std :: cout << trait8;
            gotoligcol(191,i);
            std :: cout << trait8;
        }

        for(i=126; i<154; i++)
        {

            gotoligcol(179,i);
            std :: cout << trait8;
        }

        for (i=175; i<191; i++)
        {
            Color(15,0);
            gotoligcol(i,124);
            std :: cout << trait2;
            gotoligcol(i,155);
            std :: cout << trait2;
        }
        gotoligcol(176,125);
        std :: cout << " \t   MAIN DE LA JUSTICE ";
        gotoligcol(184,140);
        std :: cout << pique;
        gotoligcol(189,140);
        Color(15,0);
        std :: cout << "25";


        Color(11,0);
        gotoligcol(193,1);
        std :: cout << "  Prix a l unite des cartes energies: 10 ECUS..." << std :: endl << std :: endl << std :: endl;


        /// ------------------------------------------------------------------------CARTES SPE--------------------------------------------------------///



        Color(12,0);
        std :: cout << "\t CARTES SPECIALES";


        /// LOUIS XVI ///

        for (i=5; i<35; i++)
        {
            Color(10,0);
            gotoligcol(200,i);
            std :: cout << trait8;
            gotoligcol(217,i);
            std :: cout << trait8;
        }

        for(i=6; i<34; i++)
        {

            gotoligcol(205,i);
            std :: cout << trait8;
        }

        for (i=201; i<217; i++)
        {
            Color(10,0);
            gotoligcol(i,4);
            std :: cout << trait2;
            gotoligcol(i,35);
            std :: cout << trait2;
        }


        gotoligcol(202,6);
        std :: cout << " \t       REVELATION";
        gotoligcol(207,5);
        std :: cout << "   REVELE VOTRE CARTE ENJEU ";
        gotoligcol(215,20);
        Color(15,0);
        std :: cout << "26";
        gotoligcol(215,6);
        Color(14,0);
        std :: cout << "Prix : 20";

        /// LOUIS XV ///

        for (i=45; i<75; i++)
        {
            Color(10,0);
            gotoligcol(200,i);
            std :: cout << trait8;
            gotoligcol(217,i);
            std :: cout << trait8;
        }

        for(i=46; i<74; i++)
        {

            gotoligcol(205,i);
            std :: cout << trait8;
        }

        for (i=201; i<217; i++)
        {
            Color(10,0);
            gotoligcol(i,44);
            std :: cout << trait2;
            gotoligcol(i,75);
            std :: cout << trait2;
        }

        gotoligcol(202,46);
        std :: cout << " \t\t MALICE";
        gotoligcol(207,45);
        std :: cout << "   PERMET DE DETRUIRE UNE";
        gotoligcol(209,45);
        std :: cout << "   CARTE ENERGIE DE VOTRE";
        gotoligcol(211,45);
        std :: cout << "         ADVERSAIRE";
        gotoligcol(215,60);
        Color(15,0);
        std :: cout << "27";
        gotoligcol(215,46);
        Color(14,0);
        std :: cout << "Prix : 20";

/// SAINT LOUIS ///

        for (i=85; i<115; i++)
        {
            Color(10,0);
            gotoligcol(200,i);
            std :: cout << trait8;
            gotoligcol(217,i);
            std :: cout << trait8;
        }

        for(i=86; i<114; i++)
        {

            gotoligcol(205,i);
            std :: cout << trait8;
        }

        for (i=201; i<217; i++)
        {
            Color(10,0);
            gotoligcol(i,84);
            std :: cout << trait2;
            gotoligcol(i,115);
            std :: cout << trait2;
        }

        gotoligcol(202,86);
        std :: cout << " \t      RESURRECTION";
        gotoligcol(207,85);
        std :: cout << "  PERMET DE RESSUSCITER UNE ";
        gotoligcol(209,85);
        std :: cout << "  CARTE MORTE DU CIMETIERE";
        gotoligcol(215,100);
        Color(15,0);
        std :: cout << "28";
        gotoligcol(215,86);
        Color(14,0);
        std :: cout << "Prix : 20";

        /// PHILIPPE LE BEL ///

        for (i=125; i<155; i++)
        {
            Color(10,0);
            gotoligcol(200,i);
            std :: cout << trait8;
            gotoligcol(217,i);
            std :: cout << trait8;
        }

        for(i=126; i<154; i++)
        {

            gotoligcol(205,i);
            std :: cout << trait8;
        }

        for (i=201; i<217; i++)
        {
            Color(10,0);
            gotoligcol(i,124);
            std :: cout << trait2;
            gotoligcol(i,155);
            std :: cout << trait2;
        }

        gotoligcol(202,126);
        std :: cout << " \t        ECHANGE";
        gotoligcol(207,125);
        std :: cout << " ECHANGE UNE CARTE DE VOTRE ";
        gotoligcol(209,125);
        std :: cout << " DECK AVEC VOTRE CARTE ENJEU  ";
        gotoligcol(215,140);
        Color(15,0);
        std :: cout << "29";
        gotoligcol(215,126);
        Color(14,0);
        std :: cout << "Prix : 40";





        /// HENRi IV ///




        for (i=5; i<35; i++)
        {
            Color(10,0);
            gotoligcol(225,i);
            std :: cout << trait8;
            gotoligcol(242,i);
            std :: cout << trait8;
        }

        for(i=6; i<34; i++)
        {

            gotoligcol(230,i);
            std :: cout << trait8;
        }

        for (i=226; i<242; i++)
        {
            Color(10,0);
            gotoligcol(i,4);
            std :: cout << trait2;
            gotoligcol(i,35);
            std :: cout << trait2;
        }

        gotoligcol(227,6);
        std :: cout << " \t       DESTRUCTION";
        gotoligcol(232,5);
        std :: cout << "  PERMET DE DETRUIRE TOUTES ";
        gotoligcol(234,5);
        std :: cout << "    LES CREATURES SUR LE";
        gotoligcol(236,5);
        std :: cout << "           TERRAIN";
        gotoligcol(240,20);
        Color(15,0);
        std :: cout << "30";
        gotoligcol(240,6);
        Color(14,0);
        std :: cout << "Prix : 30";

        /// CHARLES VII ///

        for (i=45; i<75; i++)
        {
            Color(10,0);
            gotoligcol(225,i);
            std :: cout << trait8;
            gotoligcol(242,i);
            std :: cout << trait8;
        }

        for(i=46; i<74; i++)
        {

            gotoligcol(230,i);
            std :: cout << trait8;
        }

        for (i=226; i<242; i++)
        {
            Color(10,0);
            gotoligcol(i,44);
            std :: cout << trait2;
            gotoligcol(i,75);
            std :: cout << trait2;
        }

        gotoligcol(227,46);
        std :: cout << " \t     NOUVEAU DEPART";
        gotoligcol(232,45);
        std :: cout << "   MET TOUTES LES ENERGIES ";
        gotoligcol(234,45);
        std :: cout << "             A 1";
        gotoligcol(240,60);
        Color(15,0);
        std :: cout << "31";
        gotoligcol(240,46);
        Color(14,0);
        std :: cout << "Prix : 35";

/// PEPIN LE BREF ///

        for (i=85; i<115; i++)
        {
            Color(10,0);
            gotoligcol(225,i);
            std :: cout << trait8;
            gotoligcol(242,i);
            std :: cout << trait8;
        }

        for(i=86; i<114; i++)
        {

            gotoligcol(230,i);
            std :: cout << trait8;
        }

        for (i=226; i<242; i++)
        {
            Color(10,0);
            gotoligcol(i,84);
            std :: cout << trait2;
            gotoligcol(i,115);
            std :: cout << trait2;
        }

        gotoligcol(227,86);
        std :: cout << " \t     SECONDE CHANCE";
        gotoligcol(232,85);
        std :: cout << "    RENVOI VOTRE CREATURE  ";
        gotoligcol(234,85);
        std :: cout << "  DANS VOTRE DECK AVEC TOUT";
        gotoligcol(236,85);
        std :: cout << "      SES POINTS DE VIE";
        gotoligcol(240,100);
        Color(15,0);
        std :: cout << "32";
        gotoligcol(240,86);
        Color(14,0);
        std :: cout << "Prix : 35";


        /// LOUIS XI ///

        for (i=125; i<155; i++)
        {
            Color(10,0);
            gotoligcol(225,i);
            std :: cout << trait8;
            gotoligcol(242,i);
            std :: cout << trait8;
        }

        for(i=126; i<154; i++)
        {

            gotoligcol(230,i);
            std :: cout << trait8;
        }

        for (i=226; i<242; i++)
        {
            Color(10,0);
            gotoligcol(i,124);
            std :: cout << trait2;
            gotoligcol(i,155);
            std :: cout << trait2;
        }

        gotoligcol(227,126);
        std :: cout << " \t    CHEVAL DE TROIE";
        gotoligcol(232,125);
        std :: cout << "  DETRUIT ALEATOIREMENT UNE ";
        gotoligcol(234,125);
        std :: cout << "   CARTE CONTENUE DANS LE ";
        gotoligcol(236,125);
        std :: cout << "  DECK DE VOTRE ADVERSAIRE ";
        gotoligcol(240,140);
        Color(15,0);
        std :: cout << "33";
        gotoligcol(240,126);
        Color(14,0);
        std :: cout << "Prix : 30";




/// PAUSE ///




        /// MARIE DE MEDICIS ///




        for (i=5; i<35; i++)
        {
            Color(10,0);
            gotoligcol(250,i);
            std :: cout << trait8;
            gotoligcol(267,i);
            std :: cout << trait8;
        }

        for(i=6; i<34; i++)
        {

            gotoligcol(255,i);
            std :: cout << trait8;
        }

        for (i=251; i<267; i++)
        {
            Color(10,0);
            gotoligcol(i,4);
            std :: cout << trait2;
            gotoligcol(i,35);
            std :: cout << trait2;
        }

        gotoligcol(252,6);
        std :: cout << " \t       INVOCATION";
        gotoligcol(257,5);
        std :: cout << "  INVOQUE UNE CARTE ENERGIE ";
        gotoligcol(259,5);
        std :: cout << "          ALEATOIRE";
        gotoligcol(265,20);
        Color(15,0);
        std :: cout << "34";
        gotoligcol(265,6);
        Color(14,0);
        std :: cout << "Prix : 20";

        /// CHARLES VII ///

        for (i=45; i<75; i++)
        {
            Color(10,0);
            gotoligcol(250,i);
            std :: cout << trait8;
            gotoligcol(267,i);
            std :: cout << trait8;
        }

        for(i=46; i<74; i++)
        {

            gotoligcol(255,i);
            std :: cout << trait8;
        }

        for (i=251; i<267; i++)
        {
            Color(10,0);
            gotoligcol(i,44);
            std :: cout << trait2;
            gotoligcol(i,75);
            std :: cout << trait2;
        }

        gotoligcol(252,46);
        std :: cout << " \t      ENTOURLOUPE";
        gotoligcol(257,45);
        std :: cout << "   VOTRE ADVERSAIRE DOIT  ";
        gotoligcol(259,45);
        std :: cout << " PASSER SON PROCHAIN TOUR";
        gotoligcol(265,60);
        Color(15,0);
        std :: cout << "35";
        gotoligcol(265,46);
        Color(14,0);
        std :: cout << "Prix : 20";

        Color(7,0);
        gotoligcol(274,0);
        std :: cout << "Voulez-vous acquerir une nouvelle carte : " << std :: endl;
        std :: cout << "0. NON\t 1. OUI\t:\t";
        Color(11,0);
        std :: cin >> retour;
        Color(15,0);
        int x;
        std::string mdp;
        if(retour==1)
        {
            std :: cout << std :: endl << "Veuillez entrer votre pseudo :   "<<std::endl;
            std :: cout << "Veuillez entrer votre mot de passe :  "<<std::endl;
            Color(14,0);
            gotoligcol(277,32);
            std :: cin >> pseudo;
            gotoligcol(278,38);
            std :: cin >> mdp;
            Color(15,0);
            x=chercheHero(hero,pseudo,mdp);
            if(x==300)
            {
                Color(15,4);
                gotoligcol(280,1);
                std :: cout << std :: endl<< "Derniere chance !";
                Color(15,0);
                std :: cout << std :: endl << std :: endl << "Voulez-vous acquerir une nouvelle carte : " << std :: endl;
                std :: cout << "0. NON\t 1. OUI\t:\t";
                Color(11,0);
                std :: cin >> retour;
                if (retour==1)
                {
                    Color(15,0);
                    std :: cout << std :: endl << "Veuillez entrer votre pseudo :   "<<std::endl;
                    std :: cout << "Veuillez entrer votre mot de passe :  "<<std::endl;
                    Color(14,0);
                    gotoligcol(286,32);
                    std :: cin >> pseudo;
                    gotoligcol(287,38);
                    std :: cin >> mdp;
                    Color(15,0);
                    x=chercheHero(hero,pseudo,mdp);
                }
            }
            if(x==300)
            {
                return hero;
            }
            hero[x].acheterCarte(Bibliotheque);
        }
        std :: cout << std :: endl;
        system("cls");
    }
    while (retour!=0);
    return hero;

}

std::vector <Hero> Jouer(std::vector<Hero> joueurs)
{

    int joueur[2];
    int tour=0;
    int sortie=0;
    int choix=0;
    int choix2=0;
    int choix3=0;
    char traitfin;
    char traitfin2;
    char traitfin3;
    char trait;
    char trait1;
    char trait2;
    char trait3;
    char trait4;
    char trait5;
    int x=0;
    int y=0;
    int o=0;

    traitfin=0xC4;
    traitfin2=0xC5;
    traitfin3=0xB3;
    trait=0xCD;
    trait1=0xC8;
    trait2=0xBA;
    trait3=0xC9;
    trait4=0xBB;
    trait5=0xBC;

    do
    {
        system("cls");
        std::cout << "Quels joueurs vont jouer la partie ? "<< "\n" << std::endl;
        for (unsigned i=0; i<joueurs.size() ; i++)
        {
            Color(14,0);
            std::cout << i+1<< " - " << joueurs[i].getPseudo()<<std::endl;
        }
        Color(15,0);
        gotoligcol(6,73);
        std::cout << "Entrer le numero du joueur 1 : ";
        gotoligcol(7,73);
        std::cout << "Entrer le numero du joueur 2 : ";

        gotoligcol(6,104);
        Color(11,0);
        std::cin>> x;
        while((x<=0)||(x>=(int)joueurs.size()+1))
        {
            gotoligcol(6,73);
            Color(15,0);
            std::cout << "Entrer le numero du joueur 1 :             ";
            Color(11,0);
            gotoligcol(6,104);
            std::cin>> x;
            Color(15,0);
        }
        joueur[0]=x-1;

        gotoligcol(7,104);
        std::cin>> y;
        while((y<=0)||(y>=(int)joueurs.size()+1)||(y==x))
        {
            gotoligcol(7,73);
            Color(15,0);
            std::cout << "Entrer le numero du joueur 2 :             ";
            Color(11,0);
            gotoligcol(7,104);
            std::cin>> y;
            Color(15,0);
        }
        joueur[1]=y-1;


        gotoligcol(6,73);
        Color(15,0);
        std::cout << "Entrer le numero du joueur 1 : ";
        Color(14,0);
        std::cout << joueurs[joueur[0]].getPseudo();

        gotoligcol(7,73);
        Color(15,0);
        std::cout << "Entrer le numero du joueur 2 : ";
        Color(14,0);
        std::cout << joueurs[joueur[1]].getPseudo();
    }
    while((joueurs[joueur[0]].getDeck().size()==0)||(joueurs[joueur[1]].getDeck().size()!=21));


    gotoligcol(13,0);
    Color(15,0);
    std :: cout << "Les joueurs qui vont s affronter sont : ";
    Color(14,0);
    std :: cout << joueurs[joueur[0]].getPseudo();
    Color(15,0);
    std :: cout << " contre ";
    Color(14,0);
    std :: cout << joueurs[joueur[1]].getPseudo() << std :: endl << std :: endl;
    Color(15,0);
    system("Pause");
    system("cls");


    joueurs[joueur[0]].init();
    joueurs[joueur[1]].init();

    joueurs[joueur[0]].melangedeck();
    joueurs[joueur[1]].melangedeck();

    joueurs[joueur[0]].carte_enjeu();
    joueurs[joueur[1]].carte_enjeu();


    while (sortie!=1)
    {
        for (int i=0; i<2 ; i++)
        {
            o=0;
            int p=1;
            if(i==1)
            {
                p=0;
            }

            if(joueurs[joueur[p]].getActive()!=NULL)
            {
                Color(15,0);
                gotoligcol(18,75);
                std :: cout << "Carte active de ";
                gotoligcol(18,91);
                std :: cout << joueurs[joueur[p]].getPseudo();
                std :: cout << " : ";
                Color(12,0);
                joueurs[joueur[p]].affichActive();
                std::cout << "  "<< joueurs[joueur[p]].getActive()->getPv()<< " PV";
            }

            if(joueurs[joueur[i]].getActive()!=NULL)
            {
                Color(15,0);
                gotoligcol(22,75);
                std :: cout << "Carte active de ";
                std :: cout << joueurs[joueur[i]].getPseudo();
                std :: cout << " : ";
                Color(12,0);
                joueurs[joueur[i]].affichActive();
                std::cout << "  "<< joueurs[joueur[i]].getActive()->getPv()<< " PV";
                gotoligcol(24,96);
                std::cout << "  "<< "Attaque 1 : " << joueurs[joueur[i]].getActive()->getAttaque1()<< " degats et coute 1 ";
                gotoligcol(25,96);
                std::cout << "  "<< "Attaque 2 : " << joueurs[joueur[i]].getActive()->getAttaque2()<< " degats et coute 2";
                gotoligcol(26,96);
                std::cout << "  "<< "Attaque 3 : " << joueurs[joueur[i]].getActive()->getAttaque3()<< " degats et coute 3";
                gotoligcol(28,96);
                Color(14,0);
                std::cout << "  "<< "Type : " << joueurs[joueur[i]].getActive()->getType();
                Color(15,0);
            }



            if(joueurs[joueur[p]].getActive()==NULL)
            {
                Color(15,0);
                gotoligcol(18,75);
                std::cout << joueurs[joueur[p]].getPseudo();
                std::cout << " n a pas de carte active ";
            }

            if(joueurs[joueur[i]].getActive()==NULL)
            {
                Color(15,0);
                gotoligcol(22,75);
                std::cout << joueurs[joueur[i]].getPseudo();
                std::cout << " n a pas de carte active ";
            }


            Color(15,0);
            joueurs[joueur[i]].retirer_carte();
            tour ++;

            /// TRAIT DE TERRAIN ///

            for (int i=70; i<121; i++)
            {
                gotoligcol(20,i);
                std :: cout << traitfin;
            }




            /// CUBE INFO JOUEUR ///

            for (int i=145; i<183; i++)
            {
                gotoligcol(8,i);
                std :: cout << trait;
                gotoligcol(2,i);
                std :: cout << trait;
            }

            gotoligcol(8,145);
            std :: cout << trait1;
            gotoligcol(8,183);
            std :: cout << trait5;
            gotoligcol(2,145);
            std :: cout << trait3;
            gotoligcol(2,183);
            std :: cout << trait4;

            for (int i=3; i<8; i++)
            {
                gotoligcol(i,145);
                std :: cout << trait2;
                gotoligcol(i,183);
                std :: cout << trait2;
            }

            /// CUBE MAIN JOUEUR ///

            for (int i=67; i<123; i++)
            {
                gotoligcol(35,i);
                std :: cout << trait;
                gotoligcol(45,i);
                std :: cout << trait;
            }

            gotoligcol(35,66);
            std :: cout << trait3;
            gotoligcol(35,123);
            std :: cout << trait4;
            gotoligcol(45,66);
            std :: cout << trait1;
            gotoligcol(45,123);
            std :: cout << trait5;

            for (int i=36; i<45; i++)
            {
                gotoligcol(i,66);
                std :: cout << trait2;
                gotoligcol(i,123);
                std :: cout << trait2;
            }

            /// CUBE CIMETIERE ///

            for (int i=2; i<15; i++)
            {
                gotoligcol(13,i);
                std :: cout << trait;
                gotoligcol(28,i);
                std :: cout << trait;
            }

            gotoligcol(13,1);
            std :: cout << trait3;
            gotoligcol(13,15);
            std :: cout << trait4;
            gotoligcol(28,1);
            std :: cout << trait1;
            gotoligcol(28,15);
            std :: cout << trait5;

            for (int i=14; i<28; i++)
            {
                gotoligcol(i,1);
                std :: cout << trait2;
                gotoligcol(i,15);
                std :: cout << trait2;
            }

            gotoligcol(15,4);
            Color(13,0);
            std :: cout << "CIMETIERE";
            gotoligcol(16,3);
            std :: cout << "   " << joueurs[joueur[i]].getPseudo();
            Color(15,0);
            gotoligcol(18,7);
            std :: cout << traitfin;
            gotoligcol(18,8);
            std :: cout << traitfin2;
            gotoligcol(18,9);
            std :: cout << traitfin;
            gotoligcol(19,8);
            std :: cout << traitfin3;

            gotoligcol(23,8);
            std::cout<< joueurs[joueur[i]].getCimetiere().size();
            gotoligcol(25,5);
            std :: cout << "CARTE(S)";

            Color(15,0);

            /// FLECHE TABLE DES ACTIONS ///
            Color(11,0);
            for (int i=129; i<139; i++)
            {
                gotoligcol(40,i);
                std :: cout << trait;
            }

            gotoligcol(40,139);
            std :: cout << ">";

            Color(15,0);

            /// CUBE CARTE ENERGIE ///

            for (int i=146; i<183; i++)
            {
                gotoligcol(13,i);
                std :: cout << trait;
                gotoligcol(28,i);
                std :: cout << trait;
            }

            gotoligcol(13,145);
            std :: cout << trait3;
            gotoligcol(13,183);
            std :: cout << trait4;
            gotoligcol(28,145);
            std :: cout << trait1;
            gotoligcol(28,183);
            std :: cout << trait5;

            for (int i=14; i<28; i++)
            {
                gotoligcol(i,145);
                std :: cout << trait2;
                gotoligcol(i,183);
                std :: cout << trait2;
            }

            /// TABLE DES ACTIONS ///

            for (int i=146; i<183; i++)
            {
                gotoligcol(33,i);
                std :: cout << trait;
                gotoligcol(45,i);
                std :: cout << trait;
            }

            gotoligcol(33,145);
            std :: cout << trait3;
            gotoligcol(33,183);
            std :: cout << trait4;
            gotoligcol(45,145);
            std :: cout << trait1;
            gotoligcol(45,183);
            std :: cout << trait5;

            for (int i=34; i<45; i++)
            {
                gotoligcol(i,145);
                std :: cout << trait2;
                gotoligcol(i,183);
                std :: cout << trait2;
            }


///-----------INFO JOUEUR-----------------///

            gotoligcol(4,147);
            std::cout << "Joueur : ";
            gotoligcol(4,156);
            Color(14,0);
            std::cout << joueurs[joueur[i]].getPseudo();
            Color(15,0);
            gotoligcol(5,147);
            std::cout << "PV : ";
            gotoligcol(5,152);
            Color(14,0);
            std::cout << joueurs[joueur[i]].getPv();
            Color(15,0);
            gotoligcol(6,147);
            std::cout << "Cartes restantes dans le deck : ";
            gotoligcol(6,179);
            Color(14,0);
            std::cout << joueurs[joueur[i]].Pioche();
            Color(15,0);

            gotoligcol(2,87);
            std :: cout << "A votre tour";
            gotoligcol(2,100);
            Color(14,0);
            std :: cout << joueurs[joueur[i]].getPseudo();

            for (int i=82; i<110; i++)
            {
                gotoligcol(3,i);
                std :: cout << traitfin;
            }
            Color(15,0);


            Color(15,0);
            gotoligcol(14,150);
            std :: cout << "Vos cartes enregies actvives";
            gotoligcol(15,160);
            joueurs[joueur[i]].affichEnergie();

            gotoligcol(35,156);
            Color(9,0);
            std :: cout << "TABLE DES ACTIONS";
            Color(15,0);


///-----------MAIN CARTES CREATURES-------------///


            if( joueurs[joueur[i]].getMain()->getId() >0 && joueurs[joueur[i]].getMain()->getId() <22)
            {
                std::cout << "\n\n"<<std::endl;

                gotoligcol(37,68);
                std :: cout << "Vous avez actuellement la carte ";
                Color(12,0);
                std :: cout << joueurs[joueur[i]].getMain()->getNom();
                gotoligcol(38,68);
                Color(15,0);
                std :: cout << "dans votre main.";
                gotoligcol(41,68);
                Color(14,0);
                std :: cout << "Veuillez vous referer a la TABLE DES ACTIONS pour";
                gotoligcol(42,68);
                std :: cout << "savoir ce que vous pouvez faire";

                if(joueurs[joueur[i]].getActive()==NULL)
                {
                    Color(15,0);
                    gotoligcol(37,147);
                    std :: cout << "Vous pouvez effectuer ces 2 actions";
                    gotoligcol(40,147);
                    std::cout << "1. Jouer la creature";
                    gotoligcol(42,147);
                    std::cout << "2. Remettre dans le deck";
                    gotoligcol(44,147);
                    Color(9,0);
                    std :: cout << "Saisir : ";
                    Color(15,0);
                    std::cin>>choix;

                    while((choix<1) || (choix>2))
                    {
                        gotoligcol(44,147);
                        Color(9,0);
                        std :: cout << "Saisir :       ";
                        gotoligcol(44,147);
                        Color(9,0);
                        std :: cout << "Saisir : ";
                        Color(15,0);
                        std::cin>>choix;
                    }


                    if(choix==1)
                    {
                        joueurs[joueur[i]].poserActive();
                        Color(15,0);
                    }
                    else if(choix==2)
                    {
                        joueurs[joueur[i]].remettre_carte(joueurs[joueur[i]].getMain());
                    }

                }

                else if(joueurs[joueur[i]].getActive()!=NULL)
                {

                    Color(15,0);
                    gotoligcol(37,147);
                    std :: cout << "Vous pouvez effectuer ces 2 actions";
                    gotoligcol(40,147);
                    std::cout << "1. Jouer la creature";
                    gotoligcol(42,147);
                    std::cout << "2. Remettre dans le deck";
                    gotoligcol(44,147);
                    Color(9,0);
                    std :: cout << "Saisir : ";
                    Color(15,0);
                    std::cin>>choix;

                    while((choix<1) || (choix>2))
                    {
                        gotoligcol(44,147);
                        Color(9,0);
                        std :: cout << "Saisir :       ";
                        gotoligcol(44,147);
                        Color(9,0);
                        std :: cout << "Saisir : ";
                        Color(15,0);
                        std::cin>>choix;
                    }


                    if(choix==1)
                    {
                        joueurs[joueur[i]].cimetiere();
                        joueurs[joueur[i]].poserActive();
                        joueurs[joueur[i]].affichActive();
                        Color(15,0);
                    }
                    else if(choix==2)
                    {
                        joueurs[joueur[i]].remettre_carte(joueurs[joueur[i]].getMain());
                        if (joueurs[joueur[i]].getActive()!=NULL)
                        {
                            gotoligcol(40,147);
                            std::cout<<"                                ";
                            gotoligcol(42,147);
                            std::cout<<"                                ";
                            gotoligcol(44,147);
                            std::cout<<"                                ";
                            gotoligcol(40,147);
                            std::cout<<"1. Attaquer avec la carte active";
                            gotoligcol(42,147);
                            std::cout<<"2. Passer le tour";
                            gotoligcol(44,147);
                            int choi;
                            Color(9,0);
                            std :: cout << "Saisir : ";
                            Color(15,0);
                            std::cin>>choi;

                            while((choi<1) || (choi>2))
                            {
                                gotoligcol(44,147);
                                Color(9,0);
                                std :: cout << "Saisir :       ";
                                gotoligcol(44,147);
                                Color(9,0);
                                std :: cout << "Saisir : ";
                                Color(15,0);
                                std::cin>>choi;
                            }

                            if(choi==1)
                            {
                                gotoligcol(40,147);
                                std::cout<<"                                ";
                                gotoligcol(42,147);
                                std::cout<<"                                ";
                                gotoligcol(44,147);
                                std::cout<<"                                ";
                                gotoligcol(39,147);
                                std::cout<<"1. Attaque 1"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque1() <<std::endl;
                                gotoligcol(40,147);
                                std::cout<<"2. Attaque 2"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque2() <<std::endl;
                                gotoligcol(41,147);
                                std::cout<<"3. Attaque 3"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque3() <<std::endl;
                                gotoligcol(42,147);
                                std::cout<<"4. Passer le tour";
                                gotoligcol(44,147);
                                int choixx;
                                Color(9,0);
                                std :: cout << "Saisir : ";
                                Color(15,0);
                                std::cin>>choixx;


                                while((choixx<1) || (choixx>4))
                                {
                                    gotoligcol(44,147);
                                    Color(9,0);
                                    std :: cout << "Saisir :       ";
                                    gotoligcol(44,147);
                                    Color(9,0);
                                    std :: cout << "Saisir : ";
                                    Color(15,0);
                                    std::cin>>choixx;
                                }



                                if ((choixx==1)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=1))
                                {
                                    if(joueurs[joueur[p]].getActive()==NULL)
                                    {
                                        joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque1());
                                    }

                                    else if(joueurs[joueur[p]].getActive()!=NULL)
                                    {
                                        joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque1());
                                        if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                        {
                                            int degatHero=0;
                                            joueurs[joueur[p]].cimetiere();
                                            degatHero=-joueurs[joueur[p]].getActive()->getPv();
                                            joueurs[joueur[p]].perdreVie4(degatHero);
                                            joueurs[joueur[p]].detruire();
                                        }
                                    }

                                }

                                else if ((choixx==1)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<1))
                                {
                                    gotoligcol(37,147);
                                    std::cout<<"                                   ";
                                    gotoligcol(38,147);
                                    std::cout<<"                                   ";
                                    gotoligcol(40,147);
                                    std::cout<<"                                ";
                                    gotoligcol(42,147);
                                    std::cout<<"                                ";
                                    gotoligcol(44,147);
                                    std::cout<<"                                ";
                                    gotoligcol(39,147);
                                    std::cout<<"  Vous n'avez pas assez d'energie";
                                    gotoligcol(41,147);
                                    std::cout<<"       vous passez votre tour";
                                    gotoligcol(45,2);
                                    system("Pause");
                                }

                                if ((choixx==2)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=2))
                                {
                                    if(joueurs[joueur[p]].getActive()==NULL)
                                    {
                                        joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque2());
                                    }

                                    else if(joueurs[joueur[p]].getActive()!=NULL)
                                    {
                                        joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque2());
                                        if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                        {
                                            int degatHero=0;
                                            joueurs[joueur[p]].cimetiere();
                                            degatHero=-joueurs[joueur[p]].getActive()->getPv();
                                            joueurs[joueur[p]].perdreVie4(degatHero);
                                            joueurs[joueur[p]].detruire();
                                        }
                                    }

                                }
                                else if ((choixx==2)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<2))
                                {
                                    gotoligcol(37,147);
                                    std::cout<<"                                   ";
                                    gotoligcol(38,147);
                                    std::cout<<"                                   ";
                                    gotoligcol(40,147);
                                    std::cout<<"                                ";
                                    gotoligcol(42,147);
                                    std::cout<<"                                ";
                                    gotoligcol(44,147);
                                    std::cout<<"                                ";
                                    gotoligcol(39,147);
                                    std::cout<<"  Vous n'avez pas assez d'energie";
                                    gotoligcol(41,147);
                                    std::cout<<"       vous passez votre tour";
                                    gotoligcol(45,2);
                                    system("Pause");

                                }
                                if ((choixx==3)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=3))
                                {
                                    if(joueurs[joueur[p]].getActive()==NULL)
                                    {
                                        joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque3());
                                    }

                                    else if(joueurs[joueur[p]].getActive()!=NULL)
                                    {
                                        joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque3());
                                        if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                        {
                                            joueurs[joueur[p]].cimetiere();
                                            joueurs[joueur[p]].detruire();
                                        }
                                    }

                                }
                                else if ((choixx==3)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<3))
                                {
                                    gotoligcol(37,147);
                                    std::cout<<"                                   ";
                                    gotoligcol(38,147);
                                    std::cout<<"                                   ";
                                    gotoligcol(40,147);
                                    std::cout<<"                                ";
                                    gotoligcol(42,147);
                                    std::cout<<"                                ";
                                    gotoligcol(44,147);
                                    std::cout<<"                                ";
                                    gotoligcol(39,147);
                                    std::cout<<"  Vous n'avez pas assez d'energie";
                                    gotoligcol(41,147);
                                    std::cout<<"       vous passez votre tour";
                                    gotoligcol(45,2);
                                    system("Pause");

                                }
                                if(choixx==4)
                                {

                                }
                            }
                        }
                    }
                }

            }

            /// ENERGIES ///

            else if( joueurs[joueur[i]].getMain()->getId() >21 && joueurs[joueur[i]].getMain()->getId() <26)
            {
                gotoligcol(37,68);
                std :: cout << "Vous avez actuellement la carte ";
                Color(12,0);
                std :: cout << joueurs[joueur[i]].getMain()->getNom();
                gotoligcol(38,68);
                Color(15,0);
                std :: cout << "dans votre main.";
                gotoligcol(41,68);
                Color(14,0);
                std :: cout << "Veuillez vous referer a la TABLE DES ACTIONS pour";
                gotoligcol(42,68);
                std :: cout << "savoir ce que vous pouvez faire";
                Color(15,0);

                gotoligcol(37,147);
                std :: cout << "Vous pouvez effectuer ces 2 actions";
                gotoligcol(40,147);
                std::cout << "1. Poser l energie";
                gotoligcol(42,147);
                std::cout << "2. Remettre dans le deck";
                gotoligcol(44,147);
                Color(9,0);
                std :: cout << "Saisir : ";
                Color(15,0);
                std::cin>>choix2;

                while((choix2<1) || (choix2>2))
                {
                    gotoligcol(44,147);
                    Color(9,0);
                    std :: cout << "Saisir :       ";
                    gotoligcol(44,147);
                    Color(9,0);
                    std :: cout << "Saisir : ";
                    Color(15,0);
                    std::cin>>choix2;
                }


                if(choix2==1)
                {
                    Color(15,0);
                    gotoligcol(14,150);
                    std :: cout << "Vos cartes enregies actvives";
                    gotoligcol(15,160);
                    joueurs[joueur[i]].setEnergie(joueurs[joueur[i]].getMain()->getType()-1);
                    joueurs[joueur[i]].affichEnergie();

                    if (joueurs[joueur[i]].getActive()!=NULL)
                    {
                        gotoligcol(40,147);
                        std::cout<<"                                ";
                        gotoligcol(42,147);
                        std::cout<<"                                ";
                        gotoligcol(44,147);
                        std::cout<<"                                ";
                        gotoligcol(40,147);
                        std::cout<<"1. Attaquer avec la carte active";
                        gotoligcol(42,147);
                        std::cout<<"2. Passer le tour";
                        gotoligcol(44,147);
                        int choi;
                        Color(9,0);
                        std :: cout << "Saisir : ";
                        Color(15,0);
                        std::cin>>choi;

                        while((choi<1) || (choi>2))
                        {
                            gotoligcol(44,147);
                            Color(9,0);
                            std :: cout << "Saisir :       ";
                            gotoligcol(44,147);
                            Color(9,0);
                            std :: cout << "Saisir : ";
                            Color(15,0);
                            std::cin>>choi;
                        }
                        if(choi==1)
                        {
                            gotoligcol(40,147);
                            std::cout<<"                                ";
                            gotoligcol(42,147);
                            std::cout<<"                                ";
                            gotoligcol(44,147);
                            std::cout<<"                                ";
                            gotoligcol(39,147);
                            std::cout<<"1. Attaque 1"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque1() <<std::endl;
                            gotoligcol(40,147);
                            std::cout<<"2. Attaque 2"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque2() <<std::endl;
                            gotoligcol(41,147);
                            std::cout<<"3. Attaque 3"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque3() <<std::endl;
                            gotoligcol(42,147);
                            std::cout<<"4. Passer le tour";
                            gotoligcol(44,147);
                            int choixx;
                            Color(9,0);
                            std :: cout << "Saisir : ";
                            Color(15,0);
                            std::cin>>choixx;

                            while((choixx<1) || (choixx>4))
                            {
                                gotoligcol(44,147);
                                Color(9,0);
                                std :: cout << "Saisir :       ";
                                gotoligcol(44,147);
                                Color(9,0);
                                std :: cout << "Saisir : ";
                                Color(15,0);
                                std::cin>>choixx;
                            }

                            if ((choixx==1)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=1))
                            {
                                if(joueurs[joueur[p]].getActive()==NULL)
                                {
                                    joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque1());
                                }

                                else if(joueurs[joueur[p]].getActive()!=NULL)
                                {
                                    joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque1());
                                    if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                    {
                                        int degatHero=0;
                                        joueurs[joueur[p]].cimetiere();
                                        degatHero=-joueurs[joueur[p]].getActive()->getPv();
                                        joueurs[joueur[p]].perdreVie4(degatHero);
                                        joueurs[joueur[p]].detruire();
                                    }
                                }


                            }
                            else if ((choixx==1)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<1))
                            {
                                gotoligcol(37,147);
                                std::cout<<"                                   ";
                                gotoligcol(38,147);
                                std::cout<<"                                   ";
                                gotoligcol(40,147);
                                std::cout<<"                                ";
                                gotoligcol(42,147);
                                std::cout<<"                                ";
                                gotoligcol(44,147);
                                std::cout<<"                                ";
                                gotoligcol(39,147);
                                std::cout<<"  Vous n'avez pas assez d'energie";
                                gotoligcol(41,147);
                                std::cout<<"       vous passez votre tour";
                                gotoligcol(45,2);
                                system("Pause");
                            }
                            if ((choixx==2)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=2))
                            {
                                if(joueurs[joueur[p]].getActive()==NULL)
                                {
                                    joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque2());
                                }

                                else if(joueurs[joueur[p]].getActive()!=NULL)
                                {
                                    joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque2());
                                    if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                    {
                                        int degatHero=0;
                                        joueurs[joueur[p]].cimetiere();
                                        degatHero=-joueurs[joueur[p]].getActive()->getPv();
                                        joueurs[joueur[p]].perdreVie4(degatHero);
                                        joueurs[joueur[p]].detruire();
                                    }
                                }

                            }
                            else if ((choixx==2)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<2))
                            {
                                gotoligcol(37,147);
                                std::cout<<"                                   ";
                                gotoligcol(38,147);
                                std::cout<<"                                   ";
                                gotoligcol(40,147);
                                std::cout<<"                                ";
                                gotoligcol(42,147);
                                std::cout<<"                                ";
                                gotoligcol(44,147);
                                std::cout<<"                                ";
                                gotoligcol(39,147);
                                std::cout<<"  Vous n'avez pas assez d'energie";
                                gotoligcol(41,147);
                                std::cout<<"       vous passez votre tour";
                                gotoligcol(45,2);
                                system("Pause");
                            }
                            if ((choixx==3)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=3))
                            {
                                if(joueurs[joueur[p]].getActive()==NULL)
                                {
                                    joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque3());
                                }

                                else if(joueurs[joueur[p]].getActive()!=NULL)
                                {
                                    joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque3());
                                    if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                    {
                                        int degatHero=0;
                                        joueurs[joueur[p]].cimetiere();
                                        degatHero=-joueurs[joueur[p]].getActive()->getPv();
                                        joueurs[joueur[p]].perdreVie4(degatHero);
                                        joueurs[joueur[p]].detruire();
                                    }
                                }


                            }
                            else if ((choixx==3)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<3))
                            {
                                gotoligcol(37,147);
                                std::cout<<"                                   ";
                                gotoligcol(38,147);
                                std::cout<<"                                   ";
                                gotoligcol(40,147);
                                std::cout<<"                                ";
                                gotoligcol(42,147);
                                std::cout<<"                                ";
                                gotoligcol(44,147);
                                std::cout<<"                                ";
                                gotoligcol(39,147);
                                std::cout<<"  Vous n'avez pas assez d'energie";
                                gotoligcol(41,147);
                                std::cout<<"       vous passez votre tour";
                                gotoligcol(45,2);
                                system("Pause");
                            }
                        }

                        else if (choi==2)
                        {

                        }
                    }
                }

                else if(choix2==2)
                {
                    joueurs[joueur[i]].remettre_carte(joueurs[joueur[i]].getMain());
                    if (joueurs[joueur[i]].getActive()!=NULL)
                    {
                        gotoligcol(40,147);
                        std::cout<<"                                ";
                        gotoligcol(42,147);
                        std::cout<<"                                ";
                        gotoligcol(44,147);
                        std::cout<<"                                ";
                        gotoligcol(40,147);
                        std::cout<<"1. Attaquer avec la carte active";
                        gotoligcol(42,147);
                        std::cout<<"2. Passer le tour";
                        gotoligcol(44,147);
                        int choi;
                        Color(9,0);
                        std :: cout << "Saisir : ";
                        Color(15,0);
                        std::cin>>choi;

                        while((choi<1) || (choi>2))
                        {
                            gotoligcol(44,147);
                            Color(9,0);
                            std :: cout << "Saisir :       ";
                            gotoligcol(44,147);
                            Color(9,0);
                            std :: cout << "Saisir : ";
                            Color(15,0);
                            std::cin>>choi;
                        }

                        if(choi==1)
                        {
                            gotoligcol(40,147);
                            std::cout<<"                                ";
                            gotoligcol(42,147);
                            std::cout<<"                                ";
                            gotoligcol(44,147);
                            std::cout<<"                                ";
                            gotoligcol(39,147);
                            std::cout<<"1. Attaque 1"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque1() <<std::endl;
                            gotoligcol(40,147);
                            std::cout<<"2. Attaque 2"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque2() <<std::endl;
                            gotoligcol(41,147);
                            std::cout<<"3. Attaque 3"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque3() <<std::endl;
                            gotoligcol(42,147);
                            std::cout<<"4. Passer le tour";
                            gotoligcol(44,147);
                            int choixx;
                            Color(9,0);
                            std :: cout << "Saisir : ";
                            Color(15,0);
                            std::cin>>choixx;

                            while((choixx<1) || (choixx>4))
                            {
                                gotoligcol(44,147);
                                Color(9,0);
                                std :: cout << "Saisir :       ";
                                gotoligcol(44,147);
                                Color(9,0);
                                std :: cout << "Saisir : ";
                                Color(15,0);
                                std::cin>>choixx;
                            }

                            if ((choixx==1)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=1))
                            {
                                if(joueurs[joueur[p]].getActive()==NULL)
                                {
                                    joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque1());
                                }

                                else if(joueurs[joueur[p]].getActive()!=NULL)
                                {
                                    joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque1());
                                    if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                    {
                                        int degatHero=0;
                                        joueurs[joueur[p]].cimetiere();
                                        degatHero=-joueurs[joueur[p]].getActive()->getPv();
                                        joueurs[joueur[p]].perdreVie4(degatHero);
                                        joueurs[joueur[p]].detruire();
                                    }
                                }

                            }
                            else if ((choixx==1)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<1))
                            {
                                gotoligcol(37,147);
                                std::cout<<"                                   ";
                                gotoligcol(38,147);
                                std::cout<<"                                   ";
                                gotoligcol(40,147);
                                std::cout<<"                                ";
                                gotoligcol(42,147);
                                std::cout<<"                                ";
                                gotoligcol(44,147);
                                std::cout<<"                                ";
                                gotoligcol(39,147);
                                std::cout<<"  Vous n'avez pas assez d'energie";
                                gotoligcol(41,147);
                                std::cout<<"       vous passez votre tour";
                                gotoligcol(45,2);
                                system("Pause");
                            }
                            if ((choixx==2)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=2))
                            {
                                if(joueurs[joueur[p]].getActive()==NULL)
                                {
                                    joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque2());
                                }

                                else if(joueurs[joueur[p]].getActive()!=NULL)
                                {
                                    joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque2());
                                    if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                    {
                                        int degatHero=0;
                                        joueurs[joueur[p]].cimetiere();
                                        degatHero=-joueurs[joueur[p]].getActive()->getPv();
                                        joueurs[joueur[p]].perdreVie4(degatHero);
                                        joueurs[joueur[p]].detruire();
                                    }
                                }

                            }
                            else if ((choixx==2)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<2))
                            {
                                gotoligcol(37,147);
                                std::cout<<"                                   ";
                                gotoligcol(38,147);
                                std::cout<<"                                   ";
                                gotoligcol(40,147);
                                std::cout<<"                                ";
                                gotoligcol(42,147);
                                std::cout<<"                                ";
                                gotoligcol(44,147);
                                std::cout<<"                                ";
                                gotoligcol(39,147);
                                std::cout<<"  Vous n'avez pas assez d'energie";
                                gotoligcol(41,147);
                                std::cout<<"       vous passez votre tour";
                                gotoligcol(45,2);
                                system("Pause");
                            }
                            if ((choixx==3)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=3))
                            {
                                if(joueurs[joueur[p]].getActive()==NULL)
                                {
                                    joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque3());
                                }

                                else if(joueurs[joueur[p]].getActive()!=NULL)
                                {
                                    joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque3());
                                    if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                    {
                                        int degatHero=0;
                                        joueurs[joueur[p]].cimetiere();
                                        degatHero=-joueurs[joueur[p]].getActive()->getPv();
                                        joueurs[joueur[p]].perdreVie4(degatHero);
                                        joueurs[joueur[p]].detruire();
                                    }
                                }


                            }
                            else if ((choixx==3)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<3))
                            {
                                gotoligcol(37,147);
                                std::cout<<"                                   ";
                                gotoligcol(38,147);
                                std::cout<<"                                   ";
                                gotoligcol(40,147);
                                std::cout<<"                                ";
                                gotoligcol(42,147);
                                std::cout<<"                                ";
                                gotoligcol(44,147);
                                std::cout<<"                                ";
                                gotoligcol(39,147);
                                std::cout<<"  Vous n'avez pas assez d'energie";
                                gotoligcol(41,147);
                                std::cout<<"       vous passez votre tour";
                                gotoligcol(45,2);
                                system("Pause");
                            }
                        }
                    }

                }
            }

            /// ----------------------CARTES SPE -------------------------///

            else if( joueurs[joueur[i]].getMain()->getId() >25 && joueurs[joueur[i]].getMain()->getId() <38)
            {
                gotoligcol(37,68);
                std :: cout << "Vous avez actuellement la carte ";
                Color(12,0);
                std :: cout << joueurs[joueur[i]].getMain()->getNom();
                gotoligcol(38,68);
                Color(15,0);
                std :: cout << "dans votre main.";
                gotoligcol(41,68);
                Color(14,0);
                std :: cout << "Veuillez vous referer a la TABLE DES ACTIONS pour";
                gotoligcol(42,68);
                std :: cout << "savoir ce que vous pouvez faire";
                Color(15,0);
                if (joueurs[joueur[i]].getMain()->getId()==26)
                {
                    gotoligcol(0,0);
                    Color(10,0);
                    std :: cout <<"INFOS" << std :: endl << std :: endl;
                    std :: cout << "REVELE VOTRE CARTE ENJEU";
                }

                if(joueurs[joueur[i]].getMain()->getId()==27)
                {
                    gotoligcol(0,0);
                    Color(10,0);
                    std :: cout <<"INFOS" << std :: endl << std :: endl;
                    std :: cout << "PERMET DE DETRUIRE UNE CARTE ENERGIE DE VOTRE ADVERSAIRE";
                }

                if(joueurs[joueur[i]].getMain()->getId()==28)
                {
                    gotoligcol(0,0);
                    Color(10,0);
                    std :: cout <<"INFOS" << std :: endl << std :: endl;
                    std :: cout << "PERMET DE RECUPERER UNE CARTE MORTE DU CIMETIERE";
                }

                if(joueurs[joueur[i]].getMain()->getId()==29)
                {
                    gotoligcol(0,0);
                    Color(10,0);
                    std :: cout <<"INFOS" << std :: endl << std :: endl;
                    std :: cout << "ECHANGE UNE CARTE DE VOTRE DECK AVEC VOTRE CARTE ENJEU";
                }

                if(joueurs[joueur[i]].getMain()->getId()==30)
                {
                    gotoligcol(0,0);
                    Color(10,0);
                    std :: cout <<"INFOS" << std :: endl << std :: endl;
                    std :: cout << "DETRUIT TOUTES LES CREATURES SUR LE PLATEAU";
                }

                if (joueurs[joueur[i]].getMain()->getId()==31)
                {
                    gotoligcol(0,0);
                    Color(10,0);
                    std :: cout <<"INFOS" << std :: endl << std :: endl;
                    std :: cout << "MET TOUTE LES ENERGIES A 1";
                }

                if(joueurs[joueur[i]].getMain()->getId()==32)
                {
                    gotoligcol(0,0);
                    Color(10,0);
                    std :: cout <<"INFOS" << std :: endl << std :: endl;
                    std :: cout << "RENVOIE VOTRE CREATURE DANS VOTRE DECK AVEC TOUT SES POINTS DE VIE";

                }

                if(joueurs[joueur[i]].getMain()->getId()==33)
                {
                    gotoligcol(0,0);
                    Color(10,0);
                    std :: cout <<"INFOS" << std :: endl << std :: endl;
                    std :: cout << "ENVOIE UNE CARTE ALEATOIRE DU DECK DE VOTRE ADVERSAIRE DANS LE CIMETIERE";
                }

                if (joueurs[joueur[i]].getMain()->getId()==34)
                {
                    gotoligcol(0,0);
                    Color(10,0);
                    std :: cout <<"INFOS" << std :: endl << std :: endl;
                    std :: cout << "INVOQUE UNE CARTE ENERGIE ALEATOIRE";
                }

                if (joueurs[joueur[i]].getMain()->getId()==35)
                {
                    gotoligcol(0,0);
                    Color(10,0);
                    std :: cout <<"INFOS" << std :: endl << std :: endl;
                    std :: cout << "VOTRE ADVERSAIRE DOIT PASSER SON PROCHAIN TOUR";
                }

                Color(15,0);
                gotoligcol(37,147);
                std :: cout << "Vous pouvez effectuer ces 2 actions";
                gotoligcol(40,147);
                std::cout << "1. Jouer la carte speciale";
                gotoligcol(42,147);
                std::cout << "2. Remettre dans le deck";
                gotoligcol(44,147);
                Color(9,0);
                std :: cout << "Saisir : ";
                Color(15,0);
                std::cin>>choix3;

                while((choix3<1) || (choix3>2))
                {
                    gotoligcol(44,147);
                    Color(9,0);
                    std :: cout << "Saisir :       ";
                    gotoligcol(44,147);
                    Color(9,0);
                    std :: cout << "Saisir : ";
                    Color(15,0);
                    std::cin>>choix3;
                }


                if(choix3==1)
                {
                    if (joueurs[joueur[i]].getMain()->getId()==26)
                    {
                        joueurs[joueur[i]].affichEnjeu2();
                        joueurs[joueur[i]].cimetiere2(joueurs[joueur[i]].getMain());
                        gotoligcol(44,1);
                        system("Pause");
                    }

                    if(joueurs[joueur[i]].getMain()->getId()==27)
                    {
                        int m=0;
                        srand(time(NULL));
                        m=(rand() % (3+1))+0;

                        if(joueurs[joueur[p]].getEnergie2(m)!=0)
                        {
                            joueurs[joueur[p]].setEnergie2(m);
                            joueurs[joueur[p]].affichEnergie();
                            gotoligcol(44,1);
                            system("Pause");
                            joueurs[joueur[i]].affichEnergie();
                        }
                        joueurs[joueur[i]].cimetiere2(joueurs[joueur[i]].getMain());
                    }

                    if(joueurs[joueur[i]].getMain()->getId()==28)
                    {
                        if(joueurs[joueur[i]].getCimetiere().size()!=0)
                        {
                            joueurs[joueur[i]].recupCimetiere();
                            joueurs[joueur[i]].melangedeck();
                        }
                        joueurs[joueur[i]].cimetiere2(joueurs[joueur[i]].getMain());

                    }

                    if(joueurs[joueur[i]].getMain()->getId()==29)
                    {
                        joueurs[joueur[i]].remettre_carte(joueurs[joueur[i]].getEnjeu());
                        joueurs[joueur[i]].melangedeck();
                        joueurs[joueur[i]].carte_enjeu();
                        joueurs[joueur[i]].cimetiere2(joueurs[joueur[i]].getMain());
                    }

                    if(joueurs[joueur[i]].getMain()->getId()==30)
                    {
                        if(joueurs[joueur[i]].getActive()!=NULL)
                        {
                            joueurs[joueur[i]].cimetiere();
                            joueurs[joueur[i]].detruire();
                        }
                        if(joueurs[joueur[p]].getActive()!=NULL)
                        {
                            joueurs[joueur[p]].cimetiere();
                            joueurs[joueur[p]].detruire();
                        }
                        joueurs[joueur[i]].cimetiere2(joueurs[joueur[i]].getMain());
                    }

                    if (joueurs[joueur[i]].getMain()->getId()==31)
                    {
                        joueurs[joueur[i]].setEnergie(0);
                        joueurs[joueur[i]].setEnergie(1);
                        joueurs[joueur[i]].setEnergie(2);
                        joueurs[joueur[i]].setEnergie(3);
                        joueurs[joueur[i]].cimetiere2(joueurs[joueur[i]].getMain());
                    }

                    if(joueurs[joueur[i]].getMain()->getId()==32)
                    {
                        if(joueurs[joueur[i]].getActive()!=NULL)
                        {
                            joueurs[joueur[i]].remettre_carte(joueurs[joueur[i]].getActive());
                        }
                        joueurs[joueur[i]].cimetiere2(joueurs[joueur[i]].getMain());

                    }

                    if(joueurs[joueur[i]].getMain()->getId()==33)
                    {
                        joueurs[joueur[p]].Troie();
                        joueurs[joueur[i]].cimetiere2(joueurs[joueur[i]].getMain());
                    }

                    if (joueurs[joueur[i]].getMain()->getId()==34)
                    {
                        int u=0;
                        srand(time(NULL));
                        u=(rand() % (3+1))+1;
                        joueurs[joueur[i]].setEnergie(u);
                        joueurs[joueur[i]].affichEnergie();
                        joueurs[joueur[i]].cimetiere2(joueurs[joueur[i]].getMain());
                    }

                    if (joueurs[joueur[i]].getMain()->getId()==35)
                    {
                        o=1;
                        joueurs[joueur[i]].cimetiere2(joueurs[joueur[i]].getMain());
                    }

                    if (joueurs[joueur[i]].getActive()!=NULL)
                    {
                        gotoligcol(40,147);
                        std::cout<<"                                ";
                        gotoligcol(42,147);
                        std::cout<<"                                ";
                        gotoligcol(44,147);
                        std::cout<<"                                ";
                        gotoligcol(40,147);
                        std::cout<<"1. Attaquer avec la carte active";
                        gotoligcol(42,147);
                        std::cout<<"2. Passer le tour";
                        gotoligcol(44,147);
                        int choi;
                        Color(9,0);
                        std :: cout << "Saisir : ";
                        Color(15,0);
                        std::cin>>choi;

                        while((choi<1) || (choi>2))
                        {
                            gotoligcol(44,147);
                            Color(9,0);
                            std :: cout << "Saisir :       ";
                            gotoligcol(44,147);
                            Color(9,0);
                            std :: cout << "Saisir : ";
                            Color(15,0);
                            std::cin>>choi;
                        }

                        if(choi==1)
                        {
                            gotoligcol(40,147);
                            std::cout<<"                                ";
                            gotoligcol(42,147);
                            std::cout<<"                                ";
                            gotoligcol(44,147);
                            std::cout<<"                                ";
                            gotoligcol(39,147);
                            std::cout<<"1. Attaque 1"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque1() <<std::endl;
                            gotoligcol(40,147);
                            std::cout<<"2. Attaque 2"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque2() <<std::endl;
                            gotoligcol(41,147);
                            std::cout<<"3. Attaque 3"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque3() <<std::endl;
                            gotoligcol(42,147);
                            std::cout<<"4. Passer le tour";
                            gotoligcol(44,147);
                            int choixx;
                            Color(9,0);
                            std :: cout << "Saisir : ";
                            Color(15,0);
                            std::cin>>choixx;

                            while((choixx<1) || (choixx>4))
                            {
                                gotoligcol(44,147);
                                Color(9,0);
                                std :: cout << "Saisir :       ";
                                gotoligcol(44,147);
                                Color(9,0);
                                std :: cout << "Saisir : ";
                                Color(15,0);
                                std::cin>>choixx;
                            }

                            if ((choixx==1)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=1))
                            {
                                if(joueurs[joueur[p]].getActive()!=NULL)
                                {
                                    joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque1());
                                    if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                    {
                                        joueurs[joueur[p]].cimetiere();
                                        joueurs[joueur[p]].detruire();
                                    }
                                }

                                if(joueurs[joueur[p]].getActive()==NULL)
                                {
                                    joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque1());
                                }
                            }
                            else if ((choixx==1)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<1))
                            {
                                gotoligcol(37,147);
                                std::cout<<"                                   ";
                                gotoligcol(38,147);
                                std::cout<<"                                   ";
                                gotoligcol(40,147);
                                std::cout<<"                                ";
                                gotoligcol(42,147);
                                std::cout<<"                                ";
                                gotoligcol(44,147);
                                std::cout<<"                                ";
                                gotoligcol(39,147);
                                std::cout<<"  Vous n'avez pas assez d'energie";
                                gotoligcol(41,147);
                                std::cout<<"       vous passez votre tour";
                                gotoligcol(45,2);
                                system("Pause");
                            }
                            if ((choixx==2)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=2))
                            {
                                if(joueurs[joueur[p]].getActive()!=NULL)
                                {
                                    joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque2());
                                    if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                    {
                                        joueurs[joueur[p]].cimetiere();
                                        joueurs[joueur[p]].detruire();
                                    }
                                }

                                if(joueurs[joueur[p]].getActive()==NULL)
                                {
                                    joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque2());
                                }
                            }
                            else if ((choixx==2)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<2))
                            {
                                gotoligcol(37,147);
                                std::cout<<"                                   ";
                                gotoligcol(38,147);
                                std::cout<<"                                   ";
                                gotoligcol(40,147);
                                std::cout<<"                                ";
                                gotoligcol(42,147);
                                std::cout<<"                                ";
                                gotoligcol(44,147);
                                std::cout<<"                                ";
                                gotoligcol(39,147);
                                std::cout<<"  Vous n'avez pas assez d'energie";
                                gotoligcol(41,147);
                                std::cout<<"       vous passez votre tour";
                                gotoligcol(45,2);
                                system("Pause");
                            }
                            if ((choixx==3)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=3))
                            {
                                if(joueurs[joueur[p]].getActive()!=NULL)
                                {
                                    joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque3());
                                    if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                    {
                                        joueurs[joueur[p]].cimetiere();
                                        joueurs[joueur[p]].detruire();
                                    }
                                }

                                if(joueurs[joueur[p]].getActive()==NULL)
                                {
                                    joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque3());
                                }
                            }
                            else if ((choixx==3)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<3))
                            {
                                gotoligcol(37,147);
                                std::cout<<"                                   ";
                                gotoligcol(38,147);
                                std::cout<<"                                   ";
                                gotoligcol(40,147);
                                std::cout<<"                                ";
                                gotoligcol(42,147);
                                std::cout<<"                                ";
                                gotoligcol(44,147);
                                std::cout<<"                                ";
                                gotoligcol(39,147);
                                std::cout<<"  Vous n'avez pas assez d'energie";
                                gotoligcol(41,147);
                                std::cout<<"       vous passez votre tour";
                                gotoligcol(45,2);
                                system("Pause");
                            }
                        }
                    }
                }

                else if(choix3==2)
                {
                    joueurs[joueur[i]].remettre_carte(joueurs[joueur[i]].getMain());
                    if (joueurs[joueur[i]].getActive()!=NULL)
                    {
                        gotoligcol(40,147);
                        std::cout<<"                                ";
                        gotoligcol(42,147);
                        std::cout<<"                                ";
                        gotoligcol(44,147);
                        std::cout<<"                                ";
                        gotoligcol(40,147);
                        std::cout<<"1. Attaquer avec la carte active";
                        gotoligcol(42,147);
                        std::cout<<"2. Passer le tour";
                        gotoligcol(44,147);
                        int choi;
                        Color(9,0);
                        std :: cout << "Saisir : ";
                        Color(15,0);
                        std::cin>>choi;

                        while((choi<1) || (choi>2))
                        {
                            gotoligcol(44,147);
                            Color(9,0);
                            std :: cout << "Saisir :       ";
                            gotoligcol(44,147);
                            Color(9,0);
                            std :: cout << "Saisir : ";
                            Color(15,0);
                            std::cin>>choi;
                        }

                        if(choi==1)
                        {
                            gotoligcol(40,147);
                            std::cout<<"                                ";
                            gotoligcol(42,147);
                            std::cout<<"                                ";
                            gotoligcol(44,147);
                            std::cout<<"                                ";
                            gotoligcol(39,147);
                            std::cout<<"1. Attaque 1"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque1() <<std::endl;
                            gotoligcol(40,147);
                            std::cout<<"2. Attaque 2"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque2() <<std::endl;
                            gotoligcol(41,147);
                            std::cout<<"3. Attaque 3"<< " Degats : "<< joueurs[joueur[i]].getActive()->getAttaque3() <<std::endl;
                            gotoligcol(42,147);
                            std::cout<<"4. Passer le tour";
                            gotoligcol(44,147);
                            int choixx;
                            Color(9,0);
                            std :: cout << "Saisir : ";
                            Color(15,0);
                            std::cin>>choixx;

                            while((choixx<1) || (choixx>4))
                            {
                                gotoligcol(44,147);
                                Color(9,0);
                                std :: cout << "Saisir :       ";
                                gotoligcol(44,147);
                                Color(9,0);
                                std :: cout << "Saisir : ";
                                Color(15,0);
                                std::cin>>choixx;
                            }

                            if ((choixx==1)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=1))
                            {
                                if(joueurs[joueur[p]].getActive()!=NULL)
                                {
                                    joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque1());
                                    if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                    {
                                        joueurs[joueur[p]].cimetiere();
                                        joueurs[joueur[p]].detruire();
                                    }
                                }

                                if(joueurs[joueur[p]].getActive()==NULL)
                                {
                                    joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque1());
                                }
                            }
                            else if ((choixx==1)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<1))
                            {
                                gotoligcol(37,147);
                                std::cout<<"                                   ";
                                gotoligcol(38,147);
                                std::cout<<"                                   ";
                                gotoligcol(40,147);
                                std::cout<<"                                ";
                                gotoligcol(42,147);
                                std::cout<<"                                ";
                                gotoligcol(44,147);
                                std::cout<<"                                ";
                                gotoligcol(39,147);
                                std::cout<<"  Vous n'avez pas assez d'energie";
                                gotoligcol(41,147);
                                std::cout<<"       vous passez votre tour";
                                gotoligcol(45,2);
                                system("Pause");
                            }
                            if ((choixx==2)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=2))
                            {
                                if(joueurs[joueur[p]].getActive()!=NULL)
                                {
                                    joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque2());
                                    if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                    {
                                        joueurs[joueur[p]].cimetiere();
                                        joueurs[joueur[p]].detruire();
                                    }
                                }

                                if(joueurs[joueur[p]].getActive()==NULL)
                                {
                                    joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque2());
                                }
                            }
                            else if ((choixx==2)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<2))
                            {
                                gotoligcol(37,147);
                                std::cout<<"                                   ";
                                gotoligcol(38,147);
                                std::cout<<"                                   ";
                                gotoligcol(40,147);
                                std::cout<<"                                ";
                                gotoligcol(42,147);
                                std::cout<<"                                ";
                                gotoligcol(44,147);
                                std::cout<<"                                ";
                                gotoligcol(39,147);
                                std::cout<<"  Vous n'avez pas assez d'energie";
                                gotoligcol(41,147);
                                std::cout<<"       vous passez votre tour";
                                gotoligcol(45,2);
                                system("Pause");
                            }
                            if ((choixx==3)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)>=3))
                            {
                                if(joueurs[joueur[p]].getActive()!=NULL)
                                {
                                    joueurs[joueur[p]].perdreVie2(joueurs[joueur[i]].getActive()->getAttaque3());
                                    if(joueurs[joueur[p]].getActive()->getPv()<=0)
                                    {
                                        joueurs[joueur[p]].cimetiere();
                                        joueurs[joueur[p]].detruire();
                                    }
                                }

                                if(joueurs[joueur[p]].getActive()==NULL)
                                {
                                    joueurs[joueur[p]].perdreVie4(joueurs[joueur[i]].getActive()->getAttaque3());
                                }
                            }
                            else if ((choixx==3)&&(joueurs[joueur[i]].getEnergieParticuliere(joueurs[joueur[i]].getActive()->getType()-1)<3))
                            {
                                gotoligcol(37,147);
                                std::cout<<"                                   ";
                                gotoligcol(38,147);
                                std::cout<<"                                   ";
                                gotoligcol(40,147);
                                std::cout<<"                                ";
                                gotoligcol(42,147);
                                std::cout<<"                                ";
                                gotoligcol(44,147);
                                std::cout<<"                                ";
                                gotoligcol(39,147);
                                std::cout<<"  Vous n'avez pas assez d'energie";
                                gotoligcol(41,147);
                                std::cout<<"       vous passez votre tour";
                                gotoligcol(45,2);
                                system("Pause");
                            }
                        }
                    }
                }

            }

            gotoligcol(45,2);
            system("cls");
            Color(15,0);

            if( (joueurs[joueur[p]].getPv() <= 0)||(joueurs[joueur[p]].getDeck().size()==0))
            {
                system("cls");
                for (int i=13; i<22; i++)
                {
                    gotoligcol(i,83);
                    std :: cout << trait2;
                    gotoligcol(i,133);
                    std :: cout << trait2;
                }

                gotoligcol(13,83);
                std :: cout << trait3;
                gotoligcol(13,133);
                std :: cout << trait4;
                gotoligcol(21,83);
                std :: cout << trait1;
                gotoligcol(21,133);
                std :: cout << trait5;

                for (int i=84; i<133; i++)
                {
                    gotoligcol(13,i);
                    std :: cout << trait;
                    gotoligcol(21,i);
                    std :: cout << trait;
                }
                gotoligcol(15,85);
                std :: cout << "Victoire : ";
                gotoligcol(17,85);
                std :: cout << "Ecus gagnes : ";
                gotoligcol(19,85);
                std :: cout << "Carte enjeu remportee : ";
                gotoligcol(15,96);
                Color(14,0);
                Sleep(1500);
                std::cout << joueurs[joueur[i]].getPseudo();
                Color(11,0);
                gotoligcol(17,98);
                Sleep(1500);
                std :: cout << "+15";
                gotoligcol(19,109);
                Color(12,0);
                Sleep(2500);
                joueurs[joueur[p]].affichEnjeu();
                Color(15,0);
                joueurs[joueur[i]].ajouterCarte2(joueurs[joueur[p]].getEnjeu());
                joueurs[joueur[i]].Victory();
                joueurs[joueur[p]].Defeat();
                sortie=1;
                gotoligcol(23,0);
                system("Pause");
                i=2;
            }
            if(o==1)
            {
                if(i==0)
                {
                    i=2;
                }
                else if(i==1)
                {
                    i=0;
                }
            }
        }
    }
    return joueurs;
}
