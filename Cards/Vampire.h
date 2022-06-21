#ifndef MTM_HW4_VAMPIRE_H
#define MTM_HW4_VAMPIRE_H

#include "Card.h"

class Vampire : public Card {
public:
    Vampire();

    ~Vampire() override = default ;

    Vampire(const Vampire &vampire) = default;

    Vampire& operator=(const Vampire &vampire) = default;

    void applyEncounter(Player &player) const override;

    void printInfo() const override;

    std::unique_ptr<Card> clone() const override;

private:
    int m_force;
    int m_loot;
    int m_damage;
};
#endif //MTM_HW4_VAMPIRE_H
