#include "Hero.h"
#include "Special.h"
#include "Creature.h"
#include "Energie.h"
#include "Affichage.h"
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <random>
#include <algorithm>
#include <iterator>

Hero::Hero() :m_pseudo(),m_mdp(),m_ecus(0),m_victoire(0),m_pv(0),m_enjeu(NULL)
{
    //Constructeur
    for (int i=0; i<4; i++)
    {
        m_energie[i]=0;
    }
}

Hero::Hero (std::string _pseudo,std::string _mdp)
{
    m_pseudo=_pseudo;
    m_mdp=_mdp;
    m_ecus=100;
    m_victoire=0;
    m_pv=150;
    for (int i=0; i<4; i++)
    {
        m_energie[i]=0;
    }
}

Hero::~Hero()
{
    //Destructeur
}

std::string Hero::getPseudo()
{
    return m_pseudo;
}

std::string Hero::getMdp()
{
    return m_mdp;
}

int Hero::getEcus()
{
    return m_ecus;
}

int Hero::getVictoire()
{
    return m_victoire;
}

int Hero::getPv()
{
    return m_pv;
}

Carte* Hero::getMain()
{
    return m_main;
}

std::deque <Carte*> Hero::getDeck()
{
    return m_deck;
}

std::vector <Carte*> Hero::getCollection()
{
    return m_collection;
}

int Hero::getEnergie2(int x)
{
    return m_energie[x];
}

int Hero::getEnergieParticuliere(int i)
{
    return m_energie[i];
}

void Hero::setEnergie(int i)
{
    m_energie[i]++;
}

void Hero::setEnergie2(int i)
{
    m_energie[i]--;
}

void Hero::recupCimetiere()
{
    int m=0;
    m=(rand() % (m_cimetiere.size()+1))+0;
    m_deck.push_back(m_cimetiere[m]);
    m_cimetiere.erase(m_cimetiere.begin()+m);
}

void Hero::cimetiere()
{
    m_cimetiere.push_back(m_active);
}

void Hero::cimetiere2(Carte* carte)
{
    m_cimetiere.push_back(carte);
}

void Hero::detruire()
{
    m_active=NULL;
}

void Hero::Victory()
{
    m_ecus=m_ecus+15;
    m_victoire++;
    /// rajouter la carte enjeu de l'adversaire ( envoye en parametre) dans la collection du joueur.
}

void Hero::Defeat()
{
    m_ecus=m_ecus+5;
}

std::deque <Carte*> Hero::getCimetiere()
{
    return m_cimetiere;
}

void Hero::affichEnergie()
{
    Color(14,0);
    gotoligcol(15,160);
    std::cout<<this->getPseudo();
    Color(15,0);
    for (int i=0; i<4; i++)
    {
        if (i==0)
        {
            gotoligcol(18,147);
            Color(15,0);
            std::cout<< "Energie Epee : ";
            gotoligcol(18,163);
            Color(11,0);
            std :: cout << m_energie[i];
            Color(15,0);
            std :: cout << "  (E = 1)";
        }

        if (i==1)
        {
            gotoligcol(20,147);
            Color(15,0);
            std::cout<< "Energie Couronne : ";
            gotoligcol(20,166);
            Color(11,0);
            std :: cout << m_energie[i];
            Color(15,0);
            std :: cout << "  (C = 2)";
        }

        if (i==2)
        {
            gotoligcol(22,147);
            Color(15,0);
            std::cout<< "Energie Sceptre : ";
            gotoligcol(22,165);
            Color(11,0);
            std :: cout << m_energie[i];
            Color(15,0);
            std :: cout << "  (S = 3)";
        }

        if (i==3)
        {
            gotoligcol(24,147);
            Color(15,0);
            std::cout<< "Energie Main de Justice : ";
            gotoligcol(24,173);
            Color(11,0);
            std :: cout << m_energie[i];
            Color(15,0);
            std :: cout << "  (J = 4)";
        }

    }
    Color(15,0);
}

