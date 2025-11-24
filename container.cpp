#include "container.h"

// Default
Container::Container(size_t initial_capacity):podaci(nullptr), velicina(0), kapacitet(initial_capacity) {
	if (kapacitet > 0) {
		podaci = new int[kapacitet];
	}
	cout << "Konstruktor: kapacitet = " << kapacitet << endl;
}

// Copy kons. (deep copy)
Container::Container(const Container& drugi):podaci(nullptr),velicina(drugi.velicina), kapacitet(drugi.kapacitet) {
	if (kapacitet > 0) {
		podaci = new int[kapacitet];
		for (size_t i = 0; i < velicina; i++) {
			podaci[i] = drugi.podaci[i];
		}
	}
	cout << "Copy konstruktor: velicina = " << velicina << endl;
}

// Move kons.
Container::Container(Container&& drugi) :podaci(drugi.podaci), velicina(drugi.velicina), kapacitet(drugi.kapacitet) {
	drugi.podaci = nullptr;
	drugi.velicina = 0;
	drugi.kapacitet = 0;
	cout << "Move konstruktor: velicina = " << velicina << endl;
}

// Destruktor
Container::~Container() {
	delete[] podaci;
	cout << "Destruktor" << endl;
}

void Container::push_back(int vrijednost) {
	if (velicina >= kapacitet) {
		size_t novi_kapacitet = (kapacitet == 0) ? 1 : kapacitet * 2;
		int* novi_podaci = new int[novi_kapacitet];
		for (size_t i = 0; i < velicina; i++) {
			novi_podaci[i] = podaci[i];
			delete[] podaci;
			podaci = novi_podaci;
			kapacitet = novi_kapacitet;
		}
	}
	data[]
}