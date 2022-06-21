#include "Fairy.h"
#include "../Players/Wizard.h"
#include "../utilities.h"

Fairy::Fairy() : Card("Fairy") {}

void Fairy::applyEncounter(Player &player) const {
    const Wizard *wizard = dynamic_cast<const Wizard *>(player.clone().get());
    if (wizard != nullptr) {
        printFairyMessage(true);
        player.heal(10);
    }
    printFairyMessage(false);
}

void Fairy::printInfo() const {
    printCardDetails(std::cout, "Fairy");
}

std::unique_ptr<Card> Fairy::clone() const {
    return std::unique_ptr<Fairy>(new Fairy());
}

