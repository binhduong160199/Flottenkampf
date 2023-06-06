//
// Created by Binh Duong Nguyen on 05.06.23.
//

#ifndef AUFGABE7_GAME_H
#define AUFGABE7_GAME_H
#include "Player.h"
#include "Ship.h"
#include "Jager.h"
#include "Zerstoerer.h"
#include "Kreuzer.h"
#include <iostream>

class Game {
private:
    Player* player1;
    Player* player2;

public:
    Game();
    ~Game();

    void assembleFleets();
    void startBattle();
    void battle(Player* player1, Player* player2);
    void printShipStats(const Ship* ship);
    void printFleetStats(const Player* player);
    void printWinner(const Player* player);

    Player* getPlayer1() const;
    Player* getPlayer2() const;
};

#endif //AUFGABE7_GAME_H
