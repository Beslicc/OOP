#ifndef LION_H
#define LION_H

#include "Mammal.h"

class Lion : public Mammal {
public:
    Lion(const string& name, int age, double weight);
    string getSpecies() const override;
    double getDailyFood() const override;
};

#endif