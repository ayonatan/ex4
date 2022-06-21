#include <iostream>
#include "../Mtmchkin.h"

int main() {
    printStartGameMessage();
    const int MAX_NUMBER_OF_ROUNDS = 100;
    try {
        Mtmchkin game("deck.txt");
        while (!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS) {
            game.playRound();
        }
        game.printLeaderBoard();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}