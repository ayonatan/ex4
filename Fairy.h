
#ifndef MTM_HW4_FAIRY_H
#define MTM_HW4_FAIRY_H

#include "Card.h"

class Fairy : public Card {
public:
    void applyEncounter(Player &player) const override;
};

#endif //MTM_HW4_FAIRY_H