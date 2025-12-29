#ifndef DOLPHIN_H
#define DOLPHIN_H

#include "Mammal.h"
#include "Aquatic.h"

class Dolphin : public Mammal, public Aquatic {
public:
    Dolphin(const string& name, int age, double weight);
    string getSpecies() const override;
    double getDailyFood() const override;
};

#endif