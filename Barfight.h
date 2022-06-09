#ifndef MTM_HW4_BARFIGHT_H
#define MTM_HW4_BARFIGHT_H
#include "Card.h"

class Barfight : public Card{
public:
    void applyEncounter(Player& player)const override;
};
#endif //MTM_HW4_BARFIGHT_H

