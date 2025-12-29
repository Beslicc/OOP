#include "Animal.h"

Animal::Animal(const string& name, int age, double weight)
    : name(name), age(age), weight(weight) {
    if (name.empty() || age < 0 || weight <= 0) {
        throw invalid_argument("Neispravni podaci za životinju");
    }
}