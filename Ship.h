//
// Created by Binh Duong Nguyen on 05.06.23.
//

#ifndef AUFGABE7_SHIP_H
#define AUFGABE7_SHIP_H
#include <iostream>
#include <string>

enum class ShipType {
    JAEGER,
    ZERSTOERER,
    KREUZER
};

class Ship {
protected:
    int hull;
    int size;
    int damage;
    bool special;
    std::string shipName;

public:
    Ship(int hull, int size, int damage, bool special, const std::string& shipName);
    virtual ~Ship() {}

    int getHull() const;
    int getSize() const;
    int getDamage() const;
    bool hasSpecial() const;
    std::string getShipName() const;

    virtual bool rollDice(int target);
    virtual void attackShip(Ship* target);
    virtual void performSpecialAction(Ship* target) = 0;
};

#endif //AUFGABE7_SHIP_H
