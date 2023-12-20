#include <iostream>
#include <vector>
#include <time.h>
#include "Carte.h"
#include "Creature.h"
#include "Deck.h"
#include "Energie.h"
#include "Hero.h"
#include "Special.h"
#include "Affichage.h"
#include <fstream>

// CHANGER LA TAILLE DE LA FENETRE EN 187 PAR 47

struct csv_whitespace : std::ctype<char>
{
    static const mask* make_table()
    {
        static std::vector<mask> v(classic_table(), classic_table() + table_size);
        v['|'] |=  space;
        v['\n'] |=  space;
        v[' '] &= ~space;
        return &v[0];
    }
    csv_whitespace(std::size_t refs = 0) : ctype(make_table(), false, refs) {}
};

int main()
{
    srand(time(NULL));
    std::vector <Carte*> bibliotheque;
    std::vector <Hero> joueurs;

    system("cls");
    joueurs.clear();
    std::ifstream fs("joueurs.txt");
    if(fs.is_open())
    {
        fs.imbue(std::locale(fs.getloc(), new csv_whitespace));

        int nb;
        fs >> nb ;
        for (int i=0; i < nb ; i++)
        {
            Hero h;
            fs >> h;
            joueurs.push_back(h);

        }
    }
    int action=0;

    // INITIALISATION CARTES CREATURES //

    // LEGENDAIRE //

    Creature C1 ("LOUIS XIV",2,1,130,72,25,30,38);
    bibliotheque.push_back(&C1);
    Creature C2 ("NAPOLEON",3,2,130,52,25,31,39);
    bibliotheque.push_back(&C2);
    Creature C3("JEANNE D ARC",4,3,130,19,0,0,50);
    bibliotheque.push_back(&C3);

    // EPIQUE //

    Creature C4 ("CHARLEMAGNE",3,4,80,46,0,25,31);
    bibliotheque.push_back(&C4);
    Creature C5 ("CLOVIS",1,5,80,29,0,26,33);
    bibliotheque.push_back(&C5);
    Creature C6 ("VERCINGETORIX",1,6,80,30,0,0,32);
    bibliotheque.push_back(&C6);
    Creature C7 ("BLANCHE DE CASTILLE",4,7,80,64,23,26,35);
    bibliotheque.push_back(&C7);
    Creature C8 ("MARIE-ANTOINETTE",2,8,80,38,0,23,29);
    bibliotheque.push_back(&C8);
    Creature C9 ("FRANCOIS 1ER",2,9,80,53,24,26,28);
    bibliotheque.push_back(&C9);

    // RARE //

    Creature C10 ("LOUIS XVI",2,10,35,39,0,20,25);
    bibliotheque.push_back(&C10);
    Creature C11 ("LOUIS XV",2,11,35,64,17,20,23);
    bibliotheque.push_back(&C11);
    Creature C12 ("SAINT LOUIS",4,12,35,56,16,23,25);
    bibliotheque.push_back(&C12);
    Creature C13 ("PHILIPPE IV LE BEL",1,13,35,46,18,20,24);
    bibliotheque.push_back(&C13);
    Creature C14 ("HENRI IV",3,14,35,57,0,20,25);
    bibliotheque.push_back(&C14);
    Creature C15 ("CHARLES VII",1,15,35,58,16,20,26);
    bibliotheque.push_back(&C15);
    Creature C16 ("PEPIN LE BREF",1,16,35,54,17,19,26);
    bibliotheque.push_back(&C16);
    Creature C17 ("LOUIS XI",3,17,35,60,16,18,24);
    bibliotheque.push_back(&C17);
    Creature C18 ("MARIE DE MEDICIS",4,18,35,67,18,20,24);
    bibliotheque.push_back(&C18);
    Creature C19 ("ALIENOR D AQUITAINE",3,19,35,82,18,20,22);
    bibliotheque.push_back(&C19);
    Creature C20 ("MARIE CURIE",4,20,35,67,19,21,23);
    bibliotheque.push_back(&C20);
    Creature C21 ("OLYMPES DE GOUGES",4,21,35,45,20,21,22);
    bibliotheque.push_back(&C21);


    // INITIALISATION CARTES ENERGIES //

    Energie Epee ("Energie Epee",1,22,10);
    bibliotheque.push_back(&Epee);

    Energie Couronne ("Energie Couronne",2,23,10);
    bibliotheque.push_back(&Couronne);

    Energie Sceptre ("Energie Sceptre",3,24,10);
    bibliotheque.push_back(&Sceptre);

    Energie MainJustice ("Energie Main de Justice",4,25,10);
    bibliotheque.push_back(&MainJustice);

    // INITIALISATION CARTES SPECIALES //

    Special S1 ("REVELATION",5,26,20,"REVELE VOTRE CARTE ENJEU"); ///
    bibliotheque.push_back(&S1);
    Special S2 ("MALICE",6,27,20,"PERMET DE DETRUIRE UNE CARTE ENERGIE DE VOTRE ADVERSAIRE"); ///
    bibliotheque.push_back(&S2);
    Special S3 ("RESURRECTION",7,28,20,"PERMET DE RECUPERER UNE CARTE MORTE DU CIMETIERE"); //
    bibliotheque.push_back(&S3);
    Special S4 ("ECHANGE",8,29,40,"ECHANGE UNE CARTE DE VOTRE DECK AVEC VOTRE CARTE ENJEU"); ///
    bibliotheque.push_back(&S4);
    Special S5 ("DESTRUCTION",9,30,30,"DETRUIT TOUTES LES CREATURES SUR LE PLATEAU"); ///
    bibliotheque.push_back(&S5);
    Special S6 ("NOUVEAU DEPART",16,31,35,"MET TOUTE LES ENERGIES A 1"); ///
    bibliotheque.push_back(&S6);
    Special S8 ("SECONDE CHANCE",12,32,35,"RENVOIE VOTRE CREATURE DANS VOTRE DECK AVEC TOUS SES POINTS DE VIE"); ///
    bibliotheque.push_back(&S8);
    Special S9 ("CHEVAL DE TROIE",13,33,30,"ENVOIE UNE CARTE ALEATOIRE DU DECK DE VOTRE ADVERSAIRE DANS LE CIMETIERE"); ///
    bibliotheque.push_back(&S9);
    Special S10 ("INVOCATION",14,34,20,"INVOQUE UNE CARTE ENERGIE ALEATOIRE"); ///
    bibliotheque.push_back(&S10);
    Special S11 ("ENTOURLOUPE",15,35,20,"VOTRE ADVERSAIRE DOIT PASSER SON PROCHAIN TOUR"); ///
    bibliotheque.push_back(&S11);

    TUTO();

    do
    {
        switch (action)
        {
        case 0:
        {
            action=Ecran_Acceuil();
        }
        break;
        case 1:
        {
            joueurs=Jouer(joueurs);
            action=0;
        }
        break;
        case 2:
        {
            joueurs = Caserne(joueurs,bibliotheque);
            system("cls");

            system("cls");
            std::cout<<"Sauvegarde en cours"<<std::endl;
            std::ofstream fs("joueurs.txt");
            fs << joueurs.size() << "|";
            for (auto i : joueurs)
            {
                fs << i << std::endl;
            }

            action=0;
        }
        break;
        case 3:
        {
            joueurs = Taverne (joueurs,bibliotheque);
            system("cls");

            system("cls");
            std::cout<<"Sauvegarde en cours"<<std::endl;
            std::ofstream fs("joueurs.txt");
            fs << joueurs.size() << "|";
            for (auto i : joueurs)
            {
                fs << i << std::endl;
            }
            std::cout<<"saved"<<std::endl;

            action=0;
        }
        break;
        case 4:
        {
            Reglement();
            system("cls");
            action=0;
        }
        break;
        case 5:
        {
            joueurs.push_back(NewJoueur(bibliotheque));
            system("cls");

            system("cls");
            std::cout<<"Sauvegarde en cours"<<std::endl;
            std::ofstream fs("joueurs.txt");
            fs << joueurs.size() << "|";
            for (auto i : joueurs)
            {
                fs << i << std::endl;
            }
            std::cout<<"saved"<<std::endl;
            action=0;
        }
        break;


        }

    }
    while (action!=8);

    return 0;
}
