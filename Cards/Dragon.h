#ifndef MTM_HW4_DRAGON_H
#define MTM_HW4_DRAGON_H

#include "Card.h"

class Dragon : public Card {
public:
    Dragon();

    ~Dragon()override = default ;
    
    Dragon(const Dragon &dragon) = default;

    Dragon &operator=(const Dragon &dragon) = default;

    void printInfo() const override;

    std::unique_ptr<Card> clone() const override;

    void applyEncounter(Player &player) const override;

private:
    int m_force;
    int m_loot;
    int m_damage;
};
#endif //MTM_HW4_DRAGON_H
