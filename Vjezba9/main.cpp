#include <iostream>
#include <memory>
#include "Lion.h"
#include "Elephant.h"
#include "Dolphin.h"
#include "SeaTurtle.h"
#include "ZooSection.h"
#include "ZooKeeper.h"

using namespace std;

int main() {
    try {
        ZooSection<Animal> zoo;

        cout << "=== Stvaranje zivotinja ===" << endl;

        auto lion = make_unique<Lion>("Simba", 5, 150);
        auto elephant = make_unique<Elephant>("Dumbo", 10, 5000);
        auto dolphin = make_unique<Dolphin>("Flipper", 7, 200);
        auto turtle = make_unique<SeaTurtle>("Shelly", 25, 150);

        cout << "\n=== Dodavanje zivotinja u ZooSection ===" << endl;
        zoo.addAnimal(move(lion));
        zoo.addAnimal(move(elephant));
        zoo.addAnimal(move(dolphin));
        zoo.addAnimal(move(turtle));

        cout << "\n=== Hranjenje zivotinja ===" << endl;
        for (size_t i = 0; i < zoo.size(); ++i) {
            ZooKeeper::processAnimal(zoo.getAnimal(i));
        }

        cout << "\n=== Statistika ===" << endl;
        cout << "Ukupna dnevna hrana potrebna: " << zoo.totalFood() << "kg" << endl;
        cout << "Ukupno nahranjenih zivotinja: "
            << ZooKeeper::getTotalAnimalsServed() << endl;

    }
    catch (const invalid_argument& e) {
        cerr << "Invalid argument error: " << e.what() << endl;
        return 1;
    }
    catch (const logic_error& e) {
        cerr << "Logic error: " << e.what() << endl;
        return 1;
    }
    catch (const runtime_error& e) {
        cerr << "Runtime error: " << e.what() << endl;
        return 1;
    }
    catch (const exception& e) {
        cerr << "Standardna iznimka: " << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "Nepoznata iznimka!" << endl;
        return 1;
    }

    // Demonstracija iznimki
    cout << "\n=== Demonstracija iznimki ===" << endl;

    try {
        // Prazno ime
        auto invalid1 = make_unique<Lion>("", 5, 150);
    }
    catch (const invalid_argument& e) {
        cout << "Uhvacena iznimka 1: " << e.what() << endl;
    }

    try {
        // Negativna dob
        auto invalid2 = make_unique<Elephant>("Malo", -1, 100);
    }
    catch (const invalid_argument& e) {
        cout << "Uhvacena iznimka 2: " << e.what() << endl;
    }

    try {
        // Težina 0
        auto invalid3 = make_unique<Dolphin>("Nemo", 2, 0);
    }
    catch (const invalid_argument& e) {
        cout << "Uhvacena iznimka 3: " << e.what() << endl;
    }

    try {
        // Dodavanje nullptr
        ZooSection<Animal> testZoo;
        testZoo.addAnimal(nullptr);
    }
    catch (const runtime_error& e) {
        cout << "Uhvaæena iznimka 4: " << e.what() << endl;
    }

    return 0;
}