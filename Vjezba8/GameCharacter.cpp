#include "GameCharacter.h"
#include <string>
#include <iostream>
using namespace std;

GameCharacter::GameCharacter(const string& name, int health) : name(name), health(health) {
    cout << "Kreiran lik: " << name << " (health: " << health << ")\n";
}

GameCharacter::~GameCharacter() {
    cout << "Unistava se lik: " << name << "\n";
}

void GameCharacter::takeDamage(int damage) {
    if (damage > 0) {
        health -= damage;
        if (health < 0) health = 0;
        cout << name << " prima " << damage << " stete. Health: " << health << "\n";
    }
}

bool GameCharacter::isAlive() const {
    return health > 0;
}

string GameCharacter::getName() const {
    return name;
}

int GameCharacter::getHealth() const {
    return health;
}

void GameCharacter::setHealth(int newHealth) {
    health = newHealth;
    if (health < 0) health = 0;
}