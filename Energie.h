#ifndef ENERGIE_H
#define ENERGIE_H
#include "Carte.h"
#include <vector>

class Energie :public Carte
{
public:
    Energie(std::string _nom, int _type, int _id, int _prix);
    Energie();
    ~Energie();
    virtual void archive(std::ostream & os) const;

private:


};

#endif // ENERGIE_H
