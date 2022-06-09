#ifndef MTM_HW4_VAMPIRE_H
#define MTM_HW4_VAMPIRE_H

#include "Player.h"

class Vampire : public Player {
public:
    Vampire(const char* m_name);

    Vampire(const Vampire &vampire) = default;

    ~Dragon() = default override;

    operator=(const Vampire &vampire) = default;

    void applyEncounter(Player &player) const override;

///private: add?


#endif //MTM_HW4_DRAGON_H

#endif //MTM_HW4_VAMPIRE_H
