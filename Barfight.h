#ifndef MTM_HW4_BARFIGHT_H
#define MTM_HW4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card {
public:
    Barfight();

    ~Barfight() = default override;

    Barfight &operator=(const Barfight &barFight) = default; 

    Barfight(const BarFight& barFight) = default;

    void printInfo() const override;
    
    std::unique_ptr<BarFight> clone() const override;

    void applyEncounter(Player &player) const override;
};

#endif //MTM_HW4_BARFIGHT_H
