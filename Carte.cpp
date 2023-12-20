#include <iostream>
#include <string>
#include "Carte.h"


Carte::Carte (std :: string _nom,int _type, int _id, int _prix)
    : m_nom(_nom),m_id(_id),m_type(_type),m_prix(_prix)
{
    //Constructeur

}

Carte::~Carte()
{
    //Destructeur
}

std::string Carte ::  getNom() const
{
    return m_nom;
}

int Carte::getId()
{
    return m_id;
}

int Carte::getType()
{
    return m_type;
}

int Carte::getPrix()
{
    return m_prix;
}


void Carte::archive(std::ostream & os) const
{
    os << *this;
}

std::ostream & operator<<(std::ostream & os, const Carte & x)
{
    os <<  x.m_nom <<"|" << x.m_id << "|" << x.m_type <<"|" << x.m_prix ;
    return os;
}
std::istream & operator>>( std::istream & is,Carte & x)
{
    is  >>  x.m_nom >> x.m_id >> x.m_type >> x.m_prix ;
    return is;
}
