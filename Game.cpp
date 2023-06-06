#include "Game.h"
#include <iostream>
#include <chrono>
#include <thread>

Game::Game() {
    player1 = new Player();
    player2 = new Player();
}

Game::~Game() {
    delete player1;
    delete player2;
}

void Game::assembleFleets() {
    std::cout << "Player 1 Fleet Assembly" << std::endl;
    std::cout << "-----------------------" << std::endl;
    for (int i = 0; i < 9; ++i) {
        std::cout << "Ship #" << i + 1 << std::endl;
        int type;
        do {
            std::cout << "Enter ship type (1: Jager, 2: Zerstoerer, 3: Kreuzer): ";
            std::cin >> type;
        } while (type < 1 || type > 3);

        Ship* ship = nullptr;
        switch (type) {
            case 1:
                ship = new Jager();
                break;
            case 2:
                ship = new Zerstoerer();
                break;
            case 3:
                ship = new Kreuzer();
                break;
        }

        player1->addShip(ship);
        std::cout << "Ship added to Player 1's fleet." << std::endl << std::endl;
    }

    std::cout << "Player 2 Fleet Assembly" << std::endl;
    std::cout << "-----------------------" << std::endl;
    for (int i = 0; i < 9; ++i) {
        std::cout << "Ship #" << i + 1 << std::endl;
        int type;
        do {
            std::cout << "Enter ship type (1: Jager, 2: Zerstoerer, 3: Kreuzer): ";
            std::cin >> type;
        } while (type < 1 || type > 3);

        Ship* ship = nullptr;
        switch (type) {
            case 1:
                ship = new Jager();
                break;
            case 2:
                ship = new Zerstoerer();
                break;
            case 3:
                ship = new Kreuzer();
                break;
        }

        player2->addShip(ship);
        std::cout << "Ship added to Player 2's fleet." << std::endl << std::endl;
    }
}

void Game::startBattle() {
    battle(player1, player2);
}

void Game::battle(Player* player1, Player* player2) {
    int player1ShipIndex = 0;
    int player2ShipIndex = 0;
    Player* currentPlayer = player1;
    Player* opponent = player2;

    while (player1ShipIndex < player1->getFleetSize() && player2ShipIndex < player2->getFleetSize()) {
        Ship* currentShip = currentPlayer->getShip(player1ShipIndex);
        Ship* targetShip = opponent->getShip(player2ShipIndex);

        std::cout << currentPlayer << " - " << currentShip->getShipName() << " attacks " << targetShip->getShipName() << std::endl;
        currentShip->attackShip(targetShip);

        if (targetShip->getHull() <= 0) {
            std::cout << targetShip->getShipName() << " destroyed!" << std::endl;
            player2ShipIndex++;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Swap players
        std::swap(currentPlayer, opponent);
        std::swap(player1ShipIndex, player2ShipIndex);
    }

    std::cout << std::endl;
    std::cout << "Battle ended!" << std::endl;
    std::cout << "-----------------------" << std::endl;

    if (player1ShipIndex >= player1->getFleetSize()) {
        printWinner(player2);
    } else {
        printWinner(player1);
    }
}

void Game::printShipStats(const Ship* ship) {
    std::cout << "Ship: " << ship->getShipName() << std::endl;
    std::cout << "Hull: " << ship->getHull() << std::endl;
    std::cout << "Size: " << ship->getSize() << std::endl;
    std::cout << "Damage: " << ship->getDamage() << std::endl;
    std::cout << "Special: " << (ship->hasSpecial() ? "Yes" : "No") << std::endl;
}

void Game::printFleetStats(const Player* player) {
    std::cout << "Player Fleet Stats" << std::endl;
    std::cout << "-----------------" << std::endl;
    for (int i = 0; i < player->getFleetSize(); ++i) {
        const Ship* ship = player->getShip(i);
        std::cout << "Ship #" << i + 1 << std::endl;
        printShipStats(ship);
        std::cout << std::endl;
    }
}

void Game::printWinner(const Player* player) {
    std::cout << "Player " << (player == player1 ? "1" : "2") << " wins!" << std::endl;
}

Player* Game::getPlayer1() const {
    return player1;
}

Player* Game::getPlayer2() const {
    return player2;
}
