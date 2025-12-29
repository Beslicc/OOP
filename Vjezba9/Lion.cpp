#include "Lion.h"
#include <stdexcept>

Lion::Lion(const string& name, int age, double weight)
    : Animal(name, age, weight), Mammal(name, age, weight, true) {
}

string Lion::getSpecies() const {
    return "Lion";
}

double Lion::getDailyFood() const {
    double food = weight * 0.06; // 6% težine
    if (food <= 0) {
        throw logic_error("Dnevna kolièina hrane je nula ili negativna");
    }
    return food;
}