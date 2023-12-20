#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>
#include <iostream>
#include "Carte.h"
#include "Hero.h"


Hero NewJoueur(std::vector<Carte*> Bibliotheque);

int Ecran_Acceuil ();
int Switch (int action);
int Reglement ();
int chercheHero(std::vector<Hero> hero,std::string _pseudo,std::string _mdp);

std::vector<Hero> Taverne (std::vector<Hero> hero,std::vector<Carte*> Collection);
std::vector <Hero> Caserne(std::vector<Hero> hero,std::vector<Carte*> Collection);
std::vector <Hero> Jouer(std::vector<Hero> hero);

void TUTO();
void Color(int couleurDuTexte,int couleurDeFond);
void gotoligcol( int lig, int col );

#endif // AFFICHAGE_H_INCLUDED

