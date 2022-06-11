#include "Treasure.h"

void Treasure::applyEncounter(Player &player) const {
    //check with michal seif 3.7
    //magic  number
    player.addCoins(10);
    printTreasureMessage();
}

void printInfo() const {
    printCardDetails(std::cout,"Treasure");
}