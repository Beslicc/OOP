#ifndef MAGE_H
#define MAGE_H

#include "Player.h"
#include "Enemy.h"

class Mage : public Player {
private:
    int mana;

public:
    Mage(const string& name);
    ~Mage() override;

    void displayStatus() const override;
    void specialAbility() const override;
    void attackEnemy(Enemy* target) override;

    int getMana() const;

private:
    bool canTeleport() const;
};

#endif