//
// Created by Binh Duong Nguyen on 05.06.23.
//

#ifndef AUFGABE7_ZERSTOERER_H
#define AUFGABE7_ZERSTOERER_H

#include "Ship.h"

class Zerstoerer : public Ship {
public:
    Zerstoerer();
    void performSpecialAction(Ship* target) override;
};

#endif //AUFGABE7_ZERSTOERER_H
