#include "Elephant.h"
#include <stdexcept>

Elephant::Elephant(const string& name, int age, double weight)
    : Animal(name, age, weight), Mammal(name, age, weight, false) {
}

string Elephant::getSpecies() const {
    return "Elephant";
}

double Elephant::getDailyFood() const {
    double food = weight * 0.04; // 4% težine
    if (food <= 0) {
        throw logic_error("Dnevna kolièina hrane je nula ili negativna");
    }
    return food;
}