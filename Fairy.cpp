#include "Fairy.h"

Fairy::Fairy() : Card("Fairy") {}

void Fairy::applyEncounter(Player &player) const {
    const Wizard *wizard = dynamic_cast<const Wizard *>(wizard);
    if (wizard != nullptr) {
        printFairyMessage(true);
        player.heal(10);
    }
    printFairyMessage(false);
}

void printInfo() const {
    printCardDetails(std::cout, "Fairy");
}

std::unique_ptr<Fairy> Fairy::clone() const {
    return std::unique_ptr<Fairy>(new Fairy(m_name));
}

