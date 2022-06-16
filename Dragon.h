#ifndef MTM_HW4_DRAGON_H
#define MTM_HW4_DRAGON_H

#include "Card.h"

class Dragon : public Card {
public:
    Dragon();

    Dragon(const Dragon &dragon) = default;

    ~Dragon() override = default;

    Dragon &operator=(const Dragon &dragon) = default;

    void printInfo() const override;

    Dragon *clone() const override;

    void applyEncounter(Player &player) const override;


///private: add?
private:
    int m_force;
    int m_loot;
    int m_damage;

#endif //MTM_HW4_DRAGON_H