Creature* Hero::getActive()
{
    return m_active;
}


void Hero :: init()
{
    m_pv=150;
    for (int i=0; i<4; i++)
    {
        m_energie[i]=0;
    }
    m_active=NULL;
    m_enjeu=NULL;
    m_main=NULL;
    while (!m_deck.empty())
    {
        m_deck.pop_back();
    }

    for (int i=0; i<(int)m_deck_initial.size(); i++)
    {
        m_deck.push_back(m_deck_initial[i]);
    }
}

void Hero::poserActive()
{
    m_active = (Creature*)m_main;
}

void Hero::affichActive()
{
    std::cout << m_active->getNom();
}

int Hero::Pioche()
{
    return m_deck.size();
}

void Hero::ajouterCarte(std::vector <Carte*> Bibliotheque,int x)
{
    m_collection.push_back(Bibliotheque[x-1]);
}

void Hero::ajouterCarte2(Carte* c)
{
    m_collection.push_back(c);
}

void Hero::retirerCarte(std::vector <Carte*> Bibliotheque,int x)
{
    m_collection.erase(Bibliotheque.begin()+x-1);
}

void Hero::ajouterCarteDeck()
{
    int nombre=0;
    int compteur=0;
    m_deck_initial.erase(m_deck_initial.begin(),m_deck_initial.end());
    std::vector<Carte*> copie=m_collection;
    std :: cout << std :: endl << "Voici votre collection :  ";
    Color(14,0);
    std :: cout << m_pseudo << std :: endl << std :: endl;
    Color(11,0);
    do
    {
        for(unsigned int i=0; i < copie.size() ; i++)
        {
            std::cout << i+1 <<" - "<< copie[i]->getNom() << std::endl;
        }

        Color(15,0);
        std :: cout << "\n" << "Saisissez l'id de la carte que vous voulez ajouter a votre deck : ";
        Color(11,0);
        std :: cin >> nombre;
        while ((nombre<1) || (nombre>((int)copie.size())))
        {
            Color(15,0);
            std :: cout << "\n" << "Saisissez l'id de la carte que vous voulez ajouter a votre deck : ";
            Color(11,0);
            std :: cin >> nombre;
        }
        std :: cout << std :: endl;
        Carte* copie2=new Carte;
        Carte* copie3=new Carte;
        if ((nombre>=1) && (nombre<=((int)copie.size()+1)))
        {
            copie2=copie[nombre-1];
            copie3=copie[nombre-1];
            m_deck.push_back(copie2);
            m_deck_initial.push_back(copie3);
            copie.erase(copie.begin()+(nombre-1));
            compteur++;
        }
    }
    while (compteur!=21);
    Color(15,0);
}

void Hero::affichDeckHero()
{
    Color(11,0);
    std :: cout << std :: endl;
    std :: vector <Carte*> p = m_deck_initial;
    for (int i=0; i<(int)m_deck_initial.size(); i++)
    {
        std::cout << "Nom : " << p[i]->getNom() << std::endl;
    }
    Color(15,0);
    system("Pause");
}

void Hero::affichCollectionHero ()
{
    std :: cout << std :: endl;
    std :: cout << "Voici votre collection : ";
    Color(14,0);
    std :: cout << m_pseudo << std :: endl << std :: endl;
    Color(11,0);
    for (unsigned int i=0; i<m_collection.size(); i++)
    {
        std::cout << "Nom : " << m_collection[i]->getNom() << std::endl;
        std::cout << "Prix : " << m_collection[i]->getPrix() << std::endl << std::endl;
    }
    Color(15,0);
    system("Pause");
}

