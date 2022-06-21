#ifndef MTM_HW4_BARFIGHT_H
#define MTM_HW4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card {
public:
    Barfight();

    ~Barfight()override = default ;

    Barfight &operator=(const Barfight &barFight) = default; 

    Barfight(const Barfight& barFight) = default;

    void printInfo() const override;
    
    std::unique_ptr<Card> clone() const override;

    void applyEncounter(Player &player) const override;
};

#endif //MTM_HW4_BARFIGHT_H
