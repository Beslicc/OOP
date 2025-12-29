#ifndef SEATURTLE_H
#define SEATURTLE_H

#include "Aquatic.h"

class SeaTurtle : public Aquatic {
public:
    SeaTurtle(const string& name, int age, double weight);
    string getSpecies() const override;
    double getDailyFood() const override;
};

#endif