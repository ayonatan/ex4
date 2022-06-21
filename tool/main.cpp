#include <iostream>
#include "utilities.h"
#include "Mtmchkin.h"

int main() {
    printStartGameMessage();
    const int MAX_NUMBER_OF_ROUNDS = 100;
    try
    {
        Mtmchkin game("deck.txt");
    }
    catch (DeckFileFormatError& e)
    {
        std::cerr << e.what() << std::endl();
    }
    catch (DeckFileInvalidSize& e)
    {
        std::cerr << e.what() << std::endl();
    }
    catch (DeckFileNotFound& e)
    {
        std::cerr << e.what() << std::endl();
    }
    while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS){
        game.playRound();
    }
    game.printLeaderBoard();

    return 0;
}