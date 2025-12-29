#ifndef ZOOSECTION_H
#define ZOOSECTION_H

#include <vector>
#include <memory>
#include <stdexcept>

using namespace std;

template<typename T>
class ZooSection {
    vector<unique_ptr<T>> animals;

public:
    void addAnimal(unique_ptr<T> animal) {
        if (!animal) {
            throw runtime_error("Ne može se dodati nullptr u ZooSection");
        }
        animals.push_back(move(animal));
    }

    double totalFood() const {
        double total = 0.0;
        for (const auto& animal : animals) {
            total += animal->getDailyFood();
        }
        return total;
    }

    size_t size() const {
        return animals.size();
    }

    T* getAnimal(size_t index) const {
        if (index >= animals.size()) {
            return nullptr;
        }
        return animals[index].get();
    }
};

#endif