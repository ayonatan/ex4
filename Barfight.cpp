#include "Barfight.h"

void Barfight::applyEncounter(Player &player) const {
    const Fighter *fighter = dynamic_cast<const Fighter *>(player);
    if (fighter == nullptr) {
        printBarfightMessage(false);
        player.damage(-10);
    } else {
        printBarfightMessage(true);
    }
}

void printInfo() const {
    printCardDetails(std::cout,"Barfight");
}