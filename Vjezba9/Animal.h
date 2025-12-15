#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <stdexcept>
using namespace std;

class Animal {
protected:
	string name;
	int age;
	double weight;
	Animal(string& name, int age, double weight);
public:
	virtual ~Animal() = defualt;

	virtual string getSpecies()const = 0;
	virtual double getDailyFood()const = 0;
	string getName()const = 0;

	Animal(const Animal&) = delete;
	Animal& operator = (const Animal&) = delete;
};
#endif // !ANIMAL_H