void Hero::affichHero (std::vector<Carte*> Bibliotheque)
{

    int choix=0;
    int i;

    char ecus;
    char trait1;
    char trait2;
    char coin;

    ecus = 0x24;
    trait1 = 0xB3;
    trait2 = 0xC4;
    coin = 0xD9;

    Color(11,0);

    for ( i=1 ; i<7; i++)
    {
        gotoligcol(i,25);
        std :: cout << trait1;
    }

    for ( i=1; i<25; i++)
    {
        gotoligcol(6,i);
        std :: cout << trait2;
    }

    gotoligcol(6,25);
    std :: cout << coin;

    Color(15,0);
    gotoligcol(1,1);
    std::cout << "Pseudo : ";
    gotoligcol(1,10);
    Color(14,0);
    std :: cout << m_pseudo;
    gotoligcol(3,1);
    Color(15,0);
    std::cout << "Ecus : ";
    gotoligcol(3,8);
    Color(14,0);
    std :: cout << m_ecus << "  " << ecus;
    gotoligcol(5,1);
    Color(15,0);
    std::cout << "Victoires : ";
    gotoligcol(5,13);
    Color(14,0);
    std :: cout << m_victoire;

    gotoligcol(16,1);
    Color(15,0);
    std::cout << "Vous pouvez desormais : "<< "\n" << std::endl;
    std::cout << "1. Creer un deck a partir de votre collection"<<std::endl;
    std::cout << "2. Consulter votre collection"<<std::endl;
    std::cout << "3. Consulter votre deck"<<std::endl;
    std::cout << "4. Revenir a l ecran d acceuil"<<std::endl<<std::endl;

    std :: cout << "Saisir le choix : ";
    std :: cin >> choix;

    switch(choix)
    {

    case 1:
    {
        ajouterCarteDeck();
    }
    break;


    case 2:
    {
        affichCollectionHero();
    }
    break;

    case 3:
    {
        affichDeckHero();
    }
    break;
    case 4:
    {
        std :: cout << std :: endl;
        system("Pause");
    }
    break;

    }

}

void Hero::acheterCarte (std::vector <Carte*> Bibliotheque)
{
    int nombre;
    std :: cout << std :: endl << "Saisir le numero de la carte que vous voulez acheter :  ";
    Color(11,0);
    std :: cin >> nombre;
    while((nombre<1)||(nombre>37))
    {
        Color(15,0);
        std :: cout << std :: endl << "La carte ";
        Color(11,0);
        std :: cout << nombre;
        Color(15,0);
        std :: cout << " n existe pas !!" << std :: endl;
        std :: cout << "Veuillez ressaisir une carte : ";
        Color(11,0);
        std :: cin >> nombre;
    }
    Color(15,0);


    if( m_ecus>= Bibliotheque[nombre-1]->getPrix())
    {
        m_collection.push_back(Bibliotheque[nombre-1]);
        m_ecus=m_ecus-Bibliotheque[nombre-1]->getPrix();
        system("PAUSE");
    }
    else
    {
        std::cout << "Vous n'avez pas assez d ecus, faites des combats pour gagner des ecus ";
        system("PAUSE");
    }

}

