#ifndef MTM_HW4_MERCHANT_H
#define MTM_HW4_MERCHANT_H

#include "Card.h"

const int DONT_BUY = 0;
const int BUY_HP = 1;
const int BUY_FORCE = 2;

class Merchant : public Card {
public:
    Merchant();

    ~Merchant()override = default ;

    Merchant(const Merchant& merchant) = default;

    Merchant& operator=(const Merchant& merchant) = default;

    void applyEncounter(Player &player) const override;
    
    void printInfo() const override;

    std::unique_ptr<Card> clone() const override;

};

#endif //MTM_HW4_MERCHANT_H
