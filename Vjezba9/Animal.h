#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Animal {
protected:
    string name;
    int age;
    double weight;

    Animal(const string& name, int age, double weight);
public:
    virtual ~Animal() = default;

    virtual string getSpecies() const = 0;
    virtual double getDailyFood() const = 0;
    virtual string getName() const { return name; }

    // Sprijeèi kopiranje
    Animal(const Animal&) = delete;
    Animal& operator=(const Animal&) = delete;
};

#endif