void Hero::Affiche_deck_Newjoueur()
{
    gotoligcol(6,80);
    std::cout << "VOTRE COLLECTION : " << m_pseudo;

    Color(15,0);
    gotoligcol(10,16);
    std::cout << "Nom : " << m_collection[0]->getNom();
    gotoligcol(11,16);
    std::cout << "Prix : " << m_collection[0]->getPrix();


    gotoligcol(10,56);
    std::cout << "Nom : " << m_collection[1]->getNom();
    gotoligcol(11,56);
    std::cout << "Prix : " << m_collection[1]->getPrix();

    gotoligcol(13,56);
    std::cout << "Nom : " << m_collection[2]->getNom();
    gotoligcol(14,56);
    std::cout << "Prix : " << m_collection[2]->getPrix();

    gotoligcol(16,56);
    std::cout << "Nom : " << m_collection[3]->getNom();
    gotoligcol(17,56);
    std::cout << "Prix : " << m_collection[3]->getPrix();

    gotoligcol(19,56);
    std::cout << "Nom : " << m_collection[4]->getNom();
    gotoligcol(20,56);
    std::cout << "Prix : " << m_collection[4]->getPrix();

    gotoligcol(22,56);
    std::cout << "Nom : " << m_collection[5]->getNom();
    gotoligcol(23,56);
    std::cout << "Prix : " << m_collection[5]->getPrix();

///

    gotoligcol(10,96);
    std::cout << "Nom : " << m_collection[18]->getNom();
    gotoligcol(11,96);
    std::cout << "Prix : " << m_collection[18]->getPrix();

    gotoligcol(13,96);
    std::cout << "Nom : " << m_collection[19]->getNom();
    gotoligcol(14,96);
    std::cout << "Prix : " << m_collection[19]->getPrix();

    gotoligcol(16,96);
    std::cout << "Nom : " << m_collection[20]->getNom();
    gotoligcol(17,96);
    std::cout << "Prix : " << m_collection[20]->getPrix();

    gotoligcol(19,96);
    std::cout << "Nom : " << m_collection[21]->getNom();
    gotoligcol(20,96);
    std::cout << "Prix : " << m_collection[21]->getPrix();

    gotoligcol(22,96);
    std::cout << "Nom : " << m_collection[22]->getNom();
    gotoligcol(23,96);
    std::cout << "Prix : " << m_collection[22]->getPrix();

    ///

    gotoligcol(10,136);
    std::cout << "Nom : " << m_collection[6]->getNom();
    gotoligcol(11,136);
    std::cout << "Prix : " << m_collection[6]->getPrix();

    gotoligcol(13,136);
    std::cout << "Nom : " << m_collection[7]->getNom();
    gotoligcol(14,136);
    std::cout << "Prix : " << m_collection[7]->getPrix();

    gotoligcol(16,136);
    std::cout << "Nom : " << m_collection[8]->getNom();
    gotoligcol(17,136);
    std::cout << "Prix : " << m_collection[8]->getPrix();

    gotoligcol(19,136);
    std::cout << "Nom : " << m_collection[9]->getNom();
    gotoligcol(20,136);
    std::cout << "Prix : " << m_collection[9]->getPrix();

    gotoligcol(22,136);
    std::cout << "Nom : " << m_collection[10]->getNom();
    gotoligcol(23,136);
    std::cout << "Prix : " << m_collection[10]->getPrix();

    gotoligcol(25,136);
    std::cout << "Nom : " << m_collection[11]->getNom();
    gotoligcol(26,136);
    std::cout << "Prix : " << m_collection[11]->getPrix();

    gotoligcol(28,136);
    std::cout << "Nom : " << m_collection[12]->getNom();
    gotoligcol(30,136);
    std::cout << "Prix : " << m_collection[12]->getPrix();

    gotoligcol(32,136);
    std::cout << "Nom : " << m_collection[13]->getNom();
    gotoligcol(33,136);
    std::cout << "Prix : " << m_collection[13]->getPrix();

    gotoligcol(35,136);
    std::cout << "Nom : " << m_collection[14]->getNom();
    gotoligcol(36,136);
    std::cout << "Prix : " << m_collection[14]->getPrix();

    gotoligcol(38,136);
    std::cout << "Nom : " << m_collection[15]->getNom();
    gotoligcol(39,136);
    std::cout << "Prix : " << m_collection[15]->getPrix();

    gotoligcol(41,136);
    std::cout << "Nom : " << m_collection[16]->getNom();
    gotoligcol(42,136);
    std::cout << "Prix : " << m_collection[16]->getPrix();

    gotoligcol(44,136);
    std::cout << "Nom : " << m_collection[17]->getNom();
    gotoligcol(45,136);
    std::cout << "Prix : " << m_collection[17]->getPrix();


    gotoligcol(49,15);
    system("Pause");
}

void Hero::perdreVie2(int x)
{
    getActive()->perdreVie(x);
}

void Hero::perdreVie4(int x)
{
    m_pv=m_pv-x;
}

void Hero::melangedeck()
{
    std::random_shuffle(m_deck.begin(), m_deck.end());
}

