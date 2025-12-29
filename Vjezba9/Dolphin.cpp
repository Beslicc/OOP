#include "Dolphin.h"
#include <stdexcept>

Dolphin::Dolphin(const string& name, int age, double weight)
    : Animal(name, age, weight),
    Mammal(name, age, weight, true),
    Aquatic(name, age, weight, 300.0) {
}

string Dolphin::getSpecies() const {
    return "Dolphin";
}

double Dolphin::getDailyFood() const {
    double food = weight * 0.05; // 5% težine
    if (food <= 0) {
        throw logic_error("Dnevna kolièina hrane je nula ili negativna");
    }
    return food;
}