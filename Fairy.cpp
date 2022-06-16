#include "Fairy.h"

Fairy::Fairy() : Card() {
    m_cardName = "Fairy";
}

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

Fairy *clone() const {
    return new Fairy(m_name);
}

