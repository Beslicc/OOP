#include "SeaTurtle.h"
#include <stdexcept>

SeaTurtle::SeaTurtle(const string& name, int age, double weight)
    : Animal(name, age, weight), Aquatic(name, age, weight, 200.0) {
}

string SeaTurtle::getSpecies() const {
    return "SeaTurtle";
}

double SeaTurtle::getDailyFood() const {
    double food = weight * 0.03; // 3% težine
    if (food <= 0) {
        throw logic_error("Dnevna kolièina hrane je nula ili negativna");
    }
    return food;
}