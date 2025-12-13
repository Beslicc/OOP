#include "Warrior.h"

Warrior::Warrior(const string& name)
    : Player(name, 120, 0), shieldActive(false) {
    cout << " (Warrior)\n";
}

Warrior::~Warrior() {
}

void Warrior::displayStatus() const {
    cout << "[WARRIOR] " << getName()
        << " | Health: " << getHealth()
        << " | Score: " << getScore()
        << " | Stit: " << (shieldActive ? "AKTIVAN" : "neaktivan")
        << "\n";
}

void Warrior::specialAbility() const {
    cout << getName() << " aktivira stit! Smanjuje sljedeci napad za 50%\n";
}

void Warrior::takeDamage(int damage) {
    if (shieldActive) {
        damage = damage / 2;
        cout << getName() << " stit smanjuje stetu na " << damage << "\n";
        shieldActive = false;
    }
    GameCharacter::takeDamage(damage);
}

void Warrior::attackEnemy(Enemy* target) {
    if (!target || !target->isAlive()) {
        cout << getName() << " ne moze napasti mrtvog neprijatelja!\n";
        return;
    }

    if (!isAlive()) {
        cout << getName() << " je mrtav i ne moze napadati!\n";
        return;
    }

    cout << getName() << " napada " << target->getName() << " macem (20 stete)\n";
    target->takeDamage(20);

    if (!target->isAlive()) {
        addScore(10);
    }
}

void Warrior::activateShield() {
    shieldActive = true;
}