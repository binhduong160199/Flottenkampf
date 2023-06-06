#include "Game.h"
#include <iostream>

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Game game;
    game.assembleFleets();
    game.printFleetStats(game.getPlayer1());
    game.printFleetStats(game.getPlayer2());
    std::cout << std::endl;

    game.startBattle();

    return 0;
}
