#ifndef CREATURE_H
#define CREATURE_H
#include "Carte.h"

class Creature : public Carte
{
public:
    Creature(std::string _nom, int _type, int _id, int _prix,int _pv, int _attaque1, int _attaque2, int _attaque3);
    Creature();
    ~Creature();

    int getPv();
    int setPv(int _pv);
    int getAttaque1();
    int getAttaque2();
    int getAttaque3();
    int setAttaque1(int _attaque1);
    int setAttaque2(int _attaque2);

    void perdreVie (int x);

    virtual void archive(std::ostream & os) const;

private:
    int m_pv;
    int m_attaque1;
    int m_attaque2;
    int m_attaque3;

    friend std::ostream & operator<<(std::ostream & os, const Creature & x);
    friend std::istream & operator>>( std::istream & is,Creature & x);

};

#endif // CREATURE_H
