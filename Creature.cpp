#include "Creature.h"
#include "Carte.h"

Creature::Creature(std::string nom, int type, int id, int prix,int pv, int attaque1, int attaque2, int attaque3)
    : Carte (nom,type,id,prix), m_pv(pv), m_attaque1(attaque1), m_attaque2(attaque2), m_attaque3(attaque3)
{
    //Constructeur
}

Creature::Creature()
{
    //Destructeur
}
Creature::~Creature()
{
    //Destructeur
}

int Creature::getPv()
{
    return m_pv;
}

int Creature::getAttaque1()
{
    return m_attaque1;
}

int Creature::getAttaque2()
{
    return m_attaque2;
}

int Creature::getAttaque3()
{
    return m_attaque3;
}

void Creature::perdreVie (int x)
{
    m_pv = m_pv-x;
}

void Creature::archive(std::ostream & os) const
{
    os << "Creature" << "|" << *this ;//<<std::endl;
}


std::ostream & operator<<(std::ostream & os, const Creature & x)
{
    os << (Carte)x <<"|" <<  x.m_pv <<"|"<< x.m_attaque1 <<"|"<<x.m_attaque2 <<"|"<<x.m_attaque3 ;
    return os;
}

std::istream & operator>>( std::istream & is,Creature & x)
{
    //char c;
    is >> (Carte&)x >> x.m_pv >> x.m_attaque1 >> x.m_attaque2 >> x.m_attaque3 ;
    return is;
}
