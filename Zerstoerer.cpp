//
// Created by Binh Duong Nguyen on 05.06.23.
//
#include "Zerstoerer.h"

Zerstoerer::Zerstoerer() : Ship(150, 6, 60, true, "Zerstörer") {}

void Zerstoerer::performSpecialAction(Ship* target) {
    // Special rule: Zielsuchend
    target->attackShip(target);
}
