#ifndef MTM_HW4_MERCHANT_H
#define MTM_HW4_MERCHANT_H

#include "Card.h"

const DONT_BUY = 0;
const BUY_HP = 1
const BUY_FORCE = 2;

class Merchant : public Card {
public:
    Merchant();

    ~Merchant() = default override;

    Merchant(const Merchant& merchant) = default;

    Merchant& operator=(const Merchant& merchant) = default;

    void applyEncounter(Player &player) const override;
    
    void printInfo() const override;

    Merchant *clone() const override;

};

#endif //MTM_HW4_MERCHANT_H
