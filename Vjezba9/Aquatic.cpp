#include "Aquatic.h"

Aquatic::Aquatic(const string& name, int age, double weight, double maxDiveDepth)
    : Animal(name, age, weight), maxDiveDepth(maxDiveDepth) {
    cout << "Stvorena vodena životinja koja roni do "
        << maxDiveDepth << "m" << endl;
}