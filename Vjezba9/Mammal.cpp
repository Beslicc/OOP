#include "Mammal.h"

Mammal::Mammal(const string& name, int age, double weight, bool hasFur)
    : Animal(name, age, weight), hasFur(hasFur) {
    if (hasFur) {
        cout << "Stvoren sisavac s dlakom" << endl;
    }
    else {
        cout << "Stvoren sisavac s malo dlake" << endl;
    }
}