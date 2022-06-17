#include "Pitfall.h"

Pitfall::Pitfall() : Card("Pitfall"){}

void Pitfall::applyEncounter(Player &player) const {
    const Rouge *rouge = dynamic_cast<const Rouge *>(player);
    if (rouge == nullptr) {
        printPitfallMessage(false);
        player.damage(-10);
    }
    printPitfallMessage(true);
}

void Pitfall::printInfo() const {
    printCardDetails(std::cout,"Pitfall");
}

std::unique_ptr<Pitfall> Pitfall::clone() const {
    return std::unique_ptr<Pitfall>(new Pitfall(m_name));
}
