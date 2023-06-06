//
// Created by Binh Duong Nguyen on 05.06.23.
//

#ifndef AUFGABE7_JAGER_H
#define AUFGABE7_JAGER_H

#include "Ship.h"

class Jager : public Ship {
public:
    Jager();
    void performSpecialAction(Ship* target) override;
};

#endif //AUFGABE7_JAGER_H
