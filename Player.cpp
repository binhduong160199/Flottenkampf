#include "Player.h"

Player::Player() {}

Player::~Player() {
    for (Ship* ship : fleet) {
        delete ship;
    }
}

void Player::addShip(Ship* ship) {
    fleet.push_back(ship);
}

Ship* Player::getShip(int index) const {
    if (index >= 0 && index < fleet.size()) {
        return fleet[index];
    }
    return nullptr;
}

int Player::getFleetSize() const {
    return fleet.size();
}
