#ifndef AQUATIC_H
#define AQUATIC_H

#include "Animal.h"

class Aquatic : virtual public Animal {
protected:
    double maxDiveDepth;

public:
    Aquatic(const string& name, int age, double weight, double maxDiveDepth);
    virtual ~Aquatic() = default;
};

#endif