#include "Treasure.h"

Treasure::Treasure() : Card("Treasure") {}

void Treasure::applyEncounter(Player &player) const 
{
    player.addCoins(10);
    printTreasureMessage();
}

void Treasure::printInfo() const {
    printCardDetails(std::cout,"Treasure");
}

std::unique_ptr<Treasure> Treasure::clone() const {
    return std::unique_ptr<Treasure>(new Treasure(m_name));
}