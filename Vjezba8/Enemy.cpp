#include "Enemy.h"

Enemy::Enemy(const string& name, int health, int difficulty)
    : GameCharacter(name, health), difficulty(difficulty) {
    cout << " (tezina: " << difficulty << ")\n";
}

Enemy::~Enemy() {
}

int Enemy::getDifficulty() const {
    return difficulty;
}