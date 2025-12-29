#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"

class Mammal : virtual public Animal {
protected:
    bool hasFur;

public:
    Mammal(const string& name, int age, double weight, bool hasFur);
    virtual ~Mammal() = default;
};

#endif