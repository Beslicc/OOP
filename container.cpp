#include "container.h"
#include <iostream>

using namespace std;

Container::Container(size_t pocetni_kapacitet)
    : podaci(nullptr), velicina(0), kapacitet(pocetni_kapacitet) {
    if (kapacitet > 0) {
        podaci = new int[kapacitet];
    }
}

Container::Container(const Container& drugi)
    : velicina(drugi.velicina), kapacitet(drugi.kapacitet) {
    if (kapacitet > 0) {
        podaci = new int[kapacitet];
        for (size_t i = 0; i < velicina; i++) {
            podaci[i] = drugi.podaci[i];
        }
    }
    else {
        podaci = nullptr;
    }
}

Container::Container(Container&& drugi)
    : podaci(drugi.podaci), velicina(drugi.velicina), kapacitet(drugi.kapacitet) {
    drugi.podaci = nullptr;
    drugi.velicina = 0;
    drugi.kapacitet = 0;
}

Container::~Container() {
    delete[] podaci;
}

Container& Container::operator=(const Container& drugi) {
    if (this != &drugi) {
        delete[] podaci;

        velicina = drugi.velicina;
        kapacitet = drugi.kapacitet;

        if (kapacitet > 0) {
            podaci = new int[kapacitet];
            for (size_t i = 0; i < velicina; i++) {
                podaci[i] = drugi.podaci[i];
            }
        }
        else {
            podaci = nullptr;
        }
    }
    return *this;
}

Container& Container::operator=(Container&& drugi) {
    if (this != &drugi) {
        delete[] podaci;

        podaci = drugi.podaci;
        velicina = drugi.velicina;
        kapacitet = drugi.kapacitet;

        drugi.podaci = nullptr;
        drugi.velicina = 0;
        drugi.kapacitet = 0;
    }
    return *this;
}

void Container::push_back(int vrijednost) {
    if (velicina >= kapacitet) {
        size_t novi_kapacitet = (kapacitet == 0) ? 1 : kapacitet * 2;
        int* novi_podaci = new int[novi_kapacitet];

        for (size_t i = 0; i < velicina; i++) {
            novi_podaci[i] = podaci[i];
        }

        delete[] podaci;
        podaci = novi_podaci;
        kapacitet = novi_kapacitet;
    }

    podaci[velicina] = vrijednost;
    velicina++;
}

size_t Container::size() const {
    return velicina;
}

size_t Container::capacity() const {
    return kapacitet;
}

int& Container::at(size_t index) {
    if (index >= velicina) {
        cout << "Greska: Index " << index << " je izvan raspona [0, " << (velicina - 1) << "]" << endl;
        return podaci[0];
    }
    return podaci[index];
}

const int& Container::at(size_t index) const {
    if (index >= velicina) {
        cout << "Greska: Index " << index << " je izvan raspona [0, " << (velicina - 1) << "]" << endl;
        return podaci[0];
    }
    return podaci[index];
}

void Container::clear() {
    velicina = 0;
}

void Container::print() const {
    cout << "Container: ";
    for (size_t i = 0; i < velicina; i++) {
        cout << podaci[i] << " ";
    }
    cout << "(size=" << velicina << ", capacity=" << kapacitet << ")" << endl;
}