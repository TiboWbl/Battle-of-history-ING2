#ifndef HERO_H
#define HERO_H
#include "Deck.h"
#include "Carte.h"
#include "Creature.h"
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

class Hero
{
public:
    Hero();
    Hero (std::string _pseudo,std::string _mdp);
    ~Hero();

    std::string getNom();
    std::string getPseudo();
    std::string getMdp();

    int getEcus();
    int getVictoire();
    int getPv();
    int getMain(int x);
    int Pioche();
    int getEnergieParticuliere(int i);
    int getEnergie(int x);
    int getEnergie2(int x);

    Carte* getEnjeu();
    Carte* getMain();
    Creature* getCreatureEnJeu();
    Creature* getActive();

    std::deque <Carte*> getCimetiere();
    std::vector <Hero> ajouterHero(std::vector<Hero> hero);std::deque <Carte*> getDeck();
    std::vector <Carte*> getCollection();

    void pioche();
    void cimetiere();
    void setEnergie(int i);
    void setEnergie2(int i);
    void affichEnergie();
    void setCollection(std::vector <int> _collection);
    void ajouterCarte(std::vector <Carte*> Bibliotheque,int x);
    void ajouterCarteDeck();
    void affichCollectionHero();
    void affichDeckHero();
    void affichHero (std::vector<Carte*> Bibliotheque);
    void acheterCarte (std::vector <Carte*> Bibliotheque);
    void Affiche_deck_Newjoueur();
    void melangedeck();
    void retirer_carte();
    void remettre_carte(Carte* c);
    void carte_enjeu();
    void poserActive();
    void affichActive();
    void perdreVie2(int x);
    void detruire();
    void perdreVie3(int x);
    void perdreVie4(int x);
    void affichEnjeu();
    void affichEnjeu2();
    void Victory();
    void Defeat();
    void init();
    void retirerCarte(std::vector <Carte*> Bibliotheque,int x);
    void ajouterCarte2(Carte* c);
    void cimetiere2(Carte* carte);
    void Troie();
    void recupCimetiere();


private:
    std::string m_pseudo;
    std::string m_mdp;

    int m_ecus;
    int m_victoire;
    int m_pv;

    std::vector <Carte*> m_collection;
    std::deque <Carte*> m_deck;
    std::vector <Carte*> m_deck_initial;
    std::deque <Carte*> m_cimetiere;
    std::stack<int> m_cimetiere2;

    Carte* m_main;
    Carte* m_enjeu;
    Creature* m_active=NULL;

    int m_energie[4];

    friend std::ostream & operator<<(std::ostream & os, const Hero & x);
    friend std::istream & operator>>( std::istream &,Hero & x);

};

#endif // HERO_H
