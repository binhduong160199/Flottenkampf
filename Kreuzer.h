//
// Created by Binh Duong Nguyen on 05.06.23.
//

#ifndef AUFGABE7_KREUZER_H
#define AUFGABE7_KREUZER_H

#include "Ship.h"
#include <thread>

class Kreuzer : public Ship {
public:
    Kreuzer();
    void performSpecialAction(Ship* target) override;
};


#endif //AUFGABE7_KREUZER_H