void Hero::retirer_carte()
{
    if(m_deck.size())
    {
        m_main= m_deck.front();
        m_deck.pop_front();
    }
}


void Hero::carte_enjeu()
{
    int etat=0;
    if(m_deck.size())
    {
        m_enjeu= m_deck.front();
        m_deck.pop_front();
    }
    for (int i=0; i<(int)m_collection.size(); i++)
    {
        if (etat==0)
        {
            if(m_collection[i]->getId()==m_enjeu->getId())
            {
                m_collection.erase(m_collection.begin()+i);
                etat=1;
            }
        }

    }
    etat=0;
    for (int i=0; i<(int)m_deck_initial.size(); i++)
    {
        if (etat==0)
        {
            if(m_deck_initial[i]->getId()==m_enjeu->getId())
            {
                m_deck_initial.erase(m_deck_initial.begin()+i);
                etat=1;
            }
        }

    }
}


Carte* Hero::getEnjeu()
{
    return m_enjeu;
}

void Hero::affichEnjeu()
{
    std::cout << m_enjeu->getNom();
}

void Hero::affichEnjeu2()
{
    gotoligcol(2,2);
    std::cout << "Votre carte enjeu est : "<< m_enjeu->getNom();
}

void Hero::remettre_carte(Carte* c)
{
    m_deck.push_back(c);
}

void Hero::Troie()
{
    int m;
    m=(rand() % (m_deck.size()+1))+0;
    m_cimetiere.push_back(m_deck[m]);
    m_deck.erase(m_deck.begin()+m);
}

std::ostream & operator<<(std::ostream & os, const Hero & x)
{
    os << x.m_pseudo <<"|" << x.m_mdp << "|" << x.m_ecus <<"|" << x.m_victoire << "|"  << (int)x.m_collection.size() <<"|" << x.m_deck_initial.size();
    for( const auto & i : x.m_collection)
    {
        os << "|" ;
        i->archive(os);
    }

    for( const auto & i : x.m_deck_initial)
    {
        os << "|" ;
        i->archive(os);
    }

    return os;
}



std::istream & operator>>( std::istream & is,Hero & x)
{
    int nbcarte=0;
    int nbdeck=0;
    x.m_collection.clear();

    is >> x.m_pseudo  >> x.m_mdp >> x.m_ecus  >> x.m_victoire  >> nbcarte >> nbdeck ;
    for (int i =0 ; i < nbcarte; i++)
    {
        std::string cls;
        is >> cls ;
        if(cls == "Creature")
        {
            Creature * carte = new Creature();
            is >> *carte ;
            x.m_collection.push_back(carte);
        }
        else if(cls == "Energie")
        {
            Energie * carte = new Energie();
            is >> *carte ;
            x.m_collection.push_back(carte);

        }
        else if(cls == "Special")
        {
            Special * carte = new Special();
            is >> *carte ;
            x.m_collection.push_back(carte);


        }
    }
    for (int i =0 ; i < nbdeck; i++)
    {
        std::string cls;
        is >> cls ;
        if(cls == "Creature")
        {
            Creature * carte = new Creature();
            is >> *carte ;

            x.m_deck.push_back(carte);

            x.m_deck_initial.push_back(new Creature(carte->getNom(),carte->getType(),carte->getId(),carte->getPrix(),carte->getPv(),carte->getAttaque1(),carte->getAttaque2(),carte->getAttaque3()));
        }
        else if(cls == "Energie")
        {
            Energie * carte = new Energie();
            is >> *carte ;
            x.m_deck.push_back(carte);

            x.m_deck_initial.push_back(new Energie(carte->getNom(),carte->getType(),carte->getId(),carte->getPrix()));

        }
        else if(cls == "Special")
        {
            Special * carte = new Special();
            is >> *carte ;
            x.m_deck.push_back(carte);

            x.m_deck_initial.push_back(new Special(carte->getNom(),carte->getType(),carte->getId(),carte->getPrix(),carte->getEffet()));
        }
    }
    return is;
}

