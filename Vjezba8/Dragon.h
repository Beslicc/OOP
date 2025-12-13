#ifndef DRAGON_H
#define DRAGON_H

#include "Enemy.h"
#include "Player.h"

class Dragon : public Enemy {
public:
    Dragon(const string& name);
    ~Dragon() override;

    void displayStatus() const override;
    void specialAbility() const override;
    void attackPlayer(Player* target) override;

private:
    void regenerate();
};

#endif