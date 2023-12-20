#include "Special.h"


Special::Special(const std::string & nom,int type,int id, int prix,const std::string & effet)
    : Carte (nom,type,id,prix), m_effet(effet)
{
    //Constructeur
}

Special::Special()
{

    //Destructeur
}

Special::~Special()
{
    //Destructeur
}

void Special::archive(std::ostream & os) const
{
    os << "Special" << "|" << *this ;//<< std::endl;
}

std :: string  Special :: getEffet()
{
    return m_effet;
}

std::ostream & operator<<(std::ostream & os, const Special & x)
{
    os << (Carte)x <<"|" <<  x.m_effet ;
    return os;
}

std::istream & operator>>( std::istream & is,Special & x)
{
    is >> (Carte&)x >>  x.m_effet;
    return is;
}
