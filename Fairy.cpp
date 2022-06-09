#include "Fairy.h"

void Fairy::applyEncounter(Player &player) const {
    const Wizard *wizard = dynamic_cast<const Wizard *>(wizard);
    if (wizard != nullptr) {
        printFairyMessage(true);
        player.heal(10);
    }
    printFairyMessage(false);
}
