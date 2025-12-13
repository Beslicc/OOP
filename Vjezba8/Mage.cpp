#include "Mage.h"

Mage::Mage(const string& name)
    : Player(name, 80, 0), mana(100) {
    cout << " (Mage, mana: " << mana << ")\n";
}

Mage::~Mage() {
}

void Mage::displayStatus() const {
    cout << "[MAGE] " << getName()
        << " | Health: " << getHealth()
        << " | Mana: " << mana
        << " | Score: " << getScore()
        << "\n";
}

void Mage::specialAbility() const {
    if (canTeleport()) {
        cout << getName() << " teleportira se! (health > 50)\n";
    }
    else {
        cout << getName() << " ne moze teleportirati se. Health premalo ("
            << getHealth() << " <= 50)\n";
    }
}

bool Mage::canTeleport() const {
    return getHealth() > 50;
}

void Mage::attackEnemy(Enemy* target) {
    if (!target || !target->isAlive()) {
        cout << getName() << " ne moze napasti mrtvog neprijatelja!\n";
        return;
    }

    if (!isAlive()) {
        cout << getName() << " je mrtav i ne moze napadati!\n";
        return;
    }

    if (mana >= 20) {
        cout << getName() << " baca vatrenu kuglu na "
            << target->getName() << " (40 stete)\n";
        target->takeDamage(40);
        mana -= 20;
    }
    else {
        cout << getName() << " udara stapom " << target->getName()
            << " (20 stete)\n";
        target->takeDamage(20);
    }

    if (!target->isAlive()) {
        addScore(10);
    }
}

int Mage::getMana() const {
    return mana;
}