#ifndef MTM_HW4_VAMPIRE_H
#define MTM_HW4_VAMPIRE_H

#include "Card.h"

class Vampire : public Card {
public:
    Vampire();

    Vampire(const Vampire &vampire) = default;

    ~Vampire() override = default;

    Vampire &operator=(const Vampire &vampire) = default;

    void applyEncounter(Player &player) const override;

    void printInfo() const override;

    Vampire *clone() const override;


///private: add?
private:
    int m_force;
    int m_loot;
    int m_damage;

};

#endif //MTM_HW4_DRAGON_H

#endif //MTM_HW4_VAMPIRE_H
