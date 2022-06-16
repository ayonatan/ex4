#include "Pitfall.h"

PitFall::PitFall()
{
    m_cardName = "BarFight";
}

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

PitFall *clone() const {
    return new PitFall(m_name);
}
