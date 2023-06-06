//
// Created by Binh Duong Nguyen on 05.06.23.
//
#include "Kreuzer.h"

Kreuzer::Kreuzer() : Ship(250, 8, 50, true, "Kreuzer") {}

void Kreuzer::performSpecialAction(Ship* target) {
    // Special rule: Bombardement
    std::thread additionalAttackThread(&Ship::attackShip, this, target);
    additionalAttackThread.detach();
}
