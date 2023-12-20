#ifndef SPECIAL_H
#define SPECIAL_H
#include "Carte.h"

class Special :public Carte
{
public:
    Special(const std::string &nom,int type,int id, int prix,const std::string &effet);
    Special();
    ~Special();
    std :: string getEffet();
    virtual void archive(std::ostream & os) const;

private:
    std::string m_effet;

    friend std::ostream & operator<<(std::ostream & os, const Special & x);
    friend std::istream & operator>>( std::istream &,Special & x);

};

#endif // SPECIAL_H
