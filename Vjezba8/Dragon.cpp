#include "Dragon.h"

Dragon::Dragon(const string& name)
    : Enemy(name, 300, 8) {
    cout << " (Dragon)\n";
}

Dragon::~Dragon() {
}

void Dragon::displayStatus() const {
    cout << "[DRAGON] " << getName()
        << " | Health: " << getHealth()
        << " | Tezina: " << getDifficulty()
        << "\n";
}

void Dragon::specialAbility() const {
    cout << getName() << " regenerira! Dobiva 50 healtha (max 300)\n";
}

void Dragon::regenerate() {
    int newHealth = getHealth() + 50;
    if (newHealth > 300) newHealth = 300;
    setHealth(newHealth);
    cout << getName() << " regenerirao na " << getHealth() << " healtha\n";
}

void Dragon::attackPlayer(Player* target) {
    if (!target || !target->isAlive()) {
        cout << getName() << " ne moze napasti mrtvog igraca!\n";
        return;
    }

    if (!isAlive()) {
        cout << getName() << " je mrtav i ne moze napadati!\n";
        return;
    }

    int damage = 10 * getDifficulty();
    cout << getName() << " razbija zemlju pod " << target->getName()
        << " (" << damage << " stete)\n";
    target->takeDamage(damage);
}