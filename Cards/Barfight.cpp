#include "Barfight.h"
#include "../Players/Fighter.h"
#include "../utilities.h"

Barfight::Barfight() : Card("Barfight"){}

void Barfight::applyEncounter(Player &player) const 
{
    const Fighter *fighter = dynamic_cast<const Fighter *>(player.clone().get());
    if (fighter == nullptr) 
    {
        printBarfightMessage(false);
        player.damage(10);
    } 
    else
    {
        printBarfightMessage(true);
    }
}

void Barfight::printInfo() const {
    printCardDetails(std::cout,"Barfight");
}

std::unique_ptr<Card> Barfight::clone() const 
{
    return std::unique_ptr<Barfight>(new Barfight());
}
