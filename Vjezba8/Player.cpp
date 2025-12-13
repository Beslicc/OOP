#include "Player.h"

Player::Player(const string& name, int health, int score)
    : GameCharacter(name, health), score(score) {
}

Player::~Player() {
}

void Player::addScore(int points) {
    score += points;
    cout << name << " dobiva " << points << " bodova. Ukupno: " << score << "\n";
}

int Player::getScore() const {
    return score;
}