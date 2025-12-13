#include "Goblin.h"

Goblin::Goblin(const string& name)
    : Enemy(name, 90, 3) {
    cout << " (Goblin)\n";
}

Goblin::~Goblin() {
}

void Goblin::displayStatus() const {
    cout << "[GOBLIN] " << getName()
        << " | Health: " << getHealth()
        << " | Tezina: " << getDifficulty()
        << "\n";
}

bool Goblin::canWhistle() const {
    return getHealth() > 20;
}

void Goblin::specialAbility() const {
    if (canWhistle()) {
        cout << getName() << " zviždi! Poziva druge goblinove u pomoc!\n";
    }
    else {
        cout << getName() << " ne moze zviždati. Health premalo ("
            << getHealth() << " <= 20)\n";
    }
}

void Goblin::attackPlayer(Player* target) {
    if (!target || !target->isAlive()) {
        cout << getName() << " ne moze napasti mrtvog igraca!\n";
        return;
    }

    if (!isAlive()) {
        cout << getName() << " je mrtav i ne moze napadati!\n";
        return;
    }

    int damage = 5 * getDifficulty();
    cout << getName() << " pogaða " << target->getName()
        << " strijelom (" << damage << " stete)\n";
    target->takeDamage(damage);
}