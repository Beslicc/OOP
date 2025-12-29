#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H

#include "Animal.h"
#include <iostream>

using namespace std;

class ZooKeeper {
    static int totalAnimalsServed;

public:
    static void processAnimal(Animal* animal);
    static int getTotalAnimalsServed();
};

#endif