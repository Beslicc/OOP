#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>
#include <iostream>
using namespace std;

class GameCharacter {
protected:
    string name;
    int health;

public:
    GameCharacter(const string& name, int health);
    virtual ~GameCharacter();

    virtual void displayStatus() const = 0;
    virtual void specialAbility() const = 0;

    virtual void takeDamage(int damage);
    bool isAlive() const;

    string getName() const;
    int getHealth() const;

protected:
    void setHealth(int newHealth);
};

#endif