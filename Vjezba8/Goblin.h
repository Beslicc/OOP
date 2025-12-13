#ifndef GOBLIN_H
#define GOBLIN_H

#include "Enemy.h"
#include "Player.h"

class Goblin : public Enemy {
public:
    Goblin(const string& name);
    ~Goblin() override;

    void displayStatus() const override;
    void specialAbility() const override;
    void attackPlayer(Player* target) override;

private:
    bool canWhistle() const;
};

#endif