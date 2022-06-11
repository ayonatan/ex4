#include "Pitfall.h"

void PitFall::applyEncounter(Player &player) const {
    const Rouge *rouge = dynamic_cast<const Rouge *>(player);
    if (rouge == nullptr) {
        printPitfallMessage(false);
        player.damage(-10);
    }
    printPitfallMessage(true);
}

void printInfo() const {
    printCardDetails(std::cout,"PitFall");
}