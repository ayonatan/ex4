#ifndef MTM_HW4_MERCHANT_H
#define MTM_HW4_MERCHANT_H

#include "Card.h"

class Merchant : public Card {
public:
    void applyEncounter(Player &player) const override;

    void printInfo() const override;

};

#endif //MTM_HW4_MERCHANT_H
