
#ifndef MTM_HW4_FAIRY_H
#define MTM_HW4_FAIRY_H

#include "Card.h"

class Fairy : public Card {
public:
    Fairy();

    ~Fairy()override = default ;

    Fairy& operator=(const Fairy& fairy) = default;

    Fairy(const Fairy& fairy) = default;

    void applyEncounter(Player &player) const override;

    void printInfo() const override;

    std::unique_ptr<Card> clone() const override;

};

#endif //MTM_HW4_FAIRY_H
