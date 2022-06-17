#include "Barfight.h"

Barfight::Barfight() : Card("BarFight"){}

void Barfight::applyEncounter(Player &player) const 
{
    const Fighter *fighter = dynamic_cast<const Fighter *>(player);
    if (fighter == nullptr) 
    {
        printBarfightMessage(false);
        player.damage(-10);
    } 
    else
    {
        printBarfightMessage(true);
    }
}

void BarFight::printInfo() const {
    printCardDetails(std::cout,"Barfight");
}

std::unique_ptr<BarFight> Barfight::clone() const {
    return std::unique_ptr<BarFight>(new Barfight(m_name));
}
