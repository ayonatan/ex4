#ifndef MTM_HW4_VAMPIRE_H
#define MTM_HW4_VAMPIRE_H

#include "Player.h"

class Vampire : public Player {
public:
    Vampire();

    ~Vampire() = default override;

    Vampire(const Vampire &vampire) = default;

    Vampire& operator=(const Vampire &vampire) = default;

    void applyEncounter(Player &player) const override;

    void printInfo() const override;

    Vampire *clone() const override;
}
#endif //MTM_HW4_VAMPIRE_H
