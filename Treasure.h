#ifndef MTM_HW4_TREASURE_H
#define MTM_HW4_TREASURE_H

#include "Card.h"

class Treasure : public Card {
public:
    void applyEncounter(Player &player) const override;
};



#endif //MTM_HW4_TREASURE_H
