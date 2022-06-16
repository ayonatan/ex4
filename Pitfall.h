#ifndef MTM_HW4_PITFALL_H
#define MTM_HW4_PITFALL_H
#include "Card.h"

class PitFall : public Card{
public:
    PitFall();
    void applyEncounter(Player& player)const override;
    void printInfo() const override;
    PitFall *clone() const override;

};
#endif //MTM_HW4_PITFALL_H
