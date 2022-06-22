#include "Pitfall.h"
#include "../Players/Rogue.h"
#include "../utilities.h"

Pitfall::Pitfall() : Card("Pitfall"){}

void Pitfall::applyEncounter(Player &player) const {
    const Rogue *rouge = dynamic_cast<const Rogue *>(player.clone().get());
    if (rouge == nullptr) {
        printPitfallMessage(false);
        player.damage(-10);
    }
    printPitfallMessage(true);
}

void Pitfall::printInfo() const {
    printCardDetails(std::cout,"Pitfall");
}

std::unique_ptr<Card> Pitfall::clone() const {
    return std::unique_ptr<Pitfall>(new Pitfall());
}
