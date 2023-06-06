#include "Ship.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Ship::Ship(int hull, int size, int damage, bool special, const std::string& shipName)
        : hull(hull), size(size), damage(damage), special(special), shipName(shipName) {}

int Ship::getHull() const {
    return hull;
}

int Ship::getSize() const {
    return size;
}

int Ship::getDamage() const {
    return damage;
}

bool Ship::hasSpecial() const {
    return special;
}

std::string Ship::getShipName() const {
    return shipName;
}

bool Ship::rollDice(int target) {
    int result = rand() % 10 + 1;
    return result >= target;
}

void Ship::attackShip(Ship* target) {
    if (rollDice(target->getSize())) {
        int damage = getDamage();
        if (hasSpecial() && rollDice(8)) {
            // Special rule: Kritische Treffer
            damage *= 2;
            std::cout << "Kritischer Treffer! ";
        }
        target->hull -= damage;
        std::cout << getShipName() << " greift " << target->getShipName() << " an. Schaden: " << damage << std::endl;
    } else {
        std::cout << getShipName() << " verfehlt " << target->getShipName() << std::endl;
    }
}
