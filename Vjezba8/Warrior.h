#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"
#include "Enemy.h"

class Warrior : public Player {
private:
    bool shieldActive;

public:
    Warrior(const string& name);
    ~Warrior() override;

    void displayStatus() const override;
    void specialAbility() const override;
    void attackEnemy(Enemy* target) override;
    void takeDamage(int damage) override;

private:
    void activateShield();
};

#endif