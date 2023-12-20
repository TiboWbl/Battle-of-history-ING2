#ifndef CARTE_H
#define CARTE_H
#include <string>
#include <iostream>

class Carte
{
public:
    Carte(std :: string m_nom,int m_id, int m_type, int m_prix);
    Carte() {};
    ~Carte();
    std::string getNom() const;

    int getId();
    int getType();
    int getPrix();

    virtual  std :: string getEffet()
    {
        return " ";
    };

    virtual void archive(std::ostream & os) const;

protected:

    std::string m_nom;

    int m_id;
    int m_type;
    int m_prix;

    friend std::ostream & operator<<(std::ostream & os, const Carte & x);
    friend std::istream & operator>>( std::istream &,Carte & x);
};

#endif // CARTE_H

