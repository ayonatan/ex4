#ifndef MTM_HW4_GOBLIN_H
#define MTM_HW4_GOBLIN_H

#include "Card.h"

class Goblin : public Card {
public:
    Goblin();

    ~Goblin()override = default ;

    Goblin &operator=(const Goblin &goblin) = default;

    Goblin(const Goblin &goblin) = default;

    void applyEncounter(Player& player)const override;

    void printInfo() const override;
    
    std::unique_ptr<Card> clone() const override;

private:
    int m_force;
    int m_loot;
    int m_damage;

};

#endif //MTM_HW4_GOBLIN_H
