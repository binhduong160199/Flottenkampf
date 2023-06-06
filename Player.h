//
// Created by Binh Duong Nguyen on 05.06.23.
//

#ifndef AUFGABE7_PLAYER_H
#define AUFGABE7_PLAYER_H
#include <vector>
#include "Ship.h"

class Player {
private:
    std::vector<Ship*> fleet;

public:
    Player();
    ~Player();

    void addShip(Ship* ship);
    Ship* getShip(int index) const;  // Marked as const
    int getFleetSize() const;
};


#endif //AUFGABE7_PLAYER_H
