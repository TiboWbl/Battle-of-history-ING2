#include "Energie.h"


Energie::Energie (std::string _nom, int _type, int _id, int _prix)
    : Carte (_nom,_type,_id,_prix)
{
    //Constructeur
}

Energie::Energie()
{
    //Destructeur
}
Energie::~Energie()
{
    //Destructeur
}

void Energie::archive(std::ostream & os) const
{
    os << "Energie" <<"|"<< *this;//<<std::endl;
}